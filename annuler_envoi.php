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

$query = 'DELETE FROM envoi_courriel WHERE envoye = "N" and id_courriel = '.(int)$_GET['id'];
$session->MySQL()->Query($query);

header('Location: courriel.php&id='.(int)$_GET['id']);