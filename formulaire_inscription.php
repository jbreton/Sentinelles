<?php												

require_once('classes/mysql.inc');
require_once('classes/membre.inc');
require_once('classes/session.inc');

$session = new Session();
if($membre = $session->Start()) {
	echo '<html><body><center><img src="http://www.lessentinelles.com/sentinelles.gif" alt="" width="246" height="69" border="0" /><br />
<h2>Inscription &agrave; la saison 2013</h2></center>
<table><tbody>';

        echo '<tr><td>Nom : </td><td style="border-bottom: 1px solid black; min-width: 200px; margin-bottom: 5px;">'.htmlentities($membre->nom).'</td></tr>';
        echo '</tr><td>Pr&eacute;nom : </td><td style="border-bottom: 1px solid black; min-width: 200px; margin-top: 5px;">'.htmlentities($membre->prenom).'</td></tr>';
        echo '<tr><td>Date de naissance : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->date_naissance).'&nbsp;</td></tr>';
        echo '<tr><td>Assurance maladie : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->no_assurance_maladie).'&nbsp;</td></tr>';

        echo '<tr><td colspan="2"><br /></td></tr>';

        echo '<tr><td>Adresse : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->adresse).'&nbsp;</td></tr>';
        echo '<tr><td>Ville : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->ville).'&nbsp;</td></tr>';
        echo '<tr><td>Code postal : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->code_postal).'&nbsp;</td></tr>';
        echo '<tr><td>T&eacute;l&eacute;phone : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->telephone_residence).'&nbsp;</td></tr>';
        echo '<tr><td>Bureau : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->telephone_bureau).'&nbsp;</td></tr>';
        echo '<tr><td>Autre : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->telephone_autre).'&nbsp;</td></tr>';
        echo '<tr><td>Courriel : </td><td style="border-bottom: 1px solid black; min-width: 200px; padding-top: 5px;">'.htmlentities($membre->courriel).'&nbsp;</td></tr>';
	echo '</tbody></table>';

        echo '<br /><br />Je commande ______ plaque(s) suppl&eacute;mentaire(s) de selle de v&eacute;lo. (2,50$ chacune.  La premi&egrave;re est gratuite.)';

        echo '<br /><br />Je, soussign&eacute;(e), reconnais que la pratique du cyclisme comporte l\'existence de dangers, de risques r&eacute;els de blessures et d\'accident graves. Je d&eacute;clare conna&icirc;tre la nature et l\'&eacute;tendue de ces dangers et de ces risques et j\'accepte, librement et volontairement de les courir. De plus, je d&eacute;gage le club &quot;Les Sentinelles de la Route&quot; et ses repr&eacute;sentants de toute responsabilit&eacute; qui pourrait r&eacute;sulter de la pratique du cyclisme dans le cadre des activit&eacute;s organis&eacute;es par le club &quot;Les Sentinelles de la Route&quot; et ses repr&eacute;sentants.
<br /></br />Signature : _________________________________________________ Date : ______________';
  
        echo '<script type="text/javascript">window.print();</script>';

	echo '</body></html>';
}
else {
    header('Location: /');
}