<?php

require_once('classes/mysql.inc');
require_once('classes/session.inc');
require_once('classes/membre.inc');

$session = new Session();
$membre = $session->Start();

if(!$membre || !$membre->EstCA()) {
	include('accueil.inc');
	return false;
}

$query = 'INSERT INTO membre (nom,prenom,adresse,ville,code_postal,telephone_residence,telephone_bureau,telephone_autre,courriel,date_naissance,groupe_vitesse,urgence_nom,urgence_lien,urgence_tel_res,urgence_tel_bur,urgence_tel_autre,maillot_grandeur,referer_par,no_assurance_maladie,est_inscrit)
			SELECT nom,prenom,adresse,ville,code_postal,telephone_residence,telephone_bureau,telephone_autre,courriel,date_naissance,groupe_vitesse,urgence_nom,urgence_lien,urgence_tel_res,urgence_tel_bur,urgence_tel_autre,maillot_grandeur,recrute_par,no_assurance_maladie,"Y" FROM prospect WHERE id_prospect = '.$_GET['id'];
$session->MySQL()->Query($query);
$id_membre = $session->MySQL()->LastInsertId();

$query = 'INSERT INTO inscription (id_membre, id_saison) SELECT '.$id_membre.', id_saison FROM saison WHERE active = "Y";';
$session->MySQL()->Query($query);

$query = 'DELETE FROM prospect WHERE id_prospect = '.(int)$_GET['id'];
$session->MySQL()->Query($query);

if($_GET['invite']) {
	$annee = date('Y');
	
	$query = 'SELECT courriel FROM membre WHERE id_membre = '.(int)$id_membre;
	$result = $session->MySQL()->Query($query);
	$row = $result->fetch_assoc();
	$result->close();
	
	$t = time();
	$secret = md5($t.'secret des sentinelles');
	$hash = md5($row['courriel'].'inscription saison '.$annee.' sentinelles'.$secret);

	$query = 'INSERT IGNORE INTO inscription_nouvelle_saison SET id_membre = '.(int)$id_membre.', hash = "'.$session->MySQL()->EscapeString($secret).'", cout = 20;';
	$session->MySQL()->Query($query);
	
	$mail = '<html><body>
		<p class="p1">Bonjour,</p>
<p class="p3">Faisant suite &agrave; votre demande pour &ecirc;tre membre des Sentinelles de la Route,&nbsp;qui f&ecirc;te cette ann&eacute;e son 15e anniversaire,&nbsp;voici venu le temps de vous inscrire pour la saison 2013.</p>
<p class="p3">Pour &ecirc;tre membre en r&egrave;gle du club Les Sentinelles de la Route, vous devez payer votre inscription de 20 $ et acheter le maillot obligatoire du club au co&ucirc;t de 65 $.</p>
<p class="p3"><strong>Pour vous inscrire, voici la proc&eacute;dure :</strong></p>
<ul class="ul1">
<li class="li4"><span class="s1">Suivez le lien suivant&nbsp;:&nbsp;<a href="http://www.lessentinelles.com/confirmation_inscription.php?h='.$hash.'&t='.$t.'"><span class="s2">http://www.lessentinelles.com/confirmation_inscription.php?h='.$hash.'&t='.$t.'</span></a>;</span></li>
<li class="li1">Compl&eacute;tez votre fiche et imprimez&nbsp;le document de renonciation&nbsp;au bas de la page;</li>
<li class="li1">Signez et postez le document de renonciation, accompagn&eacute; du paiement par ch&egrave;que de votre inscription et de votre maillot, &agrave; l&rsquo;adresse postale du club :</li>
</ul>
<p class="p2">&nbsp;</p>
<p class="p1">Les Sentinelles de la Route</p>
<p class="p1">C.P. 9802, Succ. postale Ste-Foy</p>
<p class="p1">Qu&eacute;bec (Qu&eacute;bec)</p>
<p class="p1">G1V 4C3</p>
<p class="p1">&nbsp;</p>
<p class="p1">Lors de la soir&eacute;e d&rsquo;ouverture de la saison, &agrave; laquelle vous serez convoquer, votre maillot vous sera remis et vous recevrez gratuitement une plaque&nbsp;personnalis&eacute;e&nbsp;pour selle de v&eacute;lo. Il vous est possible de commander des plaques&nbsp;suppl&eacute;mentaires&nbsp;au co&ucirc;t de 2,50 $ chacune (taxes incluses), payable lors de la soir&eacute;e d&rsquo;ouverture.&nbsp;Pour que vous puissiez prendre possession de votre plaque de selle lors de la soir&eacute;e d&rsquo;ouverture, il faudra que vous nous fassiez parvenir votre inscription avant le 31 mars.</p>
<p class="p1">&nbsp;</p>
<p class="p1">Je commande ______ plaquette(s) suppl&eacute;mentaire(s).</p>
<p class="p5">&nbsp;</p>
<p class="p3">Merci !</p>
<p class="p3">Roger Fortin<br /> Pr&eacute;sident,<br /> Les Sentinelles de la Route</p>
</body></html>';

	imap_mail($row['courriel'], 'Inscription aux club Les Sentinelles de la Route', $mail, 'MIME-Version: 1.0'."\r\n".'Content-type: text/html; '."\r\n".'From: Les Sentinelles de la Route <info@lessentinelles.com>'."\r\n".'Reply-To: lessentinelles@hotmail.com');
}

header('Location: /fichemembreedit.php?idmembre='.$id_membre);