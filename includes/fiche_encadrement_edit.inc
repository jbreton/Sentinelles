<?php

if(!$membre || !$membre->EstCA()) {
	include('accueil.inc');
        return false;
}

if(!empty($_POST['nom_activite'])) {
      $query = 'SET type_activite="ENCADREMENT", nom_activite = ?, genre_nom = ?, date_activite = ?, description = ?, organisme = ?, lien_organisme = ?, lieu_depart = ?, lien_lieu_depart = ?, trajet_desc = ?, lien_trajet = ?, definition_groupes = ?, autres_infos = ?';

      if((int)$_POST['id_activite'] > 0) {
	    $query = 'UPDATE activite '.$query.' WHERE id_activite = '.(int)$_POST['id_activite'];
      }
      else {
	    $query = 'INSERT INTO activite '.$query;
      }

      $stmt = $session->MySQL()->Prepare($query);
      $stmt->bind_param('ssssssssssss', stripslashes($_POST['nom_activite']), stripslashes($_POST['genre']), stripslashes($_POST['date_activite']), stripslashes($_POST['description']), stripslashes($_POST['organisme']), stripslashes($_POST['lien_organisme']), stripslashes($_POST['lieu_depart']), stripslashes($_POST['lien_lieu_depart']), stripslashes($_POST['trajet_desc']), stripslashes($_POST['lien_trajet']), stripslashes($_POST['definition_groupes']), stripslashes($_POST['autres_infos']));
      $stmt->execute();
      $stmt->close();

      if(!empty($_POST['id_activite']))
            $id_activite = $_POST['id_activite'];
      else
            $id_activite = $session->MySQL()->LastInsertId();

      if(!empty($_POST['groupe_vitesse'])) {
            foreach($_POST['groupe_vitesse'] as $groupe_id => $groupe) {
                  if((int)$groupe_id > 0) {
                        $query = 'UPDATE groupe_vitesse SET description = "'.stripslashes($groupe).'", id_activite = '.$id_activite.' WHERE id_groupe_vitesse = '.(int)$groupe_id;
                        $session->MySQL()->Query($query);
                  }
                  else {
	                $query = 'INSERT INTO groupe_vitesse SET description = "'.stripslashes($groupe).'", id_activite = '.$id_activite.';';
                        $session->MySQL()->Query($query);
                  }
            }
      }
   
      if(!empty($_POST['groupe_efface'])) {
            foreach($_POST['groupe_efface'] as $id_groupe) {
                  $query = 'DELETE FROM groupe_vitesse WHERE id_groupe_vitesse = '.(int)$id_groupe;
                  $session->MySQL()->Query($query);
            }
      }
      
      if(empty($_POST['id_activite'])) {
          ob_end_clean();
	  header('Location: /liste_encadrements.php');
          exit;
      }
      else {
	  ob_end_clean();
	  header('Location: /liste_encadrements.php');
      }
}
else if((int)$_GET['id']) {
      $id = (int)$_GET['id'];
}
else {
      $id = 0;
}


$query = 'SELECT * FROM activite WHERE id_activite = '.(int)$id;
$result = $session->MySQL()->Query($query);
$row = $result->fetch_assoc();
$result->close();

