<?php

if(!$membre && !$membre->EstCA()) {
	include('includes/acceuil.inc');
        return;
}

$c = 0;
$i = 1;
$result = $session->MySQL()->Query('SELECT nom, prenom, courriel FROM membre INNER JOIN inscription ON inscription.id_membre = membre.id_membre INNER JOIN saison ON saison.id_saison = inscription.id_saison WHERE est_inscrit = "Y" AND saison.active = "Y" ORDER BY nom, prenom;');
while($row = $result->fetch_assoc()) {
	if($c == 0) {
	     echo '<br /><br /><h1>Groupe '.$i++.'</h1><br />';
        }
        else {
	     echo ', ';
        }

        echo htmlentities($row['prenom']).' '.htmlentities($row['nom']).' &lt;'.htmlentities($row['courriel']).'&gt;';

        $c++;

        if($c == 30) $c = 0;
}
$result->close();
?>