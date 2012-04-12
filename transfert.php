<?php												


require_once('classes/mysql.inc');

$mysql = new MySQL();

$result = $mysql->Query('SELECT * FROM tmp_membre');
while($row = $result->fetch_assoc()) {
	echo $row['prenom'].' '.$row['nom'].'<br />';

        $query = 'INSERT INTO membre SET nom = "'.$row['nom'].'", prenom = "'.$row['prenom'].'", courriel = "'.$row['courriel'].'";';
        $mysql->Query($query);

        $id = $mysql->LastInsertId();

        $query = 'INSERT INTO inscription SET id_saison = 1, id_membre = '.$id.', nb_encadrements = '.(int)$row['nb_encadrements'].', cotisation = '.(int)$row['cotisation'].', est_ca = "'.$row['est_ca'].'";';
        $mysql->Query($query);
}
$result->close();