<?php

echo '<h2>' . htmlentities($row['nom']) . '</h2>';

echo '<p><b>objet</b> : '.  htmlentities($row['objet']).'</p>';
echo '<p><b>courriel</b> : '. stripslashes($row['message']).'</p>';
echo '<p><br /><b>Statut de l\'envoi</b><br />
<style>

tbody.liste tr {
	cursor: pointer;
}
tbody.liste tr:hover {
	background-color: rgb(255, 228, 155);
}

</style>
<table style="width: 100%;">
<thead><tr><th style="width: 50%;">Membre</th><th style="width: 50%;">Envoy&eacute;</th></tr></thead>
<tbody class="liste">';

$query = 'SELECT nom, prenom, courriel, envoye, date_envoi
		  FROM envoi_courriel
		  INNER JOIN membre ON membre.id_membre = envoi_courriel.id_membre
		  WHERE envoi_courriel.id_courriel = '.(int)$row['id_courriel'].'
		  ORDER BY nom, prenom;';
$result = $session->MySQL()->Query($query);
while($sub_row = $result->fetch_assoc()) {
	echo '<tr><td>'.htmlentities($sub_row['prenom'].' '.$sub_row['nom']).'</td><td>'.($sub_row['envoye'] == 'Y' ? 'Oui, à '.htmlentities($sub_row['date_envoi']) : 'Non').'</td></tr>';
}
$result->close();

echo '</tbody></table></p>
	
<p><input type="button" value="Annuler l\'envoi" onclick="location = \'annuler_envoi.php?id='.$row['id_courriel'].'\';" /></p>';