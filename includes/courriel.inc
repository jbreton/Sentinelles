<?php

if(!$membre->EstCA()) {
	include('includes/accueil.inc');
	return;
}

if($_POST['nom']) {
	if($_POST['id_courriel'] && $_POST['id_courriel'] == $_GET['id']) {
		$query = 'UPDATE courriel SET nom = ?, objet = ?, message = ?, inclure_lien = ? WHERE id_courriel = ?';
		$stmt = $session->MySQL()->Prepare($query);
		$stmt->bind_param('ssssi', $_POST['nom'], $_POST['objet'], $_POST['message'], $_POST['inclure_lien'], $_GET['id']);
		$stmt->execute();
		$stmt->close();
		
		$id = (int)$_GET['id'];
	}
	else {
		$query = 'INSERT INTO courriel SET nom = ?, objet = ?, message = ?';
		$stmt = $session->MySQL()->Prepare($query);
		$stmt->bind_param('sss', $_POST['nom'], $_POST['objet'], $_POST['message']);
		$stmt->execute();
		$stmt->close();
		
		$id = $session->MySQL()->LastInsertId();
	}
	
	if($_POST['send'] == 'Envoyer') {
		$query = 'UPDATE courriel SET envoye = "Y" WHERE id_courriel = '.(int)$id;
		$session->MySQL()->Query($query);
		
		$query = 'INSERT INTO envoi_courriel (id_courriel, id_membre) SELECT '.(int)$id.', membre.id_membre FROM membre LEFT JOIN (inscription INNER JOIN saison ON saison.id_saison = inscription.id_saison AND saison.active = "Y") ON inscription.id_membre = membre.id_membre WHERE inscription.id_inscription IS NOT NULL AND est_inscrit = "Y"';
		$session->MySQL()->Query($query);
	}
}
else {
	$id = (int)$_GET['id'];
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