<?php												

require_once('classes/mysql.inc');

$mysql = new MySQL();

$fp = fopen('membres.csv', 'r');

$header = fgetcsv($fp, 0, ';');

print_r($header);

echo count($header);

while($line = fgetcsv($fp, 0, ';')) {
echo count($line);
        $row = array_combine($header, $line);
	print_r($row);
        $query = 'INSERT INTO tmp_membre SET courriel = "'.$row['courriel'].'", nom = "'.$row['nom'].'", prenom = "'.$row['prenom'].'", nb_encadrements = "'.$row['encadrements'].'", cotisation = "'.$row['cotisation'].'";';
        $mysql->Query($query);
}