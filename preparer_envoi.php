<?php

require_once('classes/mysql.inc');
require_once('classes/session.inc');
require_once('classes/membre.inc');

$session = new Session();
$membre = $session->Start();

if(!$membre || !$membre->EstCA()) {
	header('Location: accueil.php');
	exit;
}

$query = 'SELECT id_activite FROM activite WHERE id_activite = '.(int)$_GET['id'];
$result = $session->MySQL()->Query($query);
$row = $result->fetch_assoc();
$result->close();

if($row) {
	$query = 'INSERT INTO courriel (id_activite, objet, nom, message, inclure_lien) SELECT id_activite, nom_activite, concat(nom_activite, " - ", date_activite), autres_infos, "Y" FROM activite WHERE id_activite = '.$row['id_activite'].';';
	$session->MySQL()->Query($query);
	
	$id_courriel = $session->MySQL()->LastInsertId();
	
	header('Location: courriel.php?id='.(int)$id_courriel);
}
else {
	header('Location: accueil.php');
	exit;
}