<?php												
require_once('classes/mysql.inc');
require_once('classes/session.inc');
require_once('classes/membre.inc');

$session = new Session();
if($membre = $session->Start()) {
    $stmt = $session->MySQL()->Prepare('UPDATE membre SET mot_passe = ?'.($_GET['inscrit'] == 'Y' ? ', est_inscrit="Y"' : '').' WHERE id_membre = ?');
    $stmt->bind_param('sd', $_GET['password'], $membre->id_membre);
    $stmt->execute();

    $membre->Refresh($session->MySQL());
    
    $session->Write();
}

echo 'success';