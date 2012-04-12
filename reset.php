<?php												

require_once('classes/mysql.inc');

$mysql = new MySQL();

$stmt = $mysql->Prepare('SELECT id_membre, nom, prenom, courriel FROM membre WHERE courriel = ?;');
$stmt->bind_param('s', $_GET['email']);
$stmt->execute();
$stmt->bind_result($id_membre, $nom, $prenom, $courriel);
if($stmt->fetch()) {
	$stmt->close();

        $ts = time();
        $uid = md5($id_membre + 'reset'+$ts);

        $query = 'INSERT INTO authentification_membre SET id_membre = '.(int)$id_membre.', authentification = "'.$uid.'", timestamp = '.(int)($ts + 60 * 60 * 2).';';
        $mysql->Query($query);

        $query = 'SELECT message FROM messages WHERE id_messages = 2;';
        $result = $mysql->Query($query);
        $row = $result->fetch_assoc();
        $result->close();

        $message = sprintf($row['message'], $prenom, $nom, $uid);

        mail($courriel,"Changement de mot de passe",$message,"From: lessentinelles@hotmail.com");

	echo 'success';
}
else {
	$stmt->close();
	exit(1);
}