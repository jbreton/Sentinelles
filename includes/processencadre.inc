<?php

require_once('classes/mysql.inc');
?>

<h1>Pr&eacute;sence envoy&eacute;e</h1>
						
						<div class="textes">
	<p></p>
<?php

$errors=0;
$error="Les erreurs suivantes se sont produites en traitant votre formulaire.<ul>";

if($_POST['Present']==""){
   $errors=1;
   $error.="<li>Vous n'avez pas remplis un ou plusieurs des champs obligatoires. Veuillez retourner et corriger ces erreurs.";
}
if($errors==1) echo $error;
else{
   
   if ($_POST['Nopresence'] == '')
   {
      if ($_POST['Nomembre'] == '')
      {
         $query = "insert into presence (participation,id_groupe_vitesse_demande,id_activite,prenom,nom) values('".$_POST['Present']."','" .$_POST['choix_groupe_vitesse']."','" .$_POST['Noactivite']."','" .$_POST['Prenom']."','" .$_POST['Nom']."')" ;
      }
      else
      {
         $query = "insert into presence (participation,id_groupe_vitesse_demande,id_activite,id_membre) values('".$_POST['Present']."','" .$_POST['choix_groupe_vitesse']."','" .$_POST['Noactivite']."','" .$_POST['Nomembre']."')" ;
      }
      
   }
   else   
   {
      $query = "update presence set participation='".$_POST['Present']."',id_groupe_vitesse_demande='".$_POST['choix_groupe_vitesse']."'";
      $query.= " where id_presence=".(int)$_POST['Nopresence'].";";
   }

   
   $mysql = new MySQL();
   $mysql->Query($query);
   
?>
	<br>
	Merci <strong><?php echo $membre->prenom; ?> <?php echo $membre->nom; ?> </strong>, vos informations ont &eacute;t&eacute; sauvegard&eacute;es
        <br /><br />
<?php 
}
?></div>