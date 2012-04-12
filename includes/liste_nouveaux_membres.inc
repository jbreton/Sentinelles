<?php

if(!$membre) {
	include('accueil.inc');
        return false;
}

echo '<table><thead><tr><th>Nom</th><th>Courriel</th><th>T&eacute;l&eacute;phone</th>';

echo '</tr></thead><tbody>';

$query = 'SELECT membre.id_membre, nom, prenom, courriel, telephone_residence FROM membre LEFT JOIN inscription ON inscription.id_membre = membre.id_membre WHERE inscription.id_inscription IS NULL';

$query .= ' ORDER BY nom, prenom';

$result = $session->MySQL()->Query($query);
while($row = $result->fetch_assoc()) {
	echo '<tr style="cursor: pointer;" onclick="location=\'fichemembreview.php?idmembre='.$row['id_membre'].'\'"><td>'.htmlentities($row['prenom'].' '.$row['nom']).'</td><td>'.htmlentities($row['courriel']).'</td><td>'.htmlentities($row['telephone_residence']).'</td>';

	echo '</tr>';
}
$result->close();

echo '</tbody></table>';
?>