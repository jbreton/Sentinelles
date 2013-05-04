<?php												

require_once('classes/mysql.inc');
require_once('classes/membre.inc');
require_once('classes/session.inc');

$session = new Session();
$membre = $session->Start();


if(!$membre || !$membre->EstCA()) {
	header('Location: /');
}

echo '<html><head><script src="lib/js/jquery-1.9.1.js" type="text/javascript"></script>
<link type="text/css" href="lib/css/blitzer/jquery-ui-1.10.3.custom.css" rel="stylesheet" />	
<script type="text/javascript" src="lib/js/jquery-ui-1.10.3.custom.min.js"></script><style>

table {
	border-collapse : collapse;
}

td {
	border: 1px solid black;
}

</style></head><body><table><thead><tr><th>Membre</th><th>Parcour</th><th>Date de confirmation</th><th>Pr&eacute;sent</th><th>Absent</th><th></th></tr></thead><tbody id="grille_presence">';

$mysql = $session->MySQL();

$groupes = array();
$query = 'SELECT id_groupe_vitesse, description FROM groupe_vitesse WHERE id_activite = '.(int)$_GET['id'];
$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {
	$groupes[$row['id_groupe_vitesse']] = $row['description'];
}
$result->close();

$membres = array();
$query = 'SELECT membre.id_membre, nom, prenom FROM membre LEFT JOIN (inscription INNER JOIN saison ON saison.id_saison = inscription.id_saison AND saison.active = "Y") ON inscription.id_membre = membre.id_membre WHERE inscription.id_inscription IS NOT NULL AND est_inscrit = "Y" ORDER BY nom, prenom;';
$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {
	$membres[$row['id_membre']] = $row['prenom'].' '.$row['nom'];
}
$result->close();
		
$query = 'SELECT id_presence, IFNULL(membre.nom, presence.nom) AS nom, IFNULL(membre.prenom, presence.prenom) AS prenom, courriel, membre.id_membre, groupe_vitesse.id_groupe_vitesse, est_present, date_confirmation
FROM presence
LEFT JOIN groupe_vitesse ON groupe_vitesse.id_groupe_vitesse = presence.id_groupe_vitesse_demande
LEFT JOIN membre ON membre.id_membre = presence.id_membre
WHERE presence.id_activite = '.(int)$_GET['id'].' AND participation = "Y"
ORDER BY groupe_vitesse.description, IFNULL(presence.nom, membre.nom), IFNULL(presence.prenom, membre.prenom);';
$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {
	if($row['id_membre'] && isset($membres[$row['id_membre']])) {
		unset($membres[$row['id_membre']]);
	}
	
    echo '<tr><td>'.htmlentities($row['prenom']).' '.htmlentities($row['nom']).($row['id_membre'] != '' ? ' '.$row['courriel'].' ('.$row['id_membre'].')' : '').'</td>';
	
	echo '<td><select id="groupe_'.$row['id_presence'].'"><option value="0">Sans préférence</option>';
	foreach($groupes as $groupe_id => $groupe_description) {
		echo '<option value="'.$groupe_id.'" '.($groupe_id == $row['id_groupe_vitesse'] ? 'selected="selected"' : '').'>'.htmlentities($groupe_description).'</option>';
	}
	echo '</select><script type="text/javascript">$(\'#groupe_'.$row['id_presence'].'\').data(\'id\', \''.$row['id_presence'].'\').change(function() { change_groupe($(this).data(\'id\'), $(this).val()); });</script></td>';
	
	echo '<td>'.$row['date_confirmation'].'</td>';

    echo '<td><input type="radio" id="present_'.$row['id_presence'].'" name="presence_'.$row['id_presence'].'" value="present" '.($row['est_present'] == 'Y' ? 'checked="checked"' : '').' /><script type="text/javascript">$(\'#present_'.$row['id_presence'].'\').data(\'id\', \''.$row['id_presence'].'\').click(function() { etait_present($(this).data(\'id\')); })</script></td>';
    echo '<td><input type="radio" id="absent_'.$row['id_presence'].'" name="presence_'.$row['id_presence'].'" value="absent" '.($row['est_present'] != 'Y' ? 'checked="checked"' : '').' /><script type="text/javascript">$(\'#absent_'.$row['id_presence'].'\').data(\'id\', \''.$row['id_presence'].'\').click(function() { etait_absent($(this).data(\'id\')); })</script></td>';

   
    echo '<td><input type="button" id="supprimer_presence_'.$row['id_presence'].'" value="Supprimer" />';
 
    echo '<script type="text/javascript">$(\'#supprimer_presence_'.$row['id_presence'].'\').data(\'id\', \''.$row['id_presence'].'\').click(function() { supprimer_presence($(this).data(\'id\')); })</script>';

    echo '</td></tr>';
}
$result->close();

echo '</tbody></table><br><br><input type="button" value="Ajouter un membre" onclick="ouvrir_ajout();" />';

$select_membres = '<select id="membre">';
foreach($membres as $id_membre => $membre) {
	$select_membres .= '<option value="'.(int)$id_membre.'">'.htmlentities($membre).'</option>';
}
$select_membres .= '</select>';

echo '<div id="dialog-ajout" title="Ajouter une présence">
		<label for="membre">Membre</label><br>'.$select_membres.'<br><br>
		<label for="groupe">Groupe de vitesse</label><br>';
		echo '<td><select id="groupe">';
		foreach($groupes as $groupe_id => $groupe_description) {
			echo '<option value="'.$groupe_id.'">'.htmlentities($groupe_description).'</option>';
		}
		echo '</select>
</div>';

echo '<script type="text/javascript">
$(document).ready(function() {
	$( "#dialog-ajout" ).dialog({
	  autoOpen: false,
	  height: 270,
	  width: 450,
	  modal: true,
	  buttons: {
		"Ajouter": function() {
			ajouter_presence($(\'#membre\').val(), $(\'#groupe\').val()); 
		},
		Annuler: function() {
		  $( this ).dialog( "close" );
		}
	  },
	  close: function() {

	  }
	});
});

function ouvrir_ajout() {
	$(\'#dialog-ajout\').dialog("open");
}

function supprimer_presence(id_presence) {
	$.get(\'/manage_presence.php\', { action : \'supprimer\', presence : id_presence }, function() { location.reload(); });
}

function etait_present(id_presence) {
	$.get(\'/manage_presence.php\', { action : \'present\', presence : id_presence });
}

function etait_absent(id_presence) {
	$.get(\'/manage_presence.php\', { action : \'absent\', presence : id_presence });
}

function change_groupe(id_presence, id_groupe) {
	$.get(\'/manage_presence.php\', { action : \'change_groupe\', presence : id_presence, groupe : id_groupe });
}

function ajouter_presence(id_membre, id_groupe) {
	$.get(\'/manage_presence.php\', { action : \'ajout\', membre : id_membre, groupe : id_groupe, activite : \''.(int)$_GET['id'].'\' }, function(data) { 
		location.reload();
	});
}

</script>
</body></html>';
?>