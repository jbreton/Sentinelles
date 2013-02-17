<link href="../style.css" rel="stylesheet" media="screen">
						<h1>Coordonn&eacute;es transmises au club Les Sentinelles de la Route</h1>
						
						<div class="textes">
	<p></p>
	<?php
require_once('classes/mysql.inc');
$errors=0;
$error="Les erreurs suivantes se sont produites en traitant votre inscription.<ul>";

if($_POST['Prenom']=="" || $_POST['Nom']=="" || $_POST['Telephonedomicile']=="" || $_POST['Courriel']==""){
   $errors=1;
   $error.="<li>Vous n'avez pas  remplis un ou plusieurs des champs obligatoires. Veuillez retourner et corriger  ces erreurs.";
}
if($errors==1) echo $error;
else{
   $query = "insert into prospect(prenom,nom,telephone_residence,telephone_bureau,telephone_autre,courriel,adresse,ville,code_postal,";
   $query.= "date_naissance,maillot_grandeur,groupe_vitesse,no_assurance_maladie,urgence_nom,urgence_lien,urgence_tel_res,urgence_tel_bur,";
   $query.= "urgence_tel_autre,recrute_par) values('".$_POST['Prenom']."','".$_POST['Nom']."','".$_POST['Telephonedomicile']."','".$_POST['Telephonebureau']."','".$_POST['Autretelephone']."','";
   $query.= $_POST['Courriel']."','".$_POST['Adresse']."','".$_POST['Ville']."','".$_POST['CodePostal']."','".$_POST['Anneenaissance']."-".$_POST['Moisnaissance']."-".$_POST['Journaissance']."','".$_POST['maillot']."',";
   $query.= $_POST['Groupedevitesse'].",'".$_POST['Noassmaladie']."','".$_POST['Personneurgence']."','".$_POST['Lien']."','".$_POST['Telephonedomicilepersonne']."','";
   $query.= $_POST['Telephonebureaupersonne']."','".$_POST['Telephoneautrepersonne']."','".$_POST['Recrutepar']."');";

   $mysql = new MySQL();
   $mysql->Query($query);

   $stmt = $mysql->Prepare('SELECT message FROM messages WHERE id_messages = 1;');
   $stmt->execute();
	$stmt->bind_result($message);
   if($stmt->fetch()) {
      $stmt->close();
   }

   $message = stripslashes(sprintf($message, $_POST['Nom'], $_POST['Prenom'], $_POST['Courriel'], $_POST['Telephonedomicile']));
   mail("lessentinelles@hotmail.com","Nouvelle inscription",$message,"From: Les Sentinelles de la Route <info@lessentinelles.com>\r\nReply-To: lessentinelles@hotmail.com");


?><!-- Contenu de la page remerciement --> Voici les coordonn&eacute;es que vous avez entrer dans le formulaire d&rsquo;inscription.<br>
	<br>
	<table width=70%>
		<tr>
			<td>Pr&eacute;nom:<font color="#ff0000">*</font></td>
			<td><?php echo $_POST['Prenom']; ?></td>
		</tr>
		<tr>
			<td>Nom:<font color="#ff0000">*</font></td>
			<td><?php echo $_POST['Nom']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone domicile:<font color="#ff0000">*</font></td>
			<td><?php echo $_POST['Telephonedomicile']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone bureau:</td>
			<td><?php echo $_POST['Telephonebureau']; ?></td>
		</tr>
		<tr>
			<td>Autre t&eacute;l&eacute;phone:</td>
			<td><?php echo $_POST['Autretelephone']; ?></td>
		</tr>
		<tr>
			<td>Courriel:</td>
			<td><?php echo $_POST['Courriel']; ?></td>
		</tr>
		<tr>
			<td>Adresse:</td>
			<td><?php echo $_POST['Adresse']; ?></td>
		</tr>
		<tr>
			<td>Ville:</td>
			<td><?php echo $_POST['Ville']; ?></td>
		</tr>
		<tr>
			<td>Code Postal:</td>
			<td><?php echo $_POST['CodePostal']; ?></td>
		</tr>
		<tr>
			<td>Date de naissance:</td>
			<td><?php echo $_POST['Anneenaissance']; ?>-<?php echo $_POST['Moisnaissance']; ?>-<?php echo $_POST['Journaissance']; ?></td>
		</tr>
		<tr>
			<td>Taille du maillot:</td>
			<td><?php echo $_POST['maillot']; ?></td>
		</tr>
		<tr>
			<td>Groupe de vitesse:</td>
			<td><?php echo $_POST['Groupedevitesse']; ?></td>
		</tr>
		<tr>
			<td>No ass maladie:</td>
			<td><?php echo $_POST['Noassmaladie']; ?></td>
		</tr>
		<tr>
			<td>Personne &agrave; contacter en cas d'urgence:</td>
			<td><?php echo $_POST['Personneurgence']; ?></td>
		</tr>
		<tr>
			<td>Lien de parent&eacute; du contact en cas d'urgence:</td>
			<td><?php echo $_POST['Lien']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone domicile du contact en cas d'urgence:</td>
			<td><?php echo $_POST['Telephonedomicilepersonne']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone bureau du contact en cas d'urgence:</td>
			<td><?php echo $_POST['Telephonebureaupersonne']; ?></td>
		</tr>
		<tr>
			<td>Autre t&eacute;l&eacute;phone du contact en cas d'urgence:</td>
			<td><?php echo $_POST['Telephoneautrepersonne']; ?></td>
		</tr>
		<tr>
			<td>Recrut&eacute; par:</td>
			<td><?php echo $_POST['Recrutepar']; ?></td>
		</tr>
	</table>
	<br>
	Merci <strong><?php echo $_POST['Prenom']; ?> <?php echo $_POST['Nom']; ?> </strong>,<br>
	<br>
	un membre du comit&eacute; de recrutement vous contactera d&rsquo;ici quelques jours. <!-- Ne rien changer sous cette ligne --><?php 
}
?></div>