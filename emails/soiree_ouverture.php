<?php



require_once('../classes/mysql.inc');

$mysql = new MySQL();

$query = 'SELECT
membre.id_membre, nom, prenom, courriel FROM membre;';

$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {

$id_membre = $row['id_membre'];


$email = '<html><body>
<table width="64" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<td><img src="http://www.lessentinelles.com/mockup/sentinelles.gif" alt="" width="246" height="69" border="0"></td>
	</tr>
</table>
<br />
Le 27 mars 2011<br />
<br />
Chers amis des Sentinelles de la Route,<br />
<br />
Au nom du conseil d\'administration, je vous invite &agrave; la soir&eacute;e de lancement&nbsp;de la saison
2011&nbsp;du club cycliste Les Sentinelles de la Route.<br /><br />
<b>Nous vous attendons </b><b style="color: red;">MARDI le 12 AVRIL, &agrave; 19h00</b><br />
<b>Ar&eacute;na&nbsp;Michel-Labadie<br />
3705, avenue Chauveau, salle SS-104
<br />Qu&eacute;bec</b><br /><br />
Lors de la soir&eacute;e nous proc&egrave;derons &agrave; l\'inscription,&nbsp;au&nbsp;paiement
de la cotisation (nous privil&eacute;gions les paiements par ch&egrave;que), &agrave; la
prise de photos, &agrave; l\'essayage et &agrave; la remise des maillots.<br />
<br />Par la m&ecirc;me occasion le calendrier des activit&eacute;s vous sera distribu&eacute; et
nous vous pr&eacute;senterons les nouvelles fonctions du site web du club.<br />
<br />
Cette ann&eacute;e, les formations &laquo;S&eacute;curit&eacute; et encadrement &raquo;, &laquo; Secourisme &raquo; et &laquo; M&eacute;canique &raquo; seront de retour.<br />
<br />
Nous vous transmettrons prochainement l\'ordre du jour de la soir&eacute;e.<br />
<br />
Pour toute autre information, contactez nous au 418-686-3234 ou par courriel.<br />
<br />
Nous comptons sur votre pr&eacute;sence.<br />
<br />
Au plaisir de vous rencontrer.<br />
<br />
<b>Jean-Pierre Laforest, pr&eacute;sident</b><br />
Les Sentinelles de la Route</body></html>';

echo $row['courriel'].':'.'Inscription aux club Les Sentinelles de la Route'.':'.$email.'<br />';

//imap_mail($row['courriel'], 'Soirée d\'ouverture de la saison 2011 des Sentinelles de la Route', $email, 'MIME-Version: 1.0'."\r\n".'Content-type: text/html; '."\r\n".'From: Les Sentinelles de la Route <lessentinelles@hotmail.com>');

}
$result->close();