?>
<script type="text/javascript" src="lib/tinymce/jscripts/tiny_mce/tiny_mce.js"></script>
<script type="text/javascript">
tinyMCE.init({
// General options
mode : "exact",
elements : "autres_infos",
theme : "advanced",
plugins : "spellchecker,pagebreak,style,layer,table,save,advhr,advimage,advlink,emotions,iespell,inlinepopups,insertdatetime,preview,media,searchreplace,print,contextmenu,paste,directionality,fullscreen,noneditable,visualchars,nonbreaking,xhtmlxtras,template",

// Theme options
theme_advanced_buttons1 : "save,newdocument,|,bold,italic,underline,strikethrough,|,justifyleft,justifycenter,justifyright,justifyfull,|,styleselect,formatselect,fontselect,fontsizeselect",
theme_advanced_buttons2 : "cut,copy,paste,pastetext,pasteword,|,search,replace,|,bullist,numlist,|,outdent,indent,blockquote,|,undo,redo,|,link,unlink,anchor,image,cleanup,help,code,|,insertdate,inserttime,preview,|,forecolor,backcolor",
theme_advanced_buttons3 : "tablecontrols,|,hr,removeformat,visualaid,|,sub,sup,|,charmap,emotions,iespell,media,advhr,|,print,|,ltr,rtl,|,fullscreen",
theme_advanced_buttons4 : "insertlayer,moveforward,movebackward,absolute,|,styleprops,spellchecker,|,cite,abbr,acronym,del,ins,attribs,|,visualchars,nonbreaking,template,blockquote,pagebreak,|,insertfile,insertimage",
theme_advanced_toolbar_location : "top",
theme_advanced_toolbar_align : "left",
theme_advanced_statusbar_location : "bottom",
theme_advanced_resizing : true,

// Skin options
skin : "o2k7",
skin_variant : "silver",

});
</script>
<form method="POST">
<?php if($row) echo '<input type="hidden" name="id_activite" value="'.(int)$row['id_activite'].'" />'; ?>
<table>
<tbody>

<tr><td>Nom de l'encadrement :</td><td><input type="text" id="nom_activite" name="nom_activite" value="<?php echo htmlentities($row['nom_activite']); ?>" size="35" /><select id="genre" name="genre"><option value="M" <?php echo ($row['genre_nom'] == 'M' ? 'selected="selected"' : ''); ?>>M</option><option value="F" <?php echo ($row['genre_nom'] == 'F' ? 'selected="selected"' : ''); ?>>F</option></select></td></tr>
<tr><td>Organisme :</td><td><input type="text" id="organisme" name="organisme" size="35" value="<?php echo htmlentities($row['organisme']); ?>" /></td></tr>
<tr><td>Site web de l'organisme :</td><td><input id="lien_organisme" name="lien_organisme" value="<?php echo htmlentities($row['lien_organisme']); ?>" type="text" size="50" /><input type="button" value="Tester le lien" onclick="window.open(document.getElementById('lien_organisme').value, '_blank');" /></td></tr>
<tr><td>Date :</td><td><input type="text" id="date_activite" name="date_activite" value="<?php echo $row['date_activite']; ?>" size="15" /><script type="text/javascript">$(function(){ var min = new Date(); min.setDate(1); min.setMonth(0); var max = new Date(); max.setMonth(11); max.setDate(31); $("#date_activite").datepicker({dateFormat : "yy-mm-dd", minDate : min, maxDate : max, defaultDate : "<?php echo $row['date_activite']; ?>", monthNames: ['Janvier','F&eacute;vrier','Mars','Avril','Mai','Juin','Juillet','Ao&ucirc;t','Septembre','Octobre','Novembre','Decembre'], dayNamesMin: ['Di', 'Lu', 'Ma', 'Me', 'Je', 'Ve', 'Sa']}); });</script></td></tr>
<tr><td style="vertical-align: top;">Description :</td><td><textarea rows="3" cols="35" id="description" name="description"><?php echo htmlentities($row['description']); ?></textarea></td></tr>
<tr><td colspan="2"><br /></td></tr>
<!--<tr><td colspan="2">Personne contact :</td></tr>
<tr><td>Nom :</td><td><input type="text" value="Jean-Pierre Laforest" size="30" id="nom_contact" name="nom_contact" /></td></tr>
<tr><td>Telephone :</td><td><input type="text" value="418 555-5555" size="15" id="tel_contact" name="tel_contact" /></td></tr>
<tr><td>Courriel :</td><td><input type="text" value="jp.laforest@videotron.ca" size="35" id="courriel_contact" name="courriel_contact" /></td></tr>-->
<tr><td colspan="2"><br /></td></tr>

