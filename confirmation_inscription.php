<?php												

require_once('classes/mysql.inc');
require_once('classes/membre.inc');
require_once('classes/session.inc');

$annee = date('Y');

$mysql = new MySQL();


$query = 'SELECT id_saison FROM saison WHERE active = "Y";';
$result = $mysql->Query($query);
$row = $result->fetch_assoc();
$result->close();
$id_saison = $row['id_saison'];

$secret = md5($_GET['t'].'secret des sentinelles');

$query = 'SELECT membre.id_membre FROM membre INNER JOIN inscription_nouvelle_saison ON inscription_nouvelle_saison.id_membre = membre.id_membre WHERE MD5(CONCAT(courriel, "inscription saison '.$annee.' sentinelles", "'.$secret.'")) = ?;';
$stmt = $mysql->Prepare($query);
$stmt->bind_param('s', $_GET['h']);
$stmt->execute();
$stmt->bind_result($id_membre);
if($stmt->fetch()) {
     $stmt->close();

     $query = 'SELECT id_inscription FROM inscription WHERE id_saison = '.$id_saison.' AND id_membre = '.$id_membre;
     $result = $mysql->Query($query);
     if(!$result->fetch_assoc()) {
          $query = 'INSERT INTO inscription SET id_saison = '.$id_saison.', id_membre = '.$id_membre;
          $mysql->Query($query);
     }
     $result->close();

     $membre = new Membre($mysql, $id_membre);

     $session = new Session();
     $session->Start($membre);

     header('Location: fichemembreview.php');
}
else {
     $stmt->close();
}