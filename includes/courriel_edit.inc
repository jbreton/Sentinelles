
<script type="text/javascript" src="lib/tinymce/jscripts/tiny_mce/tiny_mce.js"></script>
<script type="text/javascript">
tinyMCE.init({
// General options
mode : "exact",
elements : "message",
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
skin_variant : "silver"

});
</script>
<form method="POST">
<?php if($row) echo '<input type="hidden" name="id_courriel" value="'.(int)$row['id_courriel'].'" />'; ?>
<table>
	<tbody>
		<tr><td>Nom du courriel :</td><td><input type="text" id="nom" name="nom" value="<?php echo htmlentities($row['nom']); ?>" size="80" /></td></tr>
<tr><td></td><td></td></tr>
<tr><td>Objet</td><td><input id="objet" name="objet" value="<?php echo htmlentities($row['objet']); ?>" type="text" size="80" /></td></tr>
</tbody>
</table>
<script type="text/javascript">
function submit() {
	var valid = true;
 
        if($('#nom').val() == '') {
	    alert('Le nom du courriel est requis');
            valid = false;
        }
		
		if($('#objet').val() == '') {
	    alert('L\'objet du courriel est requis');
            valid = false;
        }
		
		if(tinyMCE.activeEditor.getContent({format : 'raw'}) == '') {
			alert('Le contenu du courriel est requis');
            valid = false;
        }

        return valid;
}

$(function() {
   $('form').submit(submit);	
});
</script>

<br /><br />

<span>Courriel : <span><br />
<textarea id="message" name="message" style="width:100%; height: 300px;"><?php echo htmlentities(stripslashes($row['message'])); ?></textarea>
<br /><span>Astuce : il est possible d'inscrire [NOM], [PRENOM] et [LIEN] qui seront remplacés à l'envoi par le nom du membre, son prénom et un lien personnalisé pour ouvrir la fiche de l'encadrement directement.</span>

<?php if($row['id_activite']) echo '<br /><input type="checkbox" id="inclure_lien" name="inclure_lien" value="Y" '.($row['inclure_lien'] == 'Y' ? 'checked="checked"' : '').' /><label for="inclure_lien">Inclure le lien pour l\'inscription</label>'; ?>
<br /><br />
<input type="submit" value="Enregistrer" /><input type="submit" name="send" value="Envoyer" style="padding-left: 20px;" /><br />
</form>