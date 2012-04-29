<?php

if(!$membre || !$membre->EstCA()) {
	include('accueil.inc');
        return false;
}

$query = 'SELECT id_courriel, nom, envoye FROM courriel ORDER BY envoye, nom;';
$result = $session->MySQL()->Query($query);
?>
<input type="button" value="Nouveau courriel" onclick="location = '/courriel.php';" /><br /><br />
<style>

tbody.liste tr {
	cursor: pointer;
}
tbody.liste tr:hover {
	background-color: rgb(255, 228, 155);
}

</style>
<table style="width: 100%;">
<thead><tr><th style="width: 50%;">Courriel</th><th style="width: 50%;">Envoy&eacute;</th></tr></thead>
<tbody class="liste">
<?php

while($row = $result->fetch_assoc()) {
	echo '<tr onclick="location = \'/courriel.php?id='.$row['id_courriel'].'\'"><td>'.htmlentities($row['nom']).'</td><td>'.($row['envoye'] == 'Y' ? 'Oui' : 'Non').'</td></tr>';
}
$result->close();

?>
</tbody>
</table>
