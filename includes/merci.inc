
<link href="../style.css" rel="stylesheet" media="screen">		
<h1>Merci ! </h1>
<div class="textes">
		<p>&laquo; Votre message &agrave; &eacute;t&eacute; envoy&eacute; &raquo;</p>
	</div>
<div class="textes">
	<p>Nous vous remercions de l&rsquo;int&eacute;r&ecirc;t que vous portez au club Les Sentinelles de la Route.</p>
	<p>
		&nbsp;<img src="images/promo_sentinelles.jpg" alt="" width="700" height="487" border="0"></p>
</div>
<?
 
   $to = "lessentinelles@hotmail.com";
   
   $msg .= "Mon nom :     ".$_POST["nom"]."\n\n";
   $msg .= "Mon courriel :     ".$_POST["courriel"]."\n\n";
   $msg .= "Mon telephone :     ".$_POST["telephone"]."\n\n";
   $msg .= "Mon message :     ".$_POST["message"]."\n\n";

   


  mail($to, "Demande", $msg, "From: ".$_POST["courriel"]."\n");

?>
