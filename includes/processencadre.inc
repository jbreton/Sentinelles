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
         $query = "insert into presence (participation,id_groupe_vitesse_demande,id_activite,prenom,nom,date_confirmation) values('".$_POST['Present']."','" .$_POST['choix_groupe_vitesse']."','" .$_POST['Noactivite']."','" .$_POST['Prenom']."','" .$_POST['Nom']."', '".date('Y-m-d H:i:s')."')" ;
      }
      else
      {
         $query = "insert into presence (participation,id_groupe_vitesse_demande,id_activite,id_membre,date_confirmation) values('".$_POST['Present']."','" .$_POST['choix_groupe_vitesse']."','" .$_POST['Noactivite']."','" .$_POST['Nomembre']."', '".date('Y-m-d H:i:s')."')" ;
      }
      
   }
   else   
   {
      $query = "update presence set participation='".$_POST['Present']."',id_groupe_vitesse_demande='".$_POST['choix_groupe_vitesse']."', date_confirmation = '".date('Y-m-d H:i:s')."'";
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