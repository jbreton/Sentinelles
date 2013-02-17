<?php 

if(!$membre) {
	include('accueil.inc');
        return false;
}

   $my_mysql = new MySQL();
   $id_prospect = $_GET['id'];

   if ($id_prospect != "")
   {
      $prospect = new Prospect($my_mysql, $id_prospect);
   }
   else
   {
      include('accueil.inc');
      return false;
   }
?>
      
<div class="textes">

<?php
   echo "<p>Voici les informations de " . $prospect->prenom . " " . $prospect->nom . ".</p>";
?>
   

   <table>
      <tbody>

         <tr><td>Prenom :</td><td><?php echo $prospect->prenom; ?></td></tr>
         <tr><td>Nom :</td><td><?php echo $prospect->nom; ?></td></tr>

         <?php 
            
               echo "<tr><td>Date de naissance :</td><td>" . $prospect->date_naissance . "</td></tr>";
               echo "<tr><td>Numero assurance maladie :</td><td>" . $prospect->no_assurance_maladie . "</td></tr>";
           
	       echo '<tr><td colspan="2"><br /></td></tr>
         <tr><td>Courriel :</td><td>'.$prospect->courriel.'</td></tr>
         <tr><td style="vertical-align: top;">Adresse :</td><td>'.$prospect->adresse.'<br />'.$prospect->ville.'<br />'.$prospect->code_postal.'</td></tr>
         <tr><td>Residence :</td><td>'.$prospect->telephone_residence.'</td></tr>
         <tr><td>Bureau :</td><td>'.$prospect->telephone_bureau.'</td></tr>
         <tr><td>Autre :</td><td>'.$prospect->telephone_autre.'</td></tr>
         <tr><td colspan="2"><br /></td></tr>';
         ?>
    

         <tr><td>Vitesse</td><td><?php echo $prospect->groupe_vitesse; ?> km/h</td></tr>

         <?php 
               echo "<tr><td>Grandeur de maillot</td><td>" . $prospect->maillot_grandeur . "</td></tr>";
         ?>

         <?php 
           
               echo '<tr><td colspan="2"><br /></td></tr>';
               echo "<tr><td colspan=\"2\">Coordonnees en cas d'urgence</td></tr>";
               echo "<tr><td>Nom :</td><td>" . $prospect->urgence_nom . "</td></tr>";
               echo "<tr><td>Lien :</td><td>" . $prospect->urgence_lien . "</td></tr>";
               echo "<tr><td>Residence :</td><td>" . $prospect->urgence_tel_res . "</td></tr>";
               echo "<tr><td>Bureau :</td><td>" . $prospect->urgence_tel_bur . "</td></tr>";
               echo "<tr><td>Autre :</td><td>" . $prospect->urgence_tel_autre . "</td></tr>";
         ?>

      </tbody>
   </table>
   <br />
   <input type="button" value="Retour" onclick="location='liste_membres.php';" />
   
   <br /><br />

</div>