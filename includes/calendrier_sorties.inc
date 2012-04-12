<?php

require_once('classes/calendrier.inc');

$cal = new Calendrier($session->MySQL(), 'SORTIE', 2011, (int)$_GET['m']);
$cal->Afficher();

?>