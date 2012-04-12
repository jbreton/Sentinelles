<?php 

if(!$membre) {
	include('accueil.inc');
        return false;
}

   $my_mysql = new MySQL();
   $id_membre = $_GET['idmembre'];

   if ($id_membre != "")
   {
      $membre_fiche = new Membre($my_mysql, $id_membre);
   }
   else
   {
      $membre_fiche = new Membre($my_mysql, $membre->id_membre);
      $id_membre = $membre->id_membre;
   }

   $mes_infos = $membre_fiche->id_membre == $membre->id_membre;

   if ($mes_infos)
   {
      echo "<h1>Ma fiche</h1>";
   }
?>
      
<div class="textes">

<?php 
   if ($mes_infos)
   {
      echo "<p>Voici vos informations personelles.</p>";
   }
   else
   {
      echo "<p>Voici les informations de " . $membre_fiche->prenom . " " . $membre_fiche->nom . ".</p>";
   }
?>
   

   <table>
      <tbody>

         <tr><td>Prenom :</td><td><?php echo $membre_fiche->prenom; ?></td></tr>
         <tr><td>Nom :</td><td><?php echo $membre_fiche->nom; ?></td></tr>

         <?php 
            if ($membre->EstCA() || $mes_infos)
            {
               echo "<tr><td>Date de naissance :</td><td>" . $membre_fiche->date_naissance . "</td></tr>";
               echo "<tr><td>Numero assurance maladie :</td><td>" . $membre_fiche->no_assurance_maladie . "</td></tr>";
            }
   
            if ($membre->EstCA() || $mes_infos || $membre_fiche->coord_public) {
	       echo '<tr><td colspan="2"><br /></td></tr>
         <tr><td>Courriel :</td><td>'.$membre_fiche->courriel.'</td></tr>
         <tr><td style="vertical-align: top;">Adresse :</td><td>'.$membre_fiche->adresse.'<br />'.$membre_fiche->ville.'<br />'.$membre_fiche->code_postal.'</td></tr>
         <tr><td>Residence :</td><td>'.$membre_fiche->telephone_residence.'</td></tr>
         <tr><td>Bureau :</td><td>'.$membre_fiche->telephone_bureau.'</td></tr>
         <tr><td>Autre :</td><td>'.$membre_fiche->telephone_autre.'</td></tr>
         <tr><td colspan="2"><br /></td></tr>';
}
         ?>
         

         <?php 
            if ($membre->EstCA() || $mes_infos)
            {
               echo "<tr><td>Permettre aux membres de voir mes coordonnees :</td><td>";
               if ($membre_fiche->coord_public)
               {
                  echo "Oui";
               }
               else
               {
                  echo "Non";
               }
               echo "</td></tr>";
            }
         ?>

         <tr><td>Vitesse</td><td><?php echo $membre_fiche->groupe_vitesse; ?> km/h</td></tr>

         <?php 
            if ($membre->EstCA() || $mes_infos)
            {
               echo "<tr><td>Grandeur de maillot</td><td>" . $membre_fiche->maillot_grandeur . "</td></tr>";
            }
         ?>
         
         <?php 
            if ($membre->EstCA())
            {
               echo "<tr><td>Maillot remis</td><td>";
               if ($membre_fiche->maillot_remis)
               {
                  echo "Oui";
               }
               else
               {
                  echo "Non";
               }
               echo "</td></tr>";
               echo "<tr><td>Dossard remis</td><td>";
               if ($membre_fiche->dossard_remis)
               {
                  echo "Oui";
               }
               else
               {
                  echo "Non";
               }
               echo "</td></tr>";
            }
         ?>
        

         <?php 

            if($membre->EstCA()) {
		$query = 'SELECT cotisation, cotisation_payee, date_paye, nb_encadrements, formulaire_recu FROM inscription INNER JOIN saison ON saison.id_saison = inscription.id_saison WHERE saison.active = "Y" AND id_membre = '.$id_membre.';';
                $result = $my_mysql->Query($query);
                $row = $result->fetch_assoc();
                $result->close(); 


                echo '<tr><td>Nb encadrements<br /> la saison pr&eacute;c&eacute;dente</td><td>'.$row['nb_encadrements'].'</td></tr>';
                echo '<tr><td>Cotisation</td><td>'.$row['cotisation'].' $</td></tr>';
                echo '<tr><td>Cotisation pay&eacute;e</td><td>'.($row['cotisation_payee'] == 'Y' ? 'Oui' : 'Non').'</td></tr>';
                if($row['cotisation_payee'] == 'Y') echo '<tr><td>Date paiement</td><td>'.$row['date_payee'].'</td></tr>';
echo '<tr><td>Formulaire recu</td><td>'.($row['formulaire_recu'] == 'Y' ? 'Oui' : 'Non').'</td></tr>';
            }

         ?>

         <?php 
            if ($membre->EstCA() || $mes_infos)
            {
               echo '<tr><td colspan="2"><br /></td></tr>';
               echo "<tr><td colspan=\"2\">Coordonnees en cas d'urgence</td></tr>";
               echo "<tr><td>Nom :</td><td>" . $membre_fiche->urgence_nom . "</td></tr>";
               echo "<tr><td>Lien :</td><td>" . $membre_fiche->urgence_lien . "</td></tr>";
               echo "<tr><td>Residence :</td><td>" . $membre_fiche->urgence_tel_res . "</td></tr>";
               echo "<tr><td>Bureau :</td><td>" . $membre_fiche->urgence_tel_bur . "</td></tr>";
               echo "<tr><td>Autre :</td><td>" . $membre_fiche->urgence_tel_autre . "</td></tr>";
            }
         ?>

      </tbody>
   </table>
   <br />
   <input type="button" value="Retour" onclick="location='liste_membres.php';" />
   <?php 



      if ($membre->EstCA() || $mes_infos)
      {
         echo "<input type=\"button\" value=\"Modifier\" onclick=\"location='fichemembreedit.php?idmembre=" .$membre_fiche->id_membre . "';\" />";
      }

      if($membre->EstCA() && !$membre_fiche->inscription_envoyee) {
           echo '<br /><br /><input type="button" value="Envoyer le courriel d\'inscription" id="send_inscription_email" /><script type="text/javascript">$(\'#send_inscription_email\').click(function() {
	$.get(\'envoyer_inscription.php?id_membre='.$membre_fiche->id_membre.'\', function() {
	alert(\'Le courriel a été envoyé\'); history.back();
});
})</script>';
      }

      if($mes_infos && !$membre_fiche->FormulaireRecu()) {
	echo '<br /><br /><br /><strong><a href="javascript:void(0);" onclick="window.open(\'formulaire_inscription.php\', \'_blank\');" style="color: red;">Cliquez ici</a> pour une version imprimable du formulaire d\'inscription. </strong>
<br /><br />Veuillez imprimer le formulaire en suivant le lien ci-dessus, le signer et nous le faire parvenir &agrave; l\'adresse
suivante pour compl&eacute;ter votre inscription :
<br />
Les Sentinelles de la Route<br />
			C.P. 9802, Succ. postale Sainte-Foy<br />
		Qu&eacute;bec (Qu&eacute;bec)<br />
			G1V 4C3';
      }
   ?>
   <br /><br />

</div>