<?php

require_once('classes/calendrier.inc');

$cal = new Calendrier($session->MySQL(), (int)$_GET['y'], (int)$_GET['m']);
$cal->Afficher();

?>