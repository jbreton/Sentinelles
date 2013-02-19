						<h1>Coordonn&eacute;es transmises au club Les Sentinelles de la Route</h1>
						
						<div class="textes">
	<p></p>
	<?php

require_once('classes/mysql.inc');
$errors=0;
$error="Les erreurs suivantes se sont produites en traitant votre formulaire.<ul>";

$mysql = new MySQL();
$post = $mysql->EscapePost($_POST);

if($post['Prenom']=="" || $post['Nom']=="" || $post['Courriel']=="" || $post['Telephonedomicile']==""){
   $errors=1;
   $error.="<li>Vous n'avez pas remplis un ou plusieurs des champs obligatoires. Veuillez retourner et corriger ces erreurs.";
}
if($errors==1) echo $error;
else{
   $query = "update membre set prenom='".$post['Prenom']."',nom='".$post['Nom']."', courriel='".$post['Courriel']."',telephone_residence='".$post['Telephonedomicile']."',telephone_bureau='".$post['Telephonebureau'];
   $query.= "',telephone_autre='".$post['Autretelephone']."',adresse='".$post['Adresse']."',ville='".$post['Ville']."',code_postal='".$post['CodePostal']."',";
   $query.= "date_naissance='".$post['Anneenaissance']."-".$post['Moisnaissance']."-".$post['Journaissance']."',maillot_grandeur='".$post['maillot']."',groupe_vitesse=".$post['Groupedevitesse'];
   $query.= ",no_assurance_maladie='".$post['Noassmaladie']."',urgence_nom='".$post['Personneurgence']."',urgence_lien='".$post['Lien']."',urgence_tel_res='".$post['Telephonedomicilepersonne']."'";
   $query.= ",urgence_tel_bur='".$post['Telephonebureaupersonne']."',urgence_tel_autre='".$post['Telephoneautrepersonne']."'";
   
   if ($post['Coordpublic'] == 'on')
   {
      $query.= ",coordonnees_publique='Y'";
   }
   else   
   {
      $query.= ",coordonnees_publique='N'";
   }
   
   if ($membre->EstCA())
   {
      if ($post['Maillotremis'] == 'on')
      {
         $query.= ",maillot_remis='Y'";
      }
      else   
      {
         $query.= ",maillot_remis='N'";
      }

      if ($post['Dossardremis'] == 'on')
      {
         $query.= ",dossard_remis='Y'";
      }
      else   
      {
         $query.= ",dossard_remis='N'";
      }
   }
   
   if($post['mot_passe'] != '') {
	  if($post['mot_passe'] == $post['confirmation']) {
		  $query .= ',mot_passe = "'.$post['mot_passe'].'"';
	  }
   }
   
   $query.= " where id_membre=".(int)$post['Nomembre'].";";
   
   $mysql->Query($query);

   if($membre->EstCA()) {
     $query = 'UPDATE inscription SET cotisation = "'.$post['cotisation'].'", formulaire_recu= "'.$post['formulaire_recu'].'",cotisation_payee = "'.$post['cotisation_payee'].'", date_paye = "'.$post['date_paye'].'" WHERE id_membre = '.(int)$post['Nomembre'].' AND id_saison = (SELECT id_saison FROM saison WHERE active = "Y");';	
     $mysql->Query($query);
   }

   $membre->Refresh($mysql);
   
?><!-- Contenu de la page remerciement --> Voici les coordonn&eacute;es que vous avez entrer dans le formulaire.<br>
	<br>
	<table width=70%>
		<tr>
			<td>Pr&eacute;nom:<font color="#ff0000">*</font></td>
			<td><?php echo $post['Prenom']; ?></td>
		</tr>
		<tr>
			<td>Nom:<font color="#ff0000">*</font></td>
			<td><?php echo $post['Nom']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone domicile:<font color="#ff0000">*</font></td>
			<td><?php echo $post['Telephonedomicile']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone bureau:</td>
			<td><?php echo $post['Telephonebureau']; ?></td>
		</tr>
		<tr>
			<td>Autre t&eacute;l&eacute;phone:</td>
			<td><?php echo $post['Autretelephone']; ?></td>
		</tr>
		<tr>
			<td>Adresse:</td>
			<td><?php echo $post['Adresse']; ?></td>
		</tr>
		<tr>
			<td>Ville:</td>
			<td><?php echo $post['Ville']; ?></td>
		</tr>
		<tr>
			<td>Code Postal:</td>
			<td><?php echo $post['CodePostal']; ?></td>
		</tr>
		<tr>
			<td>Date de naissance:</td>
			<td><?php echo $post['Anneenaissance']; ?>-<?php echo $post['Moisnaissance']; ?>-<?php echo $post['Journaissance']; ?></td>
		</tr>
		<tr>
			<td>Taille du maillot:</td>
			<td><?php echo $post['maillot']; ?></td>
		</tr>
		<tr>
			<td>Groupe de vitesse:</td>
			<td><?php echo $post['Groupedevitesse']; ?></td>
		</tr>
		<tr>
			<td>No ass maladie:</td>
			<td><?php echo $post['Noassmaladie']; ?></td>
		</tr>
		<tr>
			<td>Personne &agrave; contacter en cas d'urgence:</td>
			<td><?php echo $post['Personneurgence']; ?></td>
		</tr>
		<tr>
			<td>Lien de parent&eacute; du contact en cas d'urgence:</td>
			<td><?php echo $post['Lien']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone domicile du contact en cas d'urgence:</td>
			<td><?php echo $post['Telephonedomicilepersonne']; ?></td>
		</tr>
		<tr>
			<td>T&eacute;l&eacute;phone bureau du contact en cas d'urgence:</td>
			<td><?php echo $post['Telephonebureaupersonne']; ?></td>
		</tr>
		<tr>
			<td>Autre t&eacute;l&eacute;phone du contact en cas d'urgence:</td>
			<td><?php echo $post['Telephoneautrepersonne']; ?></td>
		</tr>
	</table>
	<br>
	Merci <strong><?php echo $post['Prenom']; ?> <?php echo $post['Nom']; ?> </strong>, vos informations ont &eacute;t&eacute; sauvegard&eacute;es
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