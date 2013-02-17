<?php

if(!$membre->EstCA()) {
	include('../includes/accueil.inc');
	return;
}

if($_POST['nom']) {
	if($_POST['id_courriel'] == $_GET['id']) {
		$query = 'UPDATE id_courriel SET nom = ?, objet = ?, message = ?, inclure_lien = ?) WHERE id_courriel = ?';
		$stmt = $session->MySQL()->Prepare($query);
		$stmt->bind_param('ssssi', $_POST['nom'], $_POST['objet'], $_POST['message'], $_POST['inclure_lien'], (int)$_GET['id']);
		$stmt->execute();
		$stmt->close();
		
		$id = (int)$_GET['id'];
	}
	else {
		$query = 'INSERT INTO id_courriel SET nom = ?, objet = ?, message = ?, inclure_lien = ?';
		$stmt = $session->MySQL()->Prepare($query);
		$stmt->bind_param('ssssi', $_POST['nom'], $_POST['objet'], $_POST['message'], $_POST['inclure_lien']);
		$stmt->execute();
		$stmt->close();
		
		$id = $session->MySQL()->LastInsertId();
	}
}

$query = 'SELECT * FROM courriel WHERE id_courriel = ' . $id;
$result = $session->MySQL()->Query($query);
$row = $result->fetch_assoc();
$result->close();

if($row && $row['envoye'] == 'Y') {
	include('courriel_view.inc');
}
else {
	include('courriel_edit.inc');
}

?>