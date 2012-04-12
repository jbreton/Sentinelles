<link href="../style.css" rel="stylesheet" media="screen">
<a href="index.php"><img src="images/logo.gif" alt="" width="185" height="140" border="0"></a>
						<div align="center">
							<div class="menu">
								<div class="menugras">
									<p class="menu"><span class="menugras"><span class="menugras"></span></span></p>
									<table width="185" border="0" cellspacing="0" cellpadding="0">
										<tr>
					<td width="135" style="padding-left: 50px;">
						<div align="center">
							<div class="menu">
								<div class="menugras">
									<p class="menu"><span class="menugras"><span class="menugras"><a href="index.php">ACCUEIL</a></span></span></p>
								</div>
							</div>

 <?php 

if($membre) {
   echo '<p class="menugras"><span class="menugras">LA SECTION<br />DES MEMBRES</span><br />
<a href="fichemembreview.php">&gt; Ma fiche</a><br />
<a href="liste_membres.php">&gt; Liste des membres</a><br />
<a href="http://www.lessentinelles.com/membrereg/reunion.html">&gt; Documents</a>
</p>';
}
else {
   echo '<p class="menugras"><span class="menugras"><span class="menugras"><a href="devenirmembre.php" class="menugras">DEVENIR MEMBRE<br>
											</a></span></span></p>';
}

if($membre && $membre->EstCA()) {
   echo '<p class="menugras"><span class="menugras">SECTION DU CA</span><br />
<a href="liste_membres.php">&gt; Liste des membres</a><br />
<a href="liste_nouveaux_membres.php">&gt; Nouveaux membres</a><br />
<a href="liste_encadrements.php">&gt; Liste des encadrements</a><br />
<a href="liste_sorties.php">&gt; Liste des sorties</a><br />
<a href="javascript:alert(\'En construction\');">&gt; Administration du site</a><br />
<a href="http://www.lessentinelles.com/membreca/index.html">&gt; Documents</a>
</p>';
}

 ?>

							<div class="menugras">
								<p class="menugras"><span class="menugras"><a href="nousjoindre.php">COMMUNIQUER<br>
											AVEC LE CLUB</a></span></p>
								<span class="menugras">LE CLUB</span></div>
							<div class="menu">
								<span class="menu"><a href="professionnel.php">&gt; Professionnel</a><br>
									<a href="historique.php">&gt; Historique</a><br>
									<a href="reglements.php">&gt; R&egrave;glements</a><br>
									<a href="codeethique.php">&gt; Code d'&eacute;thique</a><br>
									<a href="lesmembres.php">&gt; Les Membres</a><br>
									<a href="commanditaires.php">&gt; Commanditaires</a><br>
									<a href="realisations.php">&gt; R&eacute;alisations</a><br>
									<a href="webmestre.php">&gt; Webmestre</a></span>
								<p><img src="images/picto_mois.gif" alt="" width="45" height="45" border="0"><br>
									<span class="menugras">LES ACTIVIT&Eacute;S<br>
									</span><span class="menu"><a href="calendrier_encadrements.php">&gt; Encadrements</a><br>
									</span><span class="menu"><a href="sorties.php">&gt; Sorties<br>
										</a></span><span class="menugras"><a href="http://www.lessentinelles.com/dotclear/index.php" target="_blank">LE BLOG <img src="images/bulle_blog.gif" alt="" width="42" height="43" border="0"><br>
												DES MEMBRES<br>
										</a></span><a href="http://www.lessentinelles.com/dotclear/index.php?pages/Anecdotes-de-la-saison" target="_blank"><span class="menu">&gt; </span><span class="menugras">Anecdotes </span></a><a href="http://www.lessentinelles.com/dotclear/index.php?pages/March%C3%A9-aux-puces" target="_blank"><span class="menugras"><br>
										</span><span class="menu">&gt; </span><span class="menugras">March&eacute; aux puces</span></a></p></p>
							</div>
							<div class="menugras">
								<p class="menugras"><span class="menugras"><a href="http://www.picasaweb.google.ca/lessentinelles2008" target="_blank">LA GALERIE<br>
											DES PHOTOS<br>
										</a></span><img src="images/picto_photos.jpg" alt="" width="95" height="83" border="0"><span class="menugras"><a href="http://www.picasaweb.google.ca/lessentinelles2008" target="_blank"><br>
										</a></span></p>
								<div class="menugras">
									<p class="menugras"><a href="videos.php">VID&Eacute;OS DES ENCADREMENTS</a></p>
									<p class="menugras"><span class="menugras"><a href="liensutiles.php">LIENS UTILES</a></span></p>
<p><a href="http://www.facebook.com/lesSentinellesdelaRoute"><img src="images/f_logo.png" /></a></p>								
								</div>
							</div>
						</div>
					</td>
				</tr>
									</table>
									<p class="menu"></p>
								</div>
							</div>
						</div>