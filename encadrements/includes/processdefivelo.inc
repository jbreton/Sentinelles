    <?php
    include("global.inc.php");
    $errors=0;
    $error="Les erreurs suivantes se sont produites en traitant votre inscription.<ul>";
    pt_register('POST','Prenom');
    pt_register('POST','Nom');
    pt_register('POST','Present');
    pt_register('POST','Parcours');
    if($Prenom=="" || $Nom=="" || $Present==""){
    $errors=1;
    $error.="<li>Vous n'avez pas  remplis un ou plusieurs des champs obligatoires. Veuillez retourner et corriger  ces erreurs.";
    }
    if($errors==1) echo $error;
    else{
    $where_form_is="http".($HTTP_SERVER_VARS["HTTPS"]=="on"?"s":"")."://".$SERVER_NAME.strrev(strstr(strrev($PHP_SELF),"/"));
    $message="Prenom: ".$Prenom."
    Nom: ".$Nom."
    Present: ".$Present."
    Parcours: ".$Parcours."
    ";
    $message = stripslashes($message);
    mail("lessentinelles@hotmail.com","Pr�sence D�fi-V�lo Desjardins",$message,"From: lessentinelles@videotron.ca");
    ?>
    
    
    <!-- Contenu de la page remerciement -->
    <div class="textes"> 
    Merci!<br>
    Votre inscription a �t� envoy�e � l'encadreur responsble de cette activit�.<br>
    Voici les coordonn&eacute;es que vous avez entrer dans le formulaire.<br>
    <br>
    <table width=70%>
    <tr><td>Pr&eacute;nom:<font color='#ff0000'>*</font></td>
    <td> <?php echo $Prenom; ?> </td></tr>
    <tr><td>Nom:<font color='#ff0000'>*</font></td>
    <td> <?php echo $Nom; ?> </td></tr>
    <tr><td>Je serai pr�sent:<font color='#ff0000'>*</font></td>
    <td> <?php echo $Present; ?> </td></tr>
    <tr><td>Parcours choisi:<font color='#ff0000'>*</font></td>
    <td> <?php echo $Parcours; ?> </td></tr>
    </table>
    
    <br>
    Merci <strong><?php echo $Prenom; ?> <?php echo $Nom; ?> </strong><br>
    <br>
    <!-- Ne rien changer sous cette ligne -->
    
    <?php 
    }
    ?>
    </div>
    