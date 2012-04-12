<?php
require_once('classes/mysql.inc');
require_once('classes/session.inc');
require_once('classes/membre.inc');

$mysql = new MySQL();
$session = new Session($mysql);
$membre = $session->Start();

$erreur = false;
if(!$membre && $_POST['email']) {
  $membre = $session->Login($_POST['email'], $_POST['passwd']);
  if(!$membre) $erreur = 'Usager ou mot de passe invalide.';
}

if($membre) {
  echo '<span style="padding-right: 10px;">Bonjour '.$membre->prenom.' '.$membre->nom.'<span><input type="button" class="button" value="Me d&eacute;connecter" />';	
} 
else {
  echo '<form method="POST">
          <span style="font-weight: bold; font-size: 14px;">Entr&eacute;e des membres</span><br />
          <label for="email">&gt; Nom usager : </label><input type="text" id="email" name="email" style="padding-left: 5px; padding-right: 10px; width: 150px;" />
          <label for="passwd">&gt; Mot de passe : </label><input type="password" id="passwd" name="passwd" style="width: 100px;" />
          <input type="submit" id="login" class="button" value="Soumettre" />
          <a style="border-left: 1px solid black; color: black; padding-left: 5px; margin-left: 5px;" href="javascript:void(0);">Mot de passe oubli&eacute ?</a>';
  if($erreur) {
    echo '<br /><span style="color: red;">'.$erreur.'<span>';	
  }
        
  echo '</form>';
}

?>