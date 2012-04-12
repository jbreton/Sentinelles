<?php
require_once('classes/mysql.inc');
require_once('classes/session.inc');
require_once('classes/membre.inc');
class Page {
  public static function Afficher($contenu) {
      $session = new Session();
      $membre = $session->Start();

      $erreur = false;

      if(!$membre && $session->FromPost()) {
        $erreur = 'Usager ou mot de passe invalide.';
      }

      if($membre && !$membre->EstInscrit() && $contenu != 'includes/fichemembreedit.inc') {
            header('location: /fichemembreedit.php');
            exit(0);
      }

      ob_start();

      echo '
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head>
<title>Les Sentinelles de la Route</title>
<script language="javascript">AC_FL_RunContent = 0;</script>
<script src="AC_RunActiveContent.js" language="javascript"></script>
<script src="lib/js/jquery-1.5.min.js" type="text/javascript"></script>
<link type="text/css" href="lib/css/blitzer/jquery-ui-1.8.9.custom.css" rel="stylesheet" />	
<script type="text/javascript" src="lib/js/jquery-ui-1.8.9.custom.min.js"></script>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link href="style.css" rel="stylesheet" media="screen" />

	</head>
	<body leftmargin="0" topmargin="0" marginwidth="0" marginheight="0">
		<div id="main">
                        <div id="login" style="background: #ffe49b; padding-top: 10px; padding-left: 25px; font-size: 12px;">';

      if($membre) {
        echo '<form method="POST"><span style="padding-right: 10px; font-weight: bold;">Bonjour '.$membre->prenom.' '.$membre->nom.' !</span><input type="submit" class="button" value="Me d&eacute;connecter" style="padding-left: 10px;" /><input type="hidden" id="logout" name="logout" value="1" /></form>';	
        
        if(!$membre->EstInscrit()) {
		echo '<div id="change_password_dialog" title="Inscription au club Les Sentinelles de la Route">
<span>Bienvenue sur le nouveau site des Sentinelles !</span><br />
<br />
<span>Nous sommes présentement en train de refaire une grande partie du site et plusieurs de ces améliorations vont demander de vous authentifier.</span><br />
<br />
<span>Votre nom d\'usager sera le courriel qui a été utilisé pour vous contacter ('.htmlentities($membre->courriel).'), vous devez maintenant choisir votre mot de passe. </span><br />
<br />
<span>Une fois votre mot de passe choisi, nous vous invitons à compléter votre fiche d\'identification.</span><br />
<br />
                        <span>Entrez votre nouveau mot de passe<span><br />
                        <input type="password" id="change_password" size="30" /><br />
                        <span>Confirmez votre mot de passe</span><br />
                        <input type="password" id="confirm_password" size="30" />
                      </div>
                      <script type="text/javascript">
                        $(function() {
	                        $("#change_password_dialog").data("can_close", false).dialog({
	                                resizable: false,
                                        modal: true,
                                        width: 600,
                                        dialogClass : "dialogue",
                                        beforeClose : function() { return $("#change_password_dialog").data("can_close"); },
                                        buttons : {
	                                        "Changer" : function() {
	                                                if($("#change_password").val() == "") {
	                                                        alert("Vous devez entrer un mot de passe");
                                                        }
                                                        else if($("#change_password").val().length < 6) {
	                                                        alert("Le mot de passe doit contenir au moins 6 caractères");
                                                        }
                                                        else if($("#change_password").val() != $("#confirm_password").val()) {
	                                                        alert("Les mots de passe ne sont pas identiques");
                                                        }
                                                        else {                                
	                                                        $.get("change.php?inscrit=Y&password="+encodeURIComponent($("#change_password").val()), function() {
                                                                  $("#change_password_dialog").data("can_close", true).dialog("close");
                                                                });
                                                        }
                                                }
                                        }
                                });
                        });
                      </script>';
        }
        else if($session->FromAuthentification()) {
	        echo '<div id="change_password_dialog" title="Changer de mot de passe">
                        <span>Entrez votre nouveau mot de passe<span><br />
                        <input type="password" id="change_password" size="30" /><br />
                        <span>Confirmez votre mot de passe</span><br />
                        <input type="password" id="confirm_password" size="30" />
                      </div>
                      <script type="text/javascript">
                        $(function() {
	                        $("#change_password_dialog").data("can_close", false).dialog({
	                                resizable: false,
                                        modal: true,
                                        width: 450,
                                        dialogClass : "dialogue",
                                        beforeClose : function() { return $("#change_password_dialog").data("can_close"); },
                                        buttons : {
	                                        "Changer" : function() {
	                                                if($("#change_password").val() == "") {
	                                                        alert("Vous devez entrer un mot de passe");
                                                        }
                                                        else if($("#change_password").val().length < 6) {
	                                                        alert("Le mot de passe doit contenir au moins 6 caractères");
                                                        }
                                                        else if($("#change_password").val() != $("#confirm_password").val()) {
	                                                        alert("Les mots de passe ne sont pas identiques");
                                                        }
                                                        else {                                
	                                                        $.get("change.php?password="+encodeURIComponent($("#change_password").val()), function() {
                                                                  $("#change_password_dialog").data("can_close", true).dialog("close");
                                                                });
                                                        }
                                                }
                                        }
                                });
                        });
                      </script>';
        }
      } 
      else {
        echo '<form method="POST">
          <span style="font-weight: bold; font-size: 14px;">Entr&eacute;e des membres</span><br />
          <label for="email">&gt; Nom usager : </label><input type="text" id="email" name="email" style="padding-left: 5px; padding-right: 10px; width: 150px;" />
          <label for="passwd">&gt; Mot de passe : </label><input type="password" id="passwd" name="passwd" style="width: 100px;" />
          <input type="submit" id="login" class="button" value="Soumettre" />
          <a id="reset_password" style="border-left: 1px solid black; color: black; padding-left: 5px; margin-left: 5px;" href="javascript:void(0);">Mot de passe oubli&eacute ?</a>';
        if($erreur) {
          echo '<br /><span style="color: red;">'.$erreur.'<span>';	
        }
        
        echo '</form>';

        echo '<div id="reset_password_dialog" title="Mot de passe oubli&eacute; ?">
                <span>Entrez votre adresse courriel, un message contenant un lien pour r&eacute;initialiser votre mot de passe vous sera envoy&eacute; dans quelques instants.</span><br />
                <input type="text" size="40" id="reset_email" />
              </div>
              <script type="text/javascript">$(function() {
                $("#reset_password_dialog").dialog({
	          autoOpen: false,
                  modal: true,
                  resizable: false,
                  width: 450,
                  dialogClass: "dialogue",
                  buttons: {
				"Envoyer": function() {
					if($("#reset_email").val() == "") {
						alert("Vous devez entrer votre adresse courriel");
					}
					else {
						$.ajax({
                                                    url: "reset.php?email="+encodeURIComponent($("#reset_email").val()), 
                                                    success: function(data){
                                                      if(data == "success") {
					  	        alert("Le courriel a été envoyé");
                                                        $("#reset_password_dialog").dialog("close");
                                                      }
                                                      else {
                                                        alert("L\'adresse courriel n\'est pas valide");
                                                      }
                                                    },
                                                    error: function() {
	                                              alert("L\'adresse courriel n\'est pas valide");
                                                    }
                                                });
					}
				},
				"Annuler": function() {
					$( this ).dialog( "close" );
				}
                           }
                });

                $("#reset_password").click(function() {
	          $("#reset_password_dialog").dialog("open");
                });
               });</script>';
      }

     echo '</div>
			<div id="col_gauche">';
     include('includes/menu.inc');

     echo '</div>
			<div id="entete">';

     include('includes/entete.inc');

     echo '</div>
			<div id="contenu">';
     include($contenu);
     echo '</div>
			<div id="bas">
				<table width="922" border="0" cellspacing="2" cellpadding="0" align="center" height="110">
					<tr height="90">
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/CycloDefiContreLeCancer2010?feat=directlink" target="_blank"><img src="images/cyclode2010.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/Tanguay2010?feat=directlink" target="_blank"><img src="images/tanguay.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/TourDeBeauce2010?feat=directlink" target="_blank"><img src="images/beauce.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/TriathlonEcoleDesPionniers02?feat=directlink" target="_blank"><img src="images/pionniers2010.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/MiniTourCBruneauLacBeauport?feat=directlink" target="_blank"><img src="images/minitour.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/RandonneeLaCinq?feat=directlink" target="_blank"><img src="images/lacinq.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/MarcheDeLaMemoire?feat=directlink" target="_blank"><img src="images/marchememoire.jpg" alt="" width="113" height="90" border="0" /></a></td>
						<td width="113" height="90"><a href="http://picasaweb.google.ca/lessentinelles2008/FestiVeloMEC2010?feat=directlink" target="_blank"><img src="images/festivelo.jpg" alt="" width="113" height="90" border="0" /></a></td>
					</tr>
					<tr height="14">
						<td align="center" width="113" height="14">Cyclo-D&eacute;fi contre le cancer</td>
						<td align="center" width="113" height="14">Randonn&eacute;e Tanguay</td>
						<td align="center" width="113" height="14">Tour de Beauce</td>
						<td align="center" width="113" height="14">Triathlon &eacute;cole Pionniers</td>
						<td align="center" width="113" height="14">Mini-tour C-Bruneau</td>
						<td align="center" width="113" height="14">La CINQ</td>
						<td align="center" width="113" height="14">Marche de la M&eacute;moire</td>
						<td align="center" width="113" height="14">Festi v&eacute;lo MEC</td>

					</tr>

				</table>

				<p><br />';

    include('includes/credits.inc');

    echo '</p>

			</div>			

	</div></body>
</html>';

      $session->Write();  

      ob_end_flush();
}
}