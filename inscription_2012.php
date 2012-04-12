<?php												

require_once('classes/mysql.inc');
require_once('classes/membre.inc');
require_once('classes/session.inc');

$mysql = new MySQL();

$query = 'SELECT membre.id_membre FROM membre INNER JOIN inscription_2012 ON inscription_2012.id_membre = membre.id_membre WHERE MD5(CONCAT(courriel, "inscription saison 2012 sentinelles", hash)) = ?;';
$stmt = $mysql->Prepare($query);
$stmt->bind_param('s', $_GET['h']);
$stmt->execute();
$stmt->bind_result($id_membre);
if($stmt->fetch()) {
     $stmt->close();

     $query = 'SELECT id_inscription FROM inscription WHERE id_saison = 2 AND id_membre = '.$id_membre;
     $result = $mysql->Query($query);
     if(!$result->fetch_assoc()) {
          $query = 'INSERT INTO inscription SET id_saison = 2, id_membre = '.$id_membre;
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