<?php												

require_once('classes/mysql.inc');

$mysql = new MySQL();

$query = 'SELECT
 membre.id_membre, nom, prenom, courriel FROM membre WHERE id_membre = '.(int)$_GET['id_membre'];

$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {

$id_membre = $row['id_membre'];

$query = 'INSERT INTO inscription SET id_membre = '.(int)$_GET['id_membre'].', id_saison = 2, cotisation = 20;';
$mysql->Query($query);

$ts = time();
        $uid = md5($id_membre + 'reset'+$ts);

        $query = 'INSERT INTO authentification_membre SET id_membre = '.(int)$id_membre.', authentification = "'.$uid.'", timestamp = '.(int)($ts + 60 * 60 * 24 * 30).';';
        $mysql->Query($query);


$template = '<html><body>
<table width="64" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<td><img src="http://www.lessentinelles.com/mockup/sentinelles.gif" alt="" width="246" height="69" border="0"></td>
	</tr>
</table>
<h1><br>
	<font size="3" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif"><strong>Inscription pour la saison 2012 des Sentinelles de la Route</strong></font></h1>
<p></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif">Bonjour [PRENOM] [NOM]</font></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif">Nous avons reçu votre demande  d&rsquo;inscription pour la nouvelle saison des Sentinelles de la Route.</font></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif">Le montant exigible pour le paiement  de votre inscription est de 20 $</font></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif"><strong>Vous devez vous rendre sur le lien suivant pour compl&eacute;ter le formulaire d&rsquo;inscription : <br /><a href="[INSCRIPTION]" style="color: red;">[INSCRIPTION]</a></strong></font></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif">Nous sommes heureux de vous compter au nombre des membres du club Les Sentinelles de la Route.<br />
Votre pr&eacute;sence et votre 
implication aux encadrements sont importants pour les organisateurs de 
randonn&eacute;es et pour le d&eacute;veloppement du club.</font></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif"><strong>Merci de faire parvenir le formulaire d\'inscription d&ucirc;ment sign&eacute;, avec le paiement par ch&egrave;que de votre cotisation, avant le 1er avril 2012, &agrave; l\'adresse suivante :</strong><br>
		Les Sentinelles de la Route<br>
		C.P. 9802, Succ. postale Sainte-Foy<br>
		Qu&eacute;bec (Qu&eacute;bec)<br>
		G1V 4C3</font></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif">L&rsquo;invitation officielle de la soir&eacute;e d&rsquo;ouverture de la saison 2011 sera transmise prochainement.</font></p>
<p><font size="2" face="Helvetica, Geneva, Arial, SunSans-Regular, sans-serif"><em>Le conseil d&rsquo;administration des Sentinelles de la Route</em></font></p>
</body></html>';

$email = str_replace(array('[NOM]', '[PRENOM]', '[INSCRIPTION]'), array($row['nom'], $row['prenom'], 'http://www.lessentinelles.com/?authentification='.$uid), $template);

//echo $row['courriel'].':'.'Inscription aux club Les Sentinelles de la Route'.':'.$email;

imap_mail($row['courriel'], 'Inscription aux club Les Sentinelles de la Route', $email, 'MIME-Version: 1.0'."\r\n".'Content-type: text/html; '."\r\n".'From: Les Sentinelles de la Route <lessentinelles@hotmail.com>');

}
$result->close();

echo 'sent';