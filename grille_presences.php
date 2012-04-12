<?php												

require_once('classes/mysql.inc');
require_once('classes/membre.inc');
require_once('classes/session.inc');

$session = new Session();
$membre = $session->Start();

if(!$membre || !$membre->EstCA()) {
	header('Location: /');
}

$mysql = $session->MySQL();

echo '<style>

table {
	border-collapse : collapse;
}

td {
	border: 1px solid black;
}

</style>';

$groupe = false;
$first = true;

$query = 'SELECT IFNULL(membre.nom, presence.nom) AS nom, IFNULL(membre.prenom, presence.prenom) AS prenom, membre.id_membre, groupe_vitesse.description
FROM presence
LEFT JOIN groupe_vitesse ON groupe_vitesse.id_groupe_vitesse = presence.id_groupe_vitesse_demande
LEFT JOIN membre ON membre.id_membre = presence.id_membre
WHERE presence.id_activite = '.(int)$_GET['id'].' AND participation = "Y"
ORDER BY groupe_vitesse.description, IFNULL(presence.nom, membre.nom), IFNULL(presence.prenom, membre.prenom);';
$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {
    if($groupe !== $row['description']) {
       $groupe = $row['description'];

       if(!$first) 
          echo '</tbody></table><br />';
       else
          $first = false;

       if($row['description'] == '')
          echo '<h2>Sans pr&eacute;f&eacute;rence</h2>';
       else 
          echo '<h2>'.htmlentities($row['description']).'</h2>'; 

       echo '<table><thead><tr><th>Membre</th><th style="width: 500px;">Signature</th><th>Pr&eacutesent</th></tr></thead><tbody>';
    }

    echo '<tr><td>'.htmlentities($row['prenom']).' '.htmlentities($row['nom']).'</td><td></td><td></td></tr>';
}
$result->close();

echo '</tbody></table></body></html>';
?>