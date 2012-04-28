<?php

require_once('../classes/mysql.inc');

$mysql = new MySQL();

$query = 'SELECT courriel.id_courriel, courriel.objet, courriel.message, courriel.id_activite, courriel.inclure_lien, envoi_courriel.id_envoi, membre.nom, membre.prenom, membre.courriel FROM envoi_courriel INNER JOIN courriel ON courriel.id_courriel = envoi_courriel.id_courriel INNER JOIN membre ON membre.id_membre = envoi_courriel.id_membre WHERE envoye = "N" LIMIT 1;';
$result = $mysql->Query($query);
if($row = $result->fetch_assoc()) {
	$message = str_replace(array('[NOM]', '[PRENOM]'), array($row['nom'], $row['prenom']), $row['message']);
	
	$date_envoi = date('Y-m-d H:i:s');
	
	if($row['id_activite'] && $row['inclure_lien'] == 'Y') {
		$md5 = md5($row['id_courriel'].$row['id_envoi'].'envoi_courriel'.$row['courriel'].'avis'.$date_envoi);
		$url = 'http://www.lessentinelles.com/avis_participation.php?i='.$md5;
		
		$lien = '<a href="'.$url.'">'.$url.'</a>';
		
		$message = str_replace('[LIEN]', $lien, $message);
	}
	
	print_r($row);
	echo "\n$message\n";
	
	$query = 'UPDATE envoi_courriel SET envoye = "Y", date_envoi = "'.$date_envoi.'" WHERE id_envoi = '.$row['id_envoi'];
	$mysql->Query($query);
	
	// imap_mail($row['courriel'], $row['objet'], $message, 'MIME-Version: 1.0'."\r\n".'Content-type: text/html; '."\r\n".'From: Les Sentinelles de la Route <lessentinelles@hotmail.com>'."\r\n".'Reply-To: lessentinelles@hotmail.com');
}
else {
	echo "Nothing to send\n";
}
$result->close();