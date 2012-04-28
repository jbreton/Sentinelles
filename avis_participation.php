<?php
require_once('classes/mysql.inc');
require_once('classes/session.inc');
require_once('classes/membre.inc');

$mysql = new MySQL();

md5($row['id_envoi'].'envoi_courriel'.$row['courriel'].'avis'.$date_envoi);

$query = 'SELECT id_activite, membre.id_membre 
		  FROM envoi_courriel 
		  INNER JOIN courriel ON envoi_courriel.id_courriel = courriel.id_courriel
		  INNER JOIN membre ON membre.id_membre = envoi_courriel.id_membre
		  WHERE MD5(CONCAT(courriel.id_courriel, id_envoi, "envoi_courriel", courriel, "avis", date_envoi)) = ?;';
$stmt = $mysql->Prepare($query);
$stmt->bind_param('s', $_GET['i']);

$stmt->execute();

$id_activite = 0;
$id_membre = 0;
$stmt->bind_result($id_activite, $id_membre);

if($stmt->fetch()) {
	$stmt->close();
	
	$session = new Session();
	$membre = new Membre($mysql, $id_membre);
	
	$session->Start($membre);
	$session->Write();
	
	header('Location: http://www.lessentinelles.com/fiche_encadrement.php?id='.$id_activite);
}
else {
	$stmt->close();
	
	header('Location: http://www.lessentinelles.com');
}
