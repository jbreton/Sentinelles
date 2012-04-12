<?php

if(!$membre || !$membre->EstCA()) {
	include('accueil.inc');
        return false;
}

$query = 'SELECT id_activite, nom_activite, date_activite FROM activite WHERE type_activite = "ENCADREMENT" order by date_activite;';
$result = $session->MySQL()->Query($query);
?>
<input type="button" value="Ajouter un encadrement" onclick="location = '/fiche_encadrement_edit.php';" /><br /><br />
<style>

tbody.liste tr {
	cursor: pointer;
}
tbody.liste tr:hover {
	background-color: rgb(255, 228, 155);
}

</style>
<table style="width: 100%;">
<thead><tr><th style="width: 50%;">Encadrement</th><th style="width: 50%;">Date</th></tr></thead>
<tbody class="liste">
<?php

while($row = $result->fetch_assoc()) {
	echo '<tr onclick="location = \'/fiche_encadrement_edit.php?id='.$row['id_activite'].'\'"><td>'.htmlentities($row['nom_activite']).'</td><td>'.$row['date_activite'].'</td></tr>';
}
$result->close();

?>
</tbody>
</table>