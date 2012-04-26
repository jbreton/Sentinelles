<?php

if(!$membre || !$membre->EstCA()) {
	include('accueil.inc');
        return false;
}

$years = array();
	$query = 'SELECT DISTINCT YEAR(date_activite) FROM activite;';
$result = $session->MySQL()->Query($query);
while($row = $result->fetch_row()) {
	$years[] = $row[0];
}
$result->close();

$year = (int)$_GET['y'];
if(!in_array($year, $years)) {
	$year = $years[count($years)-1];
}

$query = 'SELECT id_activite, nom_activite, date_activite FROM activite WHERE YEAR(date_activite) = "'.(int)$year.'" ORDER BY date_activite;';
$result = $session->MySQL()->Query($query);
?>
<span>Voir les activit&eacute;s de </span><select id="annee_activite" onchange="location = '/liste_encadrements.php?y='+this.value;"><?php foreach($years as $o_year) { echo '<option '.($year == $o_year ? 'selected="selected"' : '').' value="'.$o_year.'">'.$o_year.'</option>'; } ?></select><br /><br />
<input type="button" value="Ajouter une activit&eacute;" onclick="location = '/fiche_encadrement_edit.php';" /><br /><br />
<style>

tbody.liste tr {
	cursor: pointer;
}
tbody.liste tr:hover {
	background-color: rgb(255, 228, 155);
}

</style>
<table style="width: 100%;">
<thead><tr><th style="width: 50%;">Activit&eacute;s</th><th style="width: 50%;">Date</th></tr></thead>
<tbody class="liste">
<?php

while($row = $result->fetch_assoc()) {
	echo '<tr onclick="location = \'/fiche_encadrement_edit.php?id='.$row['id_activite'].'\'"><td>'.htmlentities($row['nom_activite']).'</td><td>'.$row['date_activite'].'</td></tr>';
}
$result->close();

?>
</tbody>
</table>
