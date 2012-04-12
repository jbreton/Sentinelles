<html><body>
<?php			
require_once('classes/mysql.inc');
require_once('classes/calendrier.inc');

$mysql = new MySQL();

$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 1);
$cal->AfficherMois();
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 2);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 3);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 4);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 5);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 6);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 7);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 8);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 9);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 10);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 11);
$cal->Afficher();
$cal = new Calendrier($mysql, 'ENCADREMENT', 2011, 12);
$cal->Afficher();

?>
</body></html>