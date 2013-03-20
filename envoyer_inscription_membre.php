<?php

require_once('classes/mysql.inc');

$annee = date('Y');

$nb = (int)$_GET['nb'];
if($nb >= 10)
	$cout = 0;
else if($nb >= 6)
	$cout = 10;
else {
	$cout = 20;
}

$mysql = new MySQL();

$query = 'SELECT courriel FROM membre WHERE id_membre = '.(int)$_GET['id_membre'];
$result = $mysql->Query($query);
if($row = $result->fetch_assoc()) {

$t = time();
$secret = md5($t.'secret des sentinelles');
$hash = md5($row['courriel'].'inscription saison '.$annee.' sentinelles'.$secret);

$query = 'INSERT IGNORE INTO inscription_nouvelle_saison SET id_membre = '.(int)$_GET['id_membre'].', hash = "'.$mysql->EscapeString($secret).'", cout = '.(int)$cout.';';
$mysql->Query($query);

$email = '<html><body>
<p class="p1">Chers membres des Sentinelles de la Route,&nbsp;</p>
<p class="p3">Voici revenu le temps de vous inscrire pour la saison 2013 des Sentinelles de la Route, qui f&ecirc;te cette ann&eacute;e son 15e anniversaire.</p>
<p class="p1"><strong>Cette ann&eacute;e, le conseil d&rsquo;administration a modifier ses tarifs d&rsquo;inscription :</strong><ul><li>Nouveaux membres : 20 $</li><li>Membres ayant r&eacute;alis&eacute; de 0 &egrave; 5 encadrements en 2012 : 20 $</li><li>Membres ayant&nbsp;r&eacute;alis&eacute;&nbsp;de 6 &egrave; 9&nbsp;encadrements&nbsp;en 2012 : 10 $</li><li>Membres ayant&nbsp;r&eacute;alis&eacute;&nbsp;10&nbsp;encadrements&nbsp;et plus en 2012 : tarif minimale de&nbsp;0,05&cent;</li></ul></p>
<p class="p3">(Les r&egrave;glements g&eacute;n&eacute;raux nous interdisent de rendre l&rsquo;inscription gratuite, cependant rien n&rsquo;interdit un tarif de 0,05&cent;.)</p>';

if($cout == 0)
	$email .= '<p class="p3"><strong>&Eacute;tant donn&eacute; que vous avez r&eacute;alis&eacute; au moins 10 encadrements en 2012, votre inscription pour l&rsquo;ann&eacute;e 2013 vous co&ucirc;tera 0,05&cent;.</strong></p>';
else if($cout == 10)
	$email .= '<p class="p3">&Eacute;tant donn&eacute; que&nbsp;vous avez r&eacute;alis&eacute; de 6 &agrave; 9 encadrements en 2012, votre inscription pour l&rsquo;ann&eacute;e 2013 vous co&ucirc;tera 10 $.</p>';
else
	$email .= '<p class="p3">&Eacute;tant donn&eacute; que&nbsp;vous avez r&eacute;alis&eacute; de 0 &agrave; 5 encadrements en 2012, votre inscription pour l&rsquo;ann&eacute;e 2013 vous co&ucirc;tera 20 $.</p>';

$email .= '
<p class="p1"><strong>Pour vous inscrire, ce sera la m&ecirc;me proc&eacute;dure que l&rsquo;an dernier :</strong></p>
<ul class="ul1">
<li class="li4"><span class="s1">Suivez le lien suivant&nbsp;:&nbsp;<a href="http://www.lessentinelles.com/confirmation_inscription.php?h='.$hash.'&t='.$t.'"><span class="s2">http://www.lessentinelles.com/confirmation_inscription.php?h='.$hash.'&t='.$t.'</span></a>;</span></li>
<li>Complétez votre fiche et imprimez le <span style="color: red;">document de renonciation</span> au bas de la page;</li>
<li><span style="font-weight: bold; color: red;">Signez et postez le document de renonciation, accompagné du paiement de votre inscription à l&apos;adresse postale du club :</span></li>
</ul>
<p class="p1"><strong>Adresse postale:</strong><br /> Les Sentinelles de la Route<br /> C.P. 9802, Succ. postale Ste-Foy<br /> Qu&eacute;bec (Qu&eacute;bec)<br /> G1V 4C3</p>
<p class="p3">L&rsquo;an dernier tous les membres en r&egrave;gle ont re&ccedil;u gratuitement une plaque&nbsp;personnalis&eacute;e&nbsp;pour selle de v&eacute;lo. Cette ann&eacute;e <strong>seulement</strong> les nouveaux membres en r&egrave;gle recevront une plaque gratuitement. Pour les nouveaux et les anciens membres, il sera possible de commander des plaques&nbsp;suppl&eacute;mentaires&nbsp;au co&ucirc;t de 2,50 $ chacune (taxes incluses), payable lors de la soir&eacute;e d&rsquo;ouverture.&nbsp;Pour que vous puissiez prendre possession de votre plaque de selle lors de la soir&eacute;e d&rsquo;ouverture, il faudra que vous nous fassiez parvenir votre inscription avant le 31 mars.</p>
<p class="p3">Je commande ______ plaquette(s) suppl&eacute;mentaire(s).</p>
<p class="p1">Roger Fortin<br /> Pr&eacute;sident,<br /> Les Sentinelles de la Route</p>
</body></html>';

print_r($row);
echo $email;


imap_mail($row['courriel'], 'Inscription aux club Les Sentinelles de la Route', $email, 'MIME-Version: 1.0'."\r\n".'Content-type: text/html; '."\r\n".'From: Les Sentinelles de la Route <info@lessentinelles.com>'."\r\n".'Reply-To: lessentinelles@hotmail.com');

}
$result->close();