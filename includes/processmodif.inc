						<h1>Coordonn&eacute;es transmises au club Les Sentinelles de la Route</h1>
						
						<div class="textes">
	<p></p>
	<?php

require_once('classes/mysql.inc');
$errors=0;
$error="Les erreurs suivantes se sont produites en traitant votre formulaire.<ul>";

if($_POST['Prenom']=="" || $_POST['Nom']=="" || $_POST['Telephonedomicile']==""){
   $errors=1;
   $error.="<li>Vous n'avez pas remplis un ou plusieurs des champs obligatoires. Veuillez retourner et corriger ces erreurs.";
}
if($errors==1) echo $error;
else{
   $query = "update membre set prenom='".$_POST['Prenom']."',nom='".$_POST['Nom']."',telephone_residence='".$_POST['Telephonedomicile']."',telephone_bureau='".$_POST['Telephonebureau'];
   $query.= "',telephone_autre='".$_POST['Autretelephone']."',adresse='".$_POST['Adresse']."',ville='".$_POST['Ville']."',code_postal='".$_POST['CodePostal']."',";
   $query.= "date_naissance='".$_POST['Anneenaissance']."-".$_POST['Moisnaissance']."-".$_POST['Journaissance']."',maillot_grandeur='".$_POST['maillot']."',groupe_vitesse=".$_POST['Groupedevitesse'];
   $query.= ",no_assurance_maladie='".$_POST['Noassmaladie']."',urgence_nom='".$_POST['Personneurgence']."',urgence_lien='".$_POST['Lien']."',urgence_tel_res='".$_POST['Telephonedomicilepersonne']."'";
   $query.= ",urgence_tel_bur='".$_POST['Telephonebureaupersonne']."',urgence_tel_autre='".$_POST['Telephoneautrepersonne']."'";
   
   if ($_POST['Coordpublic'] == 'on')
   {
      $query.= ",coordonnees_publique='Y'";
   }
   else   
   {
      $query.= ",coordonnees_publique='N'";
   }
   
   if ($membre->EstCA())
   {
      if ($_POST['Maillotremis'] == 'on')
      {
         $query.= ",maillot_remis='Y'";
      }
      else   
      {
         $query.= ",maillot_remis='N'";
      }

      if ($_POST['Dossardremis'] == 'on')
      {
         $query.= ",dossard_remis='Y'";
      }
      else   
      {
         $query.= ",dossard_remis='N'";
      }
   }
   
   $query.= " where id_membre=".(int)$_POST['Nomembre'].";";
   
   $mysql = new MySQL();
   $mysql->Query($query);

   if($membre->EstCA()) {
     $query = 'UPDATE inscription SET cotisation = "'.$_POST['cotisation'].'", formulaire_recu= "'.$_POST['formulaire_recu'].'",cotisation_payee = "'.$_POST['cotisation_payee'].'", date_paye = "'.$_POST['date_paye'].'" WHERE id_membre = '.(int)$_POST['Nomembre'].' AND id_saison = (SELECT id_saison FROM saison WHERE active = "Y");';	
     $mysql->Query($query);
   }

   $membre->Refresh($mysql);
   
?><!-- Contenu de la page remerciement --> Voici les coordonn&eacute;es que vous avez entrer dans le formulaire.<br>
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
	</table>
	<br>
	Merci <strong><?php echo $_POST['Prenom']; ?> <?php echo $_POST['Nom']; ?> </strong>, vos informations ont &eacute;t&eacute; sauvegard&eacute;es
        <br /><br /><strong><a href="javascript:void(0);" onclick="window.open('formulaire_inscription.php', '_blank');" style="color: red;">Cliquez ici</a> pour une version imprimable du formulaire d'inscription. </strong>
<br />Veuillez signer le formulaire et nous le faire parvenir &agrave; l'adresse suivante pour compl&eacute;ter votre inscription :
<br />
Les Sentinelles de la Route<br />
			C.P. 9802, Succ. postale Sainte-Foy<br />
		Qu&eacute;bec (Qu&eacute;bec)<br />
			G1V 4C3

         <!-- Ne rien changer sous cette ligne --><?php 
}
?></div>