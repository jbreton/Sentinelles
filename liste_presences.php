<?php												

require_once('classes/mysql.inc');
require_once('classes/membre.inc');
require_once('classes/session.inc');

$session = new Session();
$membre = $session->Start();


if(!$membre || !$membre->EstCA()) {
	header('Location: /');
}

echo '<html><head><script type="text/javascript" src="/lib/js/jquery-1.5.min.js"></script><style>

table {
	border-collapse : collapse;
}

td {
	border: 1px solid black;
}

</style></head><body><table><thead><tr><th>Membre</th><th>Parcour</th><th>Pr&eacute;sent</th><th>Absent</th><th></th></tr></thead><tbody>';

$mysql = $session->MySQL();

$query = 'SELECT id_presence, IFNULL(membre.nom, presence.nom) AS nom, IFNULL(membre.prenom, presence.prenom) AS prenom, membre.id_membre, groupe_vitesse.description, est_present
FROM presence
LEFT JOIN groupe_vitesse ON groupe_vitesse.id_groupe_vitesse = presence.id_groupe_vitesse_demande
LEFT JOIN membre ON membre.id_membre = presence.id_membre
WHERE presence.id_activite = '.(int)$_GET['id'].' AND participation = "Y"
ORDER BY groupe_vitesse.description, IFNULL(presence.nom, membre.nom), IFNULL(presence.prenom, membre.prenom);';
$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {
    echo '<tr><td>'.htmlentities($row['prenom']).' '.htmlentities($row['nom']).($row['id_membre'] != '' ? ' ('.$row['id_membre'].')' : '').'</td><td>'.$row['description'].'</td>';

    echo '<td><input type="radio" id="present_'.$row['id_presence'].'" name="presence_'.$row['id_presence'].'" value="present" '.($row['est_present'] == 'Y' ? 'checked="checked"' : '').' /><script type="text/javascript">$(\'#present_'.$row['id_presence'].'\').data(\'id\', \''.$row['id_presence'].'\').click(function() { etait_present($(this).data(\'id\')); })</script></td>';
    echo '<td><input type="radio" id="absent_'.$row['id_presence'].'" name="presence_'.$row['id_presence'].'" value="absent" '.($row['est_present'] != 'Y' ? 'checked="checked"' : '').' /><script type="text/javascript">$(\'#absent_'.$row['id_presence'].'\').data(\'id\', \''.$row['id_presence'].'\').click(function() { etait_absent($(this).data(\'id\')); })</script></td>';

   
    echo '<td><input type="button" id="supprimer_presence_'.$row['id_presence'].'" value="Supprimer" />';
 
    echo '<script type="text/javascript">$(\'#supprimer_presence_'.$row['id_presence'].'\').data(\'id\', \''.$row['id_presence'].'\').click(function() { supprimer_presence($(this).data(\'id\')); })</script>';

    echo '</td></tr>';
}
$result->close();

echo '</tbody></table><script type="text/javascript">
function supprimer_presence(id_presence) {
	$.get(\'/manage_presence.php\', { action : \'supprimer\', presence : id_presence }, function() { location.reload(); });
}

function etait_present(id_presence) {
	$.get(\'/manage_presence.php\', { action : \'present\', presence : id_presence });
}

function etait_absent(id_presence) {
	$.get(\'/manage_presence.php\', { action : \'absent\', presence : id_presence });
}</script></body></html>';
?>