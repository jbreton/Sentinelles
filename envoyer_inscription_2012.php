<?php

require_once('classes/mysql.inc');

$mysql = new MySQL();

$query = 'SELECT courriel FROM membre WHERE id_membre = '.(int)$_GET['id_membre'];
$result = $mysql->Query($query);
while($row = $result->fetch_assoc()) {

$hash = md5($row['courriel'].'inscription saison 2012 sentinelles'.$row['hash']);

$email = '<html><body><p class="p1"><strong>Chers membres des Sentinelles de la Route</strong></p>
<p class="p1">Au nom du conseil d&rsquo;administration, je vous invite &agrave; la soir&eacute;e d&rsquo;ouverture de la saison 2012, du club cycliste Les Sentinelles de la Route.</p>
<p class="p2"><span class="s1"><strong>Nous vous attendons </strong></span><span style="color: #ff0000;"><strong>MERCREDI le 18 AVRIL, &agrave; 19h00</strong></span><br/>
<strong>Centre communautaire Michel-Labadie</strong><br/>
<strong>3705, avenue Chauveau, salle RC08</strong><br/>
<strong>Qu&eacute;bec</strong></p>
<p class="p1">Lors de la soir&eacute;e, nous proc&egrave;derons &agrave; l&rsquo;inscription, au paiement de la cotisation, pour ceux et celles qui ne l&rsquo;auront pas fait parvenir par la poste (nous privil&eacute;gions les paiements par ch&egrave;que), &agrave; la remise des cartes de membres, la remise des plaques pour selle de v&eacute;lo, &agrave; la prise de photos, &agrave; l&rsquo;essayage et &agrave; la remise des maillots.</p>
<p class="p1">Par la m&ecirc;me occasion le calendrier des activit&eacute;s vous sera d&eacute;voil&eacute; et nous vous pr&eacute;senterons les nouvelles fonctions du site web du club</p>
<p class="p1">Cette ann&eacute;e, les formations &laquo; s&eacute;curit&eacute; et encadrement &raquo;, &laquo; secourisme &raquo; et &laquo; m&eacute;canique &raquo; seront de retour.</p>';

$email .= '<p class="p1">Pour toute autre information, veuillez nous contacter via l&rsquo;adresse courriel du club : <a href="mailto:lessentinelles@hotmail.com"><span class="s2">lessentinelles@hotmail.com</span></a>.</p>
<p class="p1">Nous comptons sur votre pr&eacute;sence.</p>
<p class="p1">Au plaisir de vous rencontrer.</p>
<p class="p1"><strong>Yvon Breton, pr&eacute;sident</strong><br />
Les Sentinelles de la Route</p></body></html>';

print_r($row);
echo $email;


imap_mail($row['courriel'], 'Inscription aux club Les Sentinelles de la Route', $email, 'MIME-Version: 1.0'."\r\n".'Content-type: text/html; '."\r\n".'From: Les Sentinelles de la Route <lessentinelles@hotmail.com>'."\r\n".'Reply-To: lessentinelles@hotmail.com');

}
$result->close();