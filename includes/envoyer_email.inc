<?php

if(!$membre || !$membre->EstCA()) {
	include('includes/acceuil.inc');
        return;
}

if($_POST['courriel']) {
     $courriel = stripslashes($_POST['courriel']);
}

if($_POST['send']) {
     $email = '<html><body>'.$courriel.'</body></html>';

     echo '<b>Le courriel a &eacute;t&eacute; aux adresses suivantes : </b><br />';

     $query = 'SELECT nom, prenom, courriel FROM membre WHERE est_inscrit = "Y" order by nom, prenom;';
     $result = $session->MySQL()->Query($query);
     while($row = $result->fetch_assoc()) {
          echo $row['courriel'].'<br />';

          imap_mail($row['courriel'], stripslashes($_POST['sujet']), $email, 'MIME-Version: 1.0'."\r\n".'Content-type: text/html; '."\r\n".'From: Les Sentinelles de la Route <lessentinelles@hotmail.com>');
     }
     $result->close();
     
     echo '<br /><br />'.stripslashes($_POST['sujet']).'<br />'.$courriel;

     return;
}

?>
<script type="text/javascript" src="lib/tinymce/jscripts/tiny_mce/tiny_mce.js"></script>
<script type="text/javascript">
tinyMCE.init({
// General options
mode : "exact",
elements : "courriel",
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
<label for="sujet">Sujet : </label><input type="text" name="sujet" style="width: 200px;" /><br />
<textarea id="courriel" name="courriel" style="width: 90%; height: 500px;"><?php echo $courriel ?></textarea>
<br />
<input type="submit" name="preview" value="Prévisualiser" /><input type="submit" name="send" value="Envoyer" />
</form>
<?php

echo '<br /><br /><b>Le courriel sera envoyer aux adresses suivantes : </b><br />';

$query = 'SELECT nom, prenom, courriel FROM membre WHERE est_inscrit = "Y" order by nom, prenom;';
$result = $session->MySQL()->Query($query);
while($row = $result->fetch_assoc()) {
	echo $row['prenom'].' '.$row['nom'].' &lt;'.$row['courriel'].'&gt;<br />';
}
$result->close();

if($_POST['courriel']) {
    echo '<pre>'.$courriel.'</pre>';
}

?>