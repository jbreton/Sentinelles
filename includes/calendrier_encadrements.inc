<?php

require_once('classes/calendrier.inc');

$cal = new Calendrier($session->MySQL(), 'ENCADREMENT', 2012, (int)$_GET['m']);
$cal->Afficher();

?>