<tr><td>Lieu de depart :</td><td><input type="text" size="50" id="lieu_depart" name="lieu_depart" value="<?php echo htmlentities($row['lieu_depart']); ?>" /></td></tr>
<tr><td>Lien du lieu de depart :</td><td><input type="text" id="lien_lieu_depart" name="lien_lieu_depart" value="<?php echo htmlentities($row['lien_lieu_depart']); ?>" size="50" /><input type="button" value="Tester le lien" onclick="window.open(document.getElementById('lien_lieu_depart').value, '_blank');" /><td></tr>

<tr><td colspan="2"><br /></td></tr>


<tr><td>Description du trajet :</td><td><input type="text" id="trajet_desc" name="trajet_desc" value="<?php echo htmlentities($row['trajet_desc']); ?>" size="50" /></td></tr>
<tr><td>Lien du trajet :</td><td><input type="text" id="lien_trajet" name="lien_trajet" value="<?php echo htmlentities($row['lien_trajet']); ?>" size="50" /><input type="button" value="Tester le lien" onclick="window.open(document.getElementById('lien_trajet').value, '_blank');" /><td></tr>

<tr><td colspan="2"><br /></td></tr>

<tr><td style="vertical-align: top;">Description des parcours :</td><td><textarea rows="3" cols="35" id="definition_groupes" name="definition_groupes"><?php echo htmlentities($row['definition_groupes']); ?></textarea></td></tr>
</td></tr>

</tbody>

</table>
<span>Definition des parcours :</span>
<table id="groupes">
<tbody>
<?php 

if($row) {
	$query = 'SELECT id_groupe_vitesse, description FROM groupe_vitesse WHERE id_activite = '.(int)$row['id_activite'].';';
	$sub_result = $session->MySQL()->Query($query);
	while($sub_row = $sub_result->fetch_assoc()) {
		echo '<tr id="tr_groupe_vitesse_'.$sub_row['id_groupe_vitesse'].'"><td><input type="text" id="groupe_vitesse['.$sub_row['id_groupe_vitesse'].']" name="groupe_vitesse['.$sub_row['id_groupe_vitesse'].']" value="'.htmlentities($sub_row['description']).'" /></td><td style="color: red; font-weight: bold;"><span onclick="supprimerGroupe('.$sub_row['id_groupe_vitesse'].');" style="cursor: pointer;">X</span></td></tr>';
	}
}

?>
</tbody>
</table>
<a href="javascript:ajouterGroupe();" style="color: black;">Ajouter un parcour</a>
<script type="text/javascript">
prochain_groupe = -1;
function ajouterGroupe() {
	$('#groupes tbody').append('<tr id="tr_groupe_vitesse_'+prochain_groupe+'"><td><input type="text" id="groupe_vitesse['+prochain_groupe+']" name="groupe_vitesse['+prochain_groupe+']" /></td><td style="color: red; font-weight: bold;"><span onclick="supprimerGroupe('+prochain_groupe+');" style="cursor: pointer;">X</span></td></tr>');
        prochain_groupe--;
}
function supprimerGroupe(groupe) {
	$('#tr_groupe_vitesse_'+groupe).remove();

        if(groupe > 0) {
	        $('form').append('<input type="hidden" id="groupe_efface['+groupe+']" name="groupe_efface['+groupe+']" value="'+groupe+'" />');

        }
}


function submit() {
	var valid = true;
 
        if($('#nom_activite').val() == '') {
	    alert('Le nom de l\'activite est requis');
            valid = false;
        }

        return valid;
}

$(function() {
   $('form').submit(submit);	
});
</script>

<br /><br />

<span>Information supplementaires : <span><br />
<textarea id="autres_infos" name="autres_infos" style="width:100%; height: 300px;"><?php echo htmlentities(stripslashes($row['autres_infos'])); ?></textarea>

<br /><br />
<input type="submit" value="Enregistrer" /><input type="button" value="Annuler" onclick="window.back();" />
</form>