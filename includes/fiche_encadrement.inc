<?php


$query = 'SELECT * FROM activite WHERE id_activite = '.(int)$_GET['id'];
$result = $session->MySQL()->Query($query);
$row = $result->fetch_assoc();
$result->close();

if(!$row) {
	include('acceuil.inc');
        return false;
}

echo '<h2>'.htmlentities($row['nom_activite']).'</h2>';

if($row['organisme'] != '') {
        echo '<p><b>Organisme</b> : ';
        if($row['lien_organisme'] != '') {
	       echo '<a href="'.(!preg_match('/http(|s):\/\//', $row['lien_organisme']) ? 'http://' : '').$row['lien_organisme'].'" style="color: black;" target="_blank">';
        }
        echo htmlentities($row['organisme']);
        if($row['lien_organisme'] != '') {
	       echo '</a>';
        }
        echo '</p>';
}

if($row['description'] != '') {
        echo '<p><b>Description</b> : '.htmlentities($row['description']).'</p>';
}

if($row['lieu_depart'] != '') {
	echo '<p><b style="font-size: smaller;">Lieu de depart : </b>';
        if($row['lien_lieu_depart'] != '')
              echo '<a style="color:black;" href="'.(!preg_match('/http(|s):\/\//', $row['lien_lieu_depart']) ? 'http://' : '').htmlentities($row['lien_lieu_depart']).'" target="_blank">'.htmlentities($row['lieu_depart']).'</a>';
        else 
              echo htmlentities($row['lieu_depart']);
        echo '</p>';
}

if($row['trajet_desc'] != '') {
        echo '<p><b>Trajet : </b>'.htmlentities($row['trajet_desc']);
        if($row['lien_trajet'] != '')
             echo '<br /><a href="'.(!preg_match('/http(|s):\/\//', $row['lien_trajet']) ? 'http://' : '').htmlentities($row['lien_trajet']).'" style="color: black;" target="_blank">Voir le trajet</a>';
        echo '</p>';
}

if($row['autres_infos'] != '') {
	echo stripslashes($row['autres_infos']);
}

if($row['inscription_ouverte'] == 'Y' || $membre->id_membre == 85) {
        echo '<br /><br />L\'inscription pour cet encadrement est ouverte, il est important de nous confirmer votre pr&eacute;sence le plus t&ocirc;t possible.<br />';
        
        echo '<form method="POST" action="processencadre.php">';


        $query = 'SELECT id_groupe_vitesse, description FROM groupe_vitesse WHERE id_activite = '.$row['id_activite'];
        $result_groupe = $session->MySQL()->Query($query);
        $sub_row_groupe = $result_groupe->fetch_assoc();

        if ($membre)
        {
            $query = 'SELECT id_presence, participation, id_groupe_vitesse_demande FROM presence WHERE id_activite = '.$row['id_activite'].' AND id_membre = '.$membre->id_membre;
            $result = $session->MySQL()->Query($query);
            $sub_row = $result->fetch_assoc();
            $result->close();                
           echo '<input type="hidden" readonly name="Nomembre" value="'. $membre->id_membre . '" size="4" />';
        }
        else
        {
           echo '<input type="hidden" readonly name="Nomembre" value="" size="4" />';
        }

        echo '<input type="hidden" readonly name="Noactivite" value=" '. $row['id_activite'] . '" size="4" />';

        if($sub_row) 
        {

            echo '<input type="hidden" readonly name="Nopresence" value=" '. $sub_row['id_presence'] . '" size="4" />';


            echo "<br />Je serai pr&eacute;sent:<font color='#ff0000'>*</font>";
            
            
            if ($sub_row['participation'] == "Y")
   			   echo "<label><input type='radio' checked name='Present' value='Y'>Oui</label><label><input type='radio' name='Present' value='N'>Non</label>";
            else
              	echo "<label><input type='radio' name='Present' value='Y'>Oui</label><label><input type='radio' checked name='Present' value='N'>Non</label>";
            

            if($sub_row_groupe) {
                echo '<br />Quel est votre pr&eacute;f&eacute;rence parmis ces parcours : <select id="" name="choix_groupe_vitesse"><option value="0">Aucune pr&eacute;f&eacute;rence</option>';
                do {
                      echo '<option';
                      
                      if ($sub_row_groupe['id_groupe_vitesse'] == $sub_row['id_groupe_vitesse_demande'])
                      {
                        echo ' selected ';
                      }
                      
                      echo ' value="'.$sub_row_groupe['id_groupe_vitesse'].'">'.htmlentities($sub_row_groupe['description']);
                      echo '</option>';
                } while($sub_row_groupe = $result_groupe->fetch_assoc());
                echo '</select><br /><br />';
            }

        }
        else 
        {
              echo '<input type="hidden" readonly name="Nopresence" value="" size="4" />';


              if(!$membre) {
                  echo '<br />Prenom : <input type="text" name="Prenom" id="prenom" value="" size="15" />';
                  echo '<br />Nom : <input type="text" name="Nom" id="nom" value="" size="15" />';
               }


              echo "<br />Je serai pr&eacute;sent:<font color='#ff0000'>*</font><label><input type='radio' name='Present' value='Y'>Oui</label><label><input type='radio' name='Present' value='N'>Non</label>";

              if($sub_row_groupe) {
                   echo '<br />Quel est votre pr&eacute;f&eacute;rence parmis ces parcours : <select id="" name="choix_groupe_vitesse"><option value="0">Aucune pr&eacute;f&eacute;rence</option>';
                   do {
                         echo '<option value="'.$sub_row_groupe['id_groupe_vitesse'].'">'.htmlentities($sub_row_groupe['description']).'</option>';
                   } while($sub_row_groupe = $result_groupe->fetch_assoc());
                   echo '</select><br /><br />';
              }
        }

        $result_groupe->close();

        echo '<input type="submit" value="Confirmer mon choix" /><input type="button" value="Annuler" /></form>';  

        
}
if ($membre && $membre->EstCA()) {
	   echo '<br /><br /><input type="button" value="Imprimer la grille des presences" onclick="window.open(\'/grille_presences.php?id='.$row['id_activite'].'\', \'_blank\');" />
<br /><input type="button" value="Mettre a jour les presences" onclick="window.open(\'/liste_presences.php?id='.$row['id_activite'].'\', \'_blank\');" />';
        }

?>