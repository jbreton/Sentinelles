<?php

include('../classes/mysql.inc');

$mysql = new MySQL();

$fp = fopen('presence.csv', 'r');

while($line = fgetcsv($fp, NULL, ';')) {
	
	$query = 'SELECT id_membre FROM membre WHERE CONCAT(TRIM(nom), ", ", TRIM(prenom)) = "'.trim($line[0]).'";';
	$result = $mysql->Query($query);
	$row = $result->fetch_assoc();
	$result->close();
	
	echo 'http://www.lessentinelles.com/envoyer_inscription_membre.php?id_membre='.$row['id_membre'].'&nb='.$line[1];
	echo '<br>';
}