<?php

if(!$membre) {
	include('accueil.inc');
        return false;
}

if($membre->EstCA()) {
	echo '<input type="button" onclick="location = \'/groupes_courriels.php\'" value="Afficher les groupes de courriels" />';
}

echo '<style> tr.liste:hover { background-color: rgb(255, 228, 155); }</style><table><thead><tr><th>Nom</th><th>Courriel</th><th>Groupe de vitesse</th></tr></thead><tbody>';

$query = 'SELECT membre.id_membre, nom, prenom, courriel, groupe_vitesse, est_inscrit FROM membre LEFT JOIN (inscription INNER JOIN saison ON saison.id_saison = inscription.id_saison AND saison.active = "Y") ON inscription.id_membre = membre.id_membre WHERE inscription.id_inscription IS NOT NULL AND est_inscrit = "Y"';


$query .= ' ORDER BY nom, prenom';

$result = $session->MySQL()->Query($query);
while($row = $result->fetch_assoc()) {
	echo '<tr class="liste" style="cursor: pointer;" onclick="location=\'fichemembreview.php?idmembre='.$row['id_membre'].'\'"><td>'.htmlentities($row['prenom'].' '.$row['nom']).'</td><td>'.htmlentities($row['courriel']).'</td><td>'.htmlentities($row['groupe_vitesse']).'</td></tr>';
}
$result->close();

echo '</tbody></table>';
?>