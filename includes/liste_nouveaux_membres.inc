<?php

if(!$membre) {
	include('accueil.inc');
        return false;
}

if($_GET['delete']) {
	if(!$membre || !$membre->EstCA()) {
		include('accueil.inc');
		return false;
	}
	
	$session->MySQL()->Query('DELETE FROM prospect WHERE id_prospect='.(int)$_GET['delete']);
	header('Location: liste_nouveaux_membres.php');
	return false;
}

echo '<table><thead><tr><th>Nom</th><th>Courriel</th><th>T&eacute;l&eacute;phone</th>';

echo '</tr></thead><tbody>';

$query = 'SELECT id_prospect, nom, prenom, courriel, telephone_residence FROM prospect ORDER BY nom, prenom';

$result = $session->MySQL()->Query($query);
while($row = $result->fetch_assoc()) {
	echo '<tr style="cursor: pointer;" onclick="location=\'ficheprospectview.php?id='.$row['id_prospect'].'\'"><td>'.htmlentities($row['prenom'].' '.$row['nom']).'</td><td>'.htmlentities($row['courriel']).'</td><td>'.htmlentities($row['telephone_residence']).'</td>';

	echo '</tr>';
}
$result->close();

echo '</tbody></table>';
?>