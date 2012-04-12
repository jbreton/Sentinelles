<?php

if(!$membre || !$membre->EstCA()) {
	include('accueil.inc');
        return false;
}

if(!empty($_POST['nom_activite'])) {
      $query = 'SET type_activite="SORTIE", nom_activite = ?, date_activite = ?, description = ?, lieu_depart = ?, lien_lieu_depart = ?, trajet_desc = ?, lien_trajet = ?, autres_infos = ?';

      if((int)$_POST['id_activite'] > 0) {
	    $query = 'UPDATE activite '.$query.' WHERE id_activite = '.(int)$_POST['id_activite'];
      }
      else {
	    $query = 'INSERT INTO activite '.$query;
      }

      $stmt = $session->MySQL()->Prepare($query);
      $stmt->bind_param('ssssssss', $_POST['nom_activite'], $_POST['date_activite'], $_POST['description'], $_POST['lieu_depart'], $_POST['lien_lieu_depart'], $_POST['trajet_desc'], $_POST['lien_trajet'], $_POST['autres_infos']);
      $stmt->execute();
      $stmt->close();
      
      if(empty($_POST['id_activite'])) {
          ob_end_clean();
	  header('Location: /liste_sorties.php');
          exit;
      }
      else {
	  ob_end_clean();
	  header('Location: /liste_sorties.php');
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
<tr><td>Nom de la sortie :</td><td><input type="text" id="nom_activite" name="nom_activite" value="<?php echo htmlentities($row['nom_activite']); ?>" size="35" /><select id="genre" name="genre"><option value="M" <?php echo ($row['genre_nom'] == 'M' ? 'selected="selected"' : ''); ?>>M</option><option value="F" <?php echo ($row['genre_nom'] == 'F' ? 'selected="selected"' : ''); ?>>F</option></select></td></tr>
<tr><td>Date :</td><td><input type="text"id="date_activite" name="date_activite" value="<?php echo $row['date_activite']; ?>" size="15" /><script type="text/javascript">$(function(){ var min = new Date(); min.setDate(1); min.setMonth(0); var max = new Date(); max.setMonth(11); max.setDate(31); $("#date_activite").datepicker({dateFormat : "yy-mm-dd", minDate : min, maxDate : max, defaultDate : "<?php echo $row['date_activite']; ?>", monthNames: ['Janvier','F&eacute;vrier','Mars','Avril','Mai','Juin','Juillet','Ao&ucirc;t','Septembre','Octobre','Novembre','Decembre'], dayNamesMin: ['Di', 'Lu', 'Ma', 'Me', 'Je', 'Ve', 'Sa']}); });</script></td></tr>
<tr><td style="vertical-align: top;">Description :</td><td><textarea rows="3" cols="35" id="description" name="description"><?php echo htmlentities($row['description']); ?></textarea></td></tr>
<tr><td colspan="2"><br /></td></tr>
<tr><td colspan="2"><br /></td></tr>
<tr><td>Lieu de depart :</td><td><input type="text" size="50" id="lieu_depart" name="lieu_depart" value="<?php echo htmlentities($row['lieu_depart']); ?>" /></td></tr>
<tr><td>Lien du lieu de depart :</td><td><input type="text" id="lien_lieu_depart" name="lien_lieu_depart" value="<?php echo htmlentities($row['lien_lieu_depart']); ?>" size="50" /><input type="button" value="Tester le lien" onclick="window.open(document.getElementById('lien_lieu_depart').value, '_blank');" /><td></tr>
<tr><td colspan="2"><br /></td></tr>
<tr><td>Description du trajet :</td><td><input type="text" id="trajet_desc" name="trajet_desc" value="<?php echo htmlentities($row['trajet_desc']); ?>" size="50" /></td></tr>
<tr><td>Lien du trajet :</td><td><input type="text" id="lien_trajet" name="lien_trajet" value="<?php echo htmlentities($row['lien_trajet']); ?>" size="50" /><input type="button" value="Tester le lien" onclick="window.open(document.getElementById('lien_trajet').value, '_blank');" /><td></tr>
</tbody>
</table>
<script type="text/javascript">
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
<textarea id="autres_infos" name="autres_infos" style="width:100%; height: 300px;"><?php echo htmlentities($row['autres_infos']); ?></textarea>
<br /><br />
<input type="submit" value="Enregistrer" /><input type="button" value="Annuler" onclick="window.back();" />
</form>