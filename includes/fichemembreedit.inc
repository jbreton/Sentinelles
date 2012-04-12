<?php

if(!$membre) {
	include('accueil.inc');
        return false;
}

   $my_mysql = new MySQL();
   $id_membre = $_GET['idmembre'];
   if($id_membre == "") {
     	$id_membre = $membre->id_membre;
   }

   if ($id_membre != "")
   {
      $membre_fiche = new Membre($my_mysql, $id_membre);
   }
   else
   {
      echo "Membre invalide".$id_membre;
      $membre_fiche = new Membre($my_mysql, $membre->id_membre);
   }

   $mes_infos = $membre_fiche->id_membre == $membre->id_membre;

   if ($mes_infos)
   {
      echo "<h1>Ma fiche</h1>";
   }
   else if(!$membre->EstCA()) {
      include('accueil.inc');	
      return false;
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
	<form enctype='multipart/form-data' action='processmodif.php' method='post' onsubmit="return valider()">
<script type="text/javascript">function valider() {
var nom = document.getElementById("nom");
var prenom = document.getElementById('prenom');
var tel = document.getElementById("telephone");

if(nom.value == "") {
	alert('Vous devez entrer votre nom');
        return false;
}

if(prenom.value == "") {
	alert('Vous devez entrer votre pr�nom');
        return false;
}

if(tel.value != '') {
	alert('Vous devez entrer votre num�ro de t�l�phone');
        return false;
}

return true;

}</script>
<input type="hidden" readonly name="Nomembre" value="<?php echo $membre_fiche->id_membre; ?>" size="4" />
   <table>
   <tr/>
            <td>Prenom <span style="color: red; font-weight: bold;">*</span> :</td>
            <td><input type="text" name="Prenom" id="prenom" value="<?php echo $membre_fiche->prenom; ?>" size="15" /></td>
         </tr>
         <tr>
            <td>Nom <span style="color: red; font-weight: bold;">*</span> :</td><td><input id="nom" type="text" name="Nom" value="<?php echo $membre_fiche->nom; ?>" size="15" /></td>
         </tr>
         <tr>
            <td>Date de naissance :</td>
				<td><select name="Anneenaissance">
               <?php 
                  $annee = substr($membre_fiche->date_naissance,0,4);
                  if ($annee == "2000")
						   echo '<option selected value="2000">2000</option>';
                  else
                  	echo '<option value="2000">2000</option>';

                  if ($annee == "1999")
						   echo '<option selected value="1999">1999</option>';
                  else
						   echo '<option value="1999">1999</option>';

                  if ($annee == "1998")
						   echo '<option selected value="1998">1998</option>';
                  else
                  	echo '<option value="1998">1998</option>';

                  if ($annee == "1997")
						   echo '<option selected value="1997">1997</option>';
                  else
                  	echo '<option value="1997">1997</option>';

                  if ($annee == "1996")
						   echo '<option selected value="1996">1996</option>';
                  else
                  	echo '<option value="1996">1996</option>';

                  if ($annee == "1995")
						   echo '<option selected value="1995">1995</option>';
                  else
                  	echo '<option value="1995">1995</option>';

                  if ($annee == "1994")
						   echo '<option selected value="1994">1994</option>';
                  else
                  	echo '<option value="1994">1994</option>';

                  if ($annee == "1993")
						   echo '<option selected value="1993">1993</option>';
                  else
                  	echo '<option value="1993">1993</option>';

                  if ($annee == "1992")
						   echo '<option selected value="1992">1992</option>';
                  else
                  	echo '<option value="1992">1992</option>';

                  if ($annee == "1991")
						   echo '<option selected value="1991">1991</option>';
                  else
                  	echo '<option value="1991">1991</option>';

                  if ($annee == "1990")
						   echo '<option selected value="1990">1990</option>';
                  else
                  	echo '<option value="1990">1990</option>';

                  if ($annee == "1989")
						   echo '<option selected value="1989">1989</option>';
                  else
                  	echo '<option value="1989">1989</option>';

                  if ($annee == "1988")
						   echo '<option selected value="1988">1988</option>';
                  else
                  	echo '<option value="1988">1988</option>';

                  if ($annee == "1987")
						   echo '<option selected value="1987">1987</option>';
                  else
                  	echo '<option value="1987">1987</option>';

                  if ($annee == "1986")
						   echo '<option selected value="1986">1986</option>';
                  else
                  	echo '<option value="1986">1986</option>';

                  if ($annee == "1985")
						   echo '<option selected value="1985">1985</option>';
                  else
                  	echo '<option value="1985">1985</option>';

                  if ($annee == "1984")
						   echo '<option selected value="1984">1984</option>';
                  else
                  	echo '<option value="1984">1984</option>';

                  if ($annee == "1983")
						   echo '<option selected value="1983">1983</option>';
                  else
                  	echo '<option value="1983">1983</option>';

                  if ($annee == "1982")
						   echo '<option selected value="1982">1982</option>';
                  else
                  	echo '<option value="1982">1982</option>';

                  if ($annee == "1981")
						   echo '<option selected value="1981">1981</option>';
                  else
                  	echo '<option value="1981">1981</option>';

                  if ($annee == "1980")
						   echo '<option selected value="1980">1980</option>';
                  else
						   echo '<option value="1980">1980</option>';

                  if ($annee == "1979")
						   echo '<option selected value="1979">1979</option>';
                  else
                  	echo '<option value="1979">1979</option>';

                  if ($annee == "1978")
						   echo '<option selected value="1978">1978</option>';
                  else
                  	echo '<option value="1978">1978</option>';

                  if ($annee == "1977")
						   echo '<option selected value="1977">1977</option>';
                  else
                  	echo '<option value="1977">1977</option>';

                  if ($annee == "1976")
						   echo '<option selected value="1976">1976</option>';
                  else
                  	echo '<option value="1976">1976</option>';

                  if ($annee == "1975")
						   echo '<option selected value="1975">1975</option>';
                  else
                  	echo '<option value="1975">1975</option>';

                  if ($annee == "1974")
						   echo '<option selected value="1974">1974</option>';
                  else
                  	echo '<option value="1974">1974</option>';

                  if ($annee == "1973")
						   echo '<option selected value="1973">1973</option>';
                  else
                  	echo '<option value="1973">1973</option>';

                  if ($annee == "1972")
						   echo '<option selected value="1972">1972</option>';
                  else
                  	echo '<option value="1972">1972</option>';

                  if ($annee == "1971")
						   echo '<option selected value="1971">1971</option>';
                  else
                  	echo '<option value="1971">1971</option>';

                  if ($annee == "1970")
						   echo '<option selected value="1970">1970</option>';
                  else
                  	echo '<option value="1970">1970</option>';

                  if ($annee == "1969")
						   echo '<option selected value="1969">1969</option>';
                  else
                  	echo '<option value="1969">1969</option>';

                  if ($annee == "1968")
						   echo '<option selected value="1968">1968</option>';
                  else
                  	echo '<option value="1968">1968</option>';

                  if ($annee == "1967")
						   echo '<option selected value="1967">1967</option>';
                  else
                  	echo '<option value="1967">1967</option>';

                  if ($annee == "1966")
						   echo '<option selected value="1966">1966</option>';
                  else
                  	echo '<option value="1966">1966</option>';

                  if ($annee == "1965")
						   echo '<option selected value="1965">1965</option>';
                  else
                  	echo '<option value="1965">1965</option>';

                  if ($annee == "1964")
						   echo '<option selected value="1964">1964</option>';
                  else
                  	echo '<option value="1964">1964</option>';

                  if ($annee == "1963")
						   echo '<option selected value="1963">1963</option>';
                  else
                  	echo '<option value="1963">1963</option>';

                  if ($annee == "1962")
						   echo '<option selected value="1962">1962</option>';
                  else
                  	echo '<option value="1962">1962</option>';

                  if ($annee == "1961")
						   echo '<option selected value="1961">1961</option>';
                  else
						   echo '<option value="1961">1961</option>';

                  if ($annee == "1960")
						   echo '<option selected value="1960">1960</option>';
                  else
                  	echo '<option value="1960">1960</option>';

                  if ($annee == "1959")
						   echo '<option selected value="1959">1959</option>';
                  else
                  	echo '<option value="1959">1959</option>';

                  if ($annee == "1958")
						   echo '<option selected value="1958">1958</option>';
                  else
                  	echo '<option value="1958">1958</option>';

                  if ($annee == "1957")
						   echo '<option selected value="1957">1957</option>';
                  else
                  	echo '<option value="1957">1957</option>';

                  if ($annee == "1956")
						   echo '<option selected value="1956">1956</option>';
                  else
                  	echo '<option value="1956">1956</option>';

                  if ($annee == "1955")
						   echo '<option selected value="1955">1955</option>';
                  else
                  	echo '<option value="1955">1955</option>';

                  if ($annee == "1954")
						   echo '<option selected value="1954">1954</option>';
                  else
                  	echo '<option value="1954">1954</option>';

                  if ($annee == "1953")
						   echo '<option selected value="1953">1953</option>';
                  else
                  	echo '<option value="1953">1953</option>';

                  if ($annee == "1952")
						   echo '<option selected value="1952">1952</option>';
                  else
                  	echo '<option value="1952">1952</option>';

                  if ($annee == "1951")
						   echo '<option selected value="1951">1951</option>';
                  else
                  	echo '<option value="1951">1951</option>';

                  if ($annee == "1950")
						   echo '<option selected value="1950">1950</option>';
                  else
                  	echo '<option value="1950">1950</option>';

                  if ($annee == "1949")
						   echo '<option selected value="1949">1949</option>';
                  else
                  	echo '<option value="1949">1949</option>';

                  if ($annee == "1948")
						   echo '<option selected value="1948">1948</option>';
                  else
                  	echo '<option value="1948">1948</option>';

                  if ($annee == "1947")
						   echo '<option selected value="1947">1947</option>';
                  else
                  	echo '<option value="1947">1947</option>';

                  if ($annee == "1946")
						   echo '<option selected value="1946">1946</option>';
                  else
                  	echo '<option value="1946">1946</option>';

                  if ($annee == "1945")
						   echo '<option selected value="1945">1945</option>';
                  else
                  	echo '<option value="1945">1945</option>';

                  if ($annee == "1944")
						   echo '<option selected value="1944">1944</option>';
                  else
                  	echo '<option value="1944">1944</option>';

                  if ($annee == "1943")
						   echo '<option selected value="1943">1943</option>';
                  else
                  	echo '<option value="1943">1943</option>';

                  if ($annee == "1942")
						   echo '<option selected value="1942">1942</option>';
                  else
						   echo '<option value="1942">1942</option>';

                  if ($annee == "1941")
						   echo '<option selected value="1941">1941</option>';
                  else
                  	echo '<option value="1941">1941</option>';

                  if ($annee == "1940")
						   echo '<option selected value="1940">1940</option>';
                  else
                  	echo '<option value="1940">1940</option>';

                  if ($annee == "1939")
						   echo '<option selected value="1939">1939</option>';
                  else
                  	echo '<option value="1939">1939</option>';

                  if ($annee == "1938")
						   echo '<option selected value="1938">1938</option>';
                  else
                  	echo '<option value="1938">1938</option>';

                  if ($annee == "1937")
						   echo '<option selected value="1937">1937</option>';
                  else
                  	echo '<option value="1937">1937</option>';

                  if ($annee == "1936")
						   echo '<option selected value="1936">1936</option>';
                  else
                  	echo '<option value="1936">1936</option>';

                  if ($annee == "1935")
						   echo '<option selected value="1935">1935</option>';
                  else
                  	echo '<option value="1935">1935</option>';

                  if ($annee == "1934")
						   echo '<option selected value="1934">1934</option>';
                  else
                  	echo '<option value="1934">1934</option>';

                  if ($annee == "1933")
						   echo '<option selected value="1933">1933</option>';
                  else
                  	echo '<option value="1933">1933</option>';

                  if ($annee == "1932")
						   echo '<option selected value="1932">1932</option>';
                  else
                  	echo '<option value="1932">1932</option>';

                  if ($annee == "1931")
						   echo '<option selected value="1931">1931</option>';
                  else
                  	echo '<option value="1931">1931</option>';

                  if ($annee == "1930")
						   echo '<option selected value="1930">1930</option>';
                  else
                  	echo '<option value="1930">1930</option>';

                  if ($annee == "1929")
						   echo '<option selected value="1929">1929</option>';
                  else
                  	echo '<option value="1929">1929</option>';

                  if ($annee == "1928")
						   echo '<option selected value="1928">1928</option>';
                  else
                  	echo '<option value="1928">1928</option>';

                  if ($annee == "1927")
						   echo '<option selected value="1927">1927</option>';
                  else
                  	echo '<option value="1927">1927</option>';

                  if ($annee == "1926")
						   echo '<option selected value="1926">1926</option>';
                  else
                  	echo '<option value="1926">1926</option>';

                  if ($annee == "1925")
						   echo '<option selected value="1925">1925</option>';
                  else
                  	echo '<option value="1925">1925</option>';

                  if ($annee == "1924")
						   echo '<option selected value="1924">1924</option>';
                  else
                  	echo '<option value="1924">1924</option>';

                  if ($annee == "1923")
						   echo '<option selected value="1923">1923</option>';
                  else
						   echo '<option value="1923">1923</option>';

                  if ($annee == "1922")
						   echo '<option selected value="1922">1922</option>';
                  else
                  	echo '<option value="1922">1922</option>';

                  if ($annee == "1921")
						   echo '<option selected value="1921">1921</option>';
                  else
                  	echo '<option value="1921">1921</option>';

                  if ($annee == "1920")
						   echo '<option selected value="1920">1920</option>';
                  else
                  	echo '<option value="1920">1920</option>';

                  ?>
					</select>
					<select name="Moisnaissance">
               <?php 
                  $mois = substr($membre_fiche->date_naissance,5,2);
                  if ($mois == "01")
						   echo '<option selected value="01">Janvier</option>';
                  else
                  	echo '<option value="01">Janvier</option>';

                  if ($mois == "02")
						   echo '<option selected value="02">F&eacute;vrier</option>';
                  else
						   echo '<option value="02">F&eacute;vrier</option>';

                  if ($mois == "03")
						   echo '<option selected value="03">Mars</option>';
                  else
                  	echo '<option value="03">Mars</option>';

                  if ($mois == "04")
						   echo '<option selected value="04">Avril</option>';
                  else
                  	echo '<option value="04">Avril</option>';

                  if ($mois == "05")
						   echo '<option selected value="05">Mai</option>';
                  else
                  	echo '<option value="05">Mai</option>';

                  if ($mois == "06")
						   echo '<option selected value="06">Juin</option>';
                  else
                  	echo '<option value="06">Juin</option>';

                  if ($mois == "07")
						   echo '<option selected value="07">Juillet</option>';
                  else
                  	echo '<option value="07">Juillet</option>';

                  if ($mois == "08")
						   echo '<option selected value="08">Août</option>';
                  else
                  	echo '<option value="08">Août</option>';

                  if ($mois == "09")
						   echo '<option selected value="09">Septembre</option>';
                  else
                  	echo '<option value="09">Septembre</option>';

                  if ($mois == "10")
						   echo '<option selected value="10">Octobre</option>';
                  else
                  	echo '<option value="10">Octobre</option>';

                  if ($mois == "11")
						   echo '<option selected value="11">Novembre</option>';
                  else
                  	echo '<option value="11">Novembre</option>';

                  if ($mois == "12")
						   echo '<option selected value="12">D&eacute;cembre</option>';
                  else
                  	echo '<option value="12">D&eacute;cembre</option>';
                  ?>
					</select>
					<select name="Journaissance">
               <?php 
                  $jour = substr($membre_fiche->date_naissance,8,2);
                  if ($jour == "01")
						   echo '<option selected value="01">01</option>';
                  else
                  	echo '<option value="01">01</option>';

                  if ($jour == "02")
						   echo '<option selected value="02">02</option>';
                  else
						   echo '<option value="02">02</option>';

                  if ($jour == "03")
						   echo '<option selected value="03">03</option>';
                  else
                  	echo '<option value="03">03</option>';

                  if ($jour == "04")
						   echo '<option selected value="04">04</option>';
                  else
                  	echo '<option value="04">04</option>';

                  if ($jour == "05")
						   echo '<option selected value="05">05</option>';
                  else
                  	echo '<option value="05">05</option>';

                  if ($jour == "06")
						   echo '<option selected value="06">06</option>';
                  else
                  	echo '<option value="06">06</option>';

                  if ($jour == "07")
						   echo '<option selected value="07">07</option>';
                  else
                  	echo '<option value="07">07</option>';

                  if ($jour == "08")
						   echo '<option selected value="08">08</option>';
                  else
                  	echo '<option value="08">08</option>';

                  if ($jour == "09")
						   echo '<option selected value="09">09</option>';
                  else
                  	echo '<option value="09">09</option>';

                  if ($jour == "10")
						   echo '<option selected value="10">10</option>';
                  else
                  	echo '<option value="10">10</option>';

                  if ($jour == "11")
						   echo '<option selected value="11">11</option>';
                  else
                  	echo '<option value="11">11</option>';

                  if ($jour == "12")
						   echo '<option selected value="12">12</option>';
                  else
                  	echo '<option value="12">12</option>';

                  if ($jour == "13")
						   echo '<option selected value="13">13</option>';
                  else
                  	echo '<option value="13">13</option>';

                  if ($jour == "14")
						   echo '<option selected value="14">14</option>';
                  else
                  	echo '<option value="14">14</option>';

                  if ($jour == "15")
						   echo '<option selected value="15">15</option>';
                  else
                  	echo '<option value="15">15</option>';

                  if ($jour == "16")
						   echo '<option selected value="16">16</option>';
                  else
                  	echo '<option value="16">16</option>';

                  if ($jour == "17")
						   echo '<option selected value="17">17</option>';
                  else
                  	echo '<option value="17">17</option>';

                  if ($jour == "18")
						   echo '<option selected value="18">18</option>';
                  else
                  	echo '<option value="18">18</option>';

                  if ($jour == "19")
						   echo '<option selected value="19">19</option>';
                  else
                  	echo '<option value="19">19</option>';

                  if ($jour == "20")
						   echo '<option selected value="20">20</option>';
                  else
                  	echo '<option value="20">20</option>';

                  if ($jour == "21")
						   echo '<option selected value="21">21</option>';
                  else
                  	echo '<option value="21">21</option>';

                  if ($jour == "22")
						   echo '<option selected value="22">22</option>';
                  else
                  	echo '<option value="22">22</option>';

                  if ($jour == "23")
						   echo '<option selected value="23">23</option>';
                  else
                  	echo '<option value="23">23</option>';

                  if ($jour == "24")
						   echo '<option selected value="24">24</option>';
                  else
                  	echo '<option value="24">24</option>';

                  if ($jour == "25")
						   echo '<option selected value="25">25</option>';
                  else
                  	echo '<option value="25">25</option>';

                  if ($jour == "26")
						   echo '<option selected value="26">26</option>';
                  else
                  	echo '<option value="26">26</option>';

                  if ($jour == "27")
						   echo '<option selected value="27">27</option>';
                  else
                  	echo '<option value="27">27</option>';

                  if ($jour == "28")
						   echo '<option selected value="28">28</option>';
                  else
                  	echo '<option value="28">28</option>';

                  if ($jour == "29")
						   echo '<option selected value="29">29</option>';
                  else
                  	echo '<option value="29">29</option>';

                  if ($jour == "30")
						   echo '<option selected value="30">30</option>';
                  else
                  	echo '<option value="30">30</option>';

                  if ($jour == "31")
						   echo '<option selected value="31">31</option>';
                  else
                  	echo '<option value="31">31</option>';
                  ?>

					</select></td>
         </tr>
         <tr>
            <td>Numero assurance maladie :</td><td><input type="text" name="Noassmaladie" value="<?php echo $membre_fiche->no_assurance_maladie; ?>" size="15" /></td>
         </tr>
         <tr>
            <td colspan="2"><br /></td>
         </tr>
         <tr>
            <td>Courriel :</td><td><input type="text" name="Courriel" readonly="readonly" value="<?php echo $membre_fiche->courriel; ?>" size="30" /></td>
         </tr>
         <tr>
            <td style="vertical-align: top;">Addresse :</td>
            <td><input type="text" name="Adresse" value="<?php echo $membre_fiche->adresse; ?>" size="30" /></td>
         </tr>
         <tr>
            <td style="vertical-align: top;">Ville :</td>
            <td><input type="text" name="Ville" value="<?php echo $membre_fiche->ville; ?>" size="30" /></td>
         </tr>
         <tr>
            <td style="vertical-align: top;">Code postal :</td>
            <td><input type="text" name="CodePostal" value="<?php echo $membre_fiche->code_postal; ?>" size="30" /></td>
         </tr>
         <tr>
            <td>Residence<span style="color: red">*</span> :</td><td><input type="text" name="Telephonedomicile" value="<?php echo $membre_fiche->telephone_residence; ?>" size="15" /></td>
         </tr>
         <tr>
            <td>Bureau :</td><td><input type="text" name="Telephonebureau" value="<?php echo $membre_fiche->telephone_bureau; ?>" size="15" /></td>
         </tr>
         <tr>
            <td>Autre :</td><td><input type="text" name="Autretelephone" value="<?php echo $membre_fiche->telephone_autre; ?>" size="15" /></td>
         </tr>
         <tr>
            <td colspan="2"><br /></td>
         </tr>
         <tr>
            <td>Permettre aux membres de voir mes coordonnees :</td><td><input type="checkbox" name="Coordpublic" 
            <?php
               if ($membre_fiche->coord_public)
               {
                  echo "checked";
               }
            ?>
            /></td>

         </tr>

         <tr><td>Vitesse :</td>
            <td>
            <select name="Groupedevitesse">
               <?php 
                  if ($membre_fiche->groupe_vitesse == 18)
						   echo '<option selected value="18">18 km/h</option>';
                  else
                  	echo '<option value="18">18 km/h</option>';

                  if ($membre_fiche->groupe_vitesse == 20)
						   echo '<option selected value="20">20 km/h</option>';
                  else
						   echo '<option value="20">20 km/h</option>';

                  if ($membre_fiche->groupe_vitesse == 22)
						   echo '<option selected value="22">22 km/h</option>';
                  else
                  	echo '<option value="22">22 km/h</option>';

                  if ($membre_fiche->groupe_vitesse == 25)
						   echo '<option selected value="25">25 km/h</option>';
                  else
                  	echo '<option value="25">25 km/h</option>';

                  if ($membre_fiche->groupe_vitesse == 28)
						   echo '<option selected value="28">28 km/h</option>';
                  else
                  	echo '<option value="28">28 km/h</option>';

                  if ($membre_fiche->groupe_vitesse == 30)
						   echo '<option selected value="30">30 km/h</option>';
                  else
                  	echo '<option value="30">30 km/h</option>';

                  if ($membre_fiche->groupe_vitesse == 32)
						   echo '<option selected value="32">32 km/h</option>';
                  else
                  	echo '<option value="32">32 km/h</option>';

                  if ($membre_fiche->groupe_vitesse == 35)
						   echo '<option selected value="35">35 km/h</option>';
                  else
                  	echo '<option value="35">35 km/h</option>';
                  ?>
				</select>
            </td>
         
         </tr>
         
         <tr>
            <td>Grandeur de maillot :</td>
				<td><select name="maillot">
               <?php 
                  if ($membre_fiche->maillot_grandeur == "XSmall")
						   echo '<option selected value="XSmall">X-Small (Femme)</option>';
                  else
                  	echo '<option value="XSmall">X-Small (Femme)</option>';

                  if ($membre_fiche->maillot_grandeur == "Petit(femme)")
						   echo '<option selected value="Petit(femme)">Petit (Femme)</option>';
                  else
						   echo '<option value="Petit(femme)">Petit (Femme)</option>';

                  if ($membre_fiche->maillot_grandeur == "Petit(homme)")
						   echo '<option selected value="Petit(homme)">Petit (Homme)</option>';
                  else
                  	echo '<option value="Petit(homme)">Petit (Homme)</option>';

                  if ($membre_fiche->maillot_grandeur == "Medium(femme)")
						   echo '<option selected value="Medium(femme)">M&eacute;dium (Femme)</option>';
                  else
                  	echo '<option value="Medium(femme)">M&eacute;dium (Femme)</option>';

                  if ($membre_fiche->maillot_grandeur == "Medium(homme)")
						   echo '<option selected value="Medium(homme)">M&eacute;dium (Homme)</option>';
                  else
                  	echo '<option value="Medium(homme)">M&eacute;dium (Homme)</option>';

                  if ($membre_fiche->maillot_grandeur == "Large(femme)")
						   echo '<option selected value="Large(femme)">Large (Femme)</option>';
                  else
                  	echo '<option value="Large(femme)">Large (Femme)</option>';

                  if ($membre_fiche->maillot_grandeur == "Large(homme)")
						   echo '<option selected value="Large(homme)">Large (Homme)</option>';
                  else
                  	echo '<option value="Large(homme)">Large (Homme)</option>';

                  if ($membre_fiche->maillot_grandeur == "XLarge(femme)")
						   echo '<option selected value="XLarge(femme)">X-Large (Femme)</option>';
                  else
                  	echo '<option value="XLarge(femme)">X-Large (Femme)</option>';

                  if ($membre_fiche->maillot_grandeur == "XLarge(homme)")
						   echo '<option selected value="XLarge(homme)">X-Large (Homme)</option>';
                  else
                  	echo '<option value="XLarge(homme)">X-Large (Homme)</option>';

                  if ($membre_fiche->maillot_grandeur == "2XLarge(homme)")
						   echo '<option selected value="2XLarge(homme)">2X-Large (Homme)</option>';
                  else
                  	echo '<option value="2XLarge(homme)">2X-Large (Homme)</option>';

                  if ($membre_fiche->maillot_grandeur == "3XLarge(homme)")
						   echo '<option selected value="3XLarge(homme)">3X-Large (Homme)</option>';
                  else
                  	echo '<option value="3XLarge(homme)">3X-Large (Homme)</option>';
                  ?>
					</select></td>
         </tr>


         <?php 
            if ($membre->EstCA())
            {
               echo "<tr><td>Maillot remis :</td><td><input type=\"checkbox\" name=\"Maillotremis\" ";
               if ($membre_fiche->maillot_remis)
               {
                  echo "checked";
               }
               echo "/></td></tr>";

               echo "<tr><td>Dossard remis :</td><td><input type=\"checkbox\" name=\"Dossardremis\" ";
               if ($membre_fiche->dossard_remis)
               {
                  echo "checked";
               }
               echo "/></td></tr>";

                $query = 'SELECT cotisation, cotisation_payee, date_paye, nb_encadrements, formulaire_recu FROM inscription INNER JOIN saison ON saison.id_saison = inscription.id_saison WHERE saison.active = "Y" AND id_membre = '.$id_membre.';';
                $result = $my_mysql->Query($query);
                $row = $result->fetch_assoc();
                $result->close();

                echo '<tr><td>Nb encadrements<br /> la saison pr&eacute;c&eacute;dente</td><td>'.$row['nb_encadrements'].'</td></tr>';
                echo '<tr><td>Cotisation</td><td><input type="text" size=4 name="cotisation" id="cotisation" value="'.$row['cotisation'].'" /> $</td></tr>';
                echo '<tr><td>Cotisation pay&eacute;e</td><td><select id="cotisation_payee" name="cotisation_payee"><option value="Y" '.($row['cotisation_payee'] == 'Y' ? 'selected="selected"' : '').'>Oui</option><option value="N" '.($row['cotisation_payee'] != 'Y' ? 'selected="selected"' : '').'>Non</option></select></td></tr>';
                echo '<tr><td>Date paiement</td><td><input type="text" id="date_paye" name="date_paye" value="'.$row['date_paye'].'" /><script type="text/javascript">$(function(){ var min = new Date(); min.setDate(1); min.setMonth(0); var max = new Date(); max.setMonth(11); max.setDate(31); $("#date_paye").datepicker({minDate : min, maxDate : max, monthNames: [\'Janvier\',\'F&eacute;vrier\',\'Mars\',\'Avril\',\'Mai\',\'Juin\',\'Juillet\',\'Ao&ucirc;t\',\'Septembre\',\'Octobre\',\'Novembre\',\'Decembre\'], dateFormat : "yy-mm-dd", dayNamesMin: [\'Di\', \'Lu\', \'Ma\', \'Me\', \'Je\', \'Ve\', \'Sa\']}); });</script></td></tr>';
                echo '<tr><td>Formulaire recu</td><td><select id="formulaire_recu" name="formulaire_recu"><option value="Y" '.($row['formulaire_recu'] == 'Y' ? 'selected="selected"' : '').'>Oui</option><option value="N" '.($row['formulaire_recu'] != 'Y' ? 'selected="selected"' : '').'>Non</option></select></td></tr>';
            }
         ?>

         <tr><td colspan="2"><br /></td></tr>

         <tr><td colspan="2">Coordonnees en cas d'urgence</td></tr>
         <tr><td>Nom :</td><td><input type="text" name="Personneurgence" value="<?php echo $membre_fiche->urgence_nom; ?>" /></td></tr>
         <tr>
            <td>Lien :</td>
         	<td><select name="Lien">
               <?php 
                  if ($membre_fiche->urgence_lien == "Conjoint(e)")
						   echo '<option selected value="Conjoint(e)">Conjoint(e)</option>';
                  else
                  	echo '<option value="Conjoint(e)">Conjoint(e)</option>';

                  if ($membre_fiche->urgence_lien == "Pere")
						   echo '<option selected value="Pere">Pere</option>';
                  else
						   echo '<option value="Pere">Pere</option>';

                  if ($membre_fiche->urgence_lien == "Mere")
						   echo '<option selected value="Mere">Mere</option>';
                  else
                  	echo '<option value="Mere">Mere</option>';

                  if ($membre_fiche->urgence_lien == "Frere")
						   echo '<option selected value="Frere">Frere</option>';
                  else
                  	echo '<option value="Frere">Frere</option>';

                  if ($membre_fiche->urgence_lien == "Soeur")
						   echo '<option selected value="Soeur">Soeur</option>';
                  else
                  	echo '<option value="Soeur">Soeur</option>';

                  if ($membre_fiche->urgence_lien == "Ami(e)")
						   echo '<option selected value="Ami(e)">Ami(e)</option>';
                  else
                  	echo '<option value="Ami(e)">Ami(e)</option>';

                  if ($membre_fiche->urgence_lien == "Autre")
						   echo '<option selected value="Autre">Autre</option>';
                  else
                  	echo '<option value="Autre">Autre</option>';
     	         ?>

					</select></td>
			</tr>
			<tr>
				<td>T&eacute;l&eacute;phone domicile du contact en cas d'urgence:</td>
				<td><input type=text name="Telephonedomicilepersonne" size=30 value="<?php echo $membre_fiche->urgence_tel_res; ?>"></td>
			</tr>
			<tr>
				<td>T&eacute;l&eacute;phone bureau du contact en cas d'urgence:</td>
				<td><input type=text name="Telephonebureaupersonne" size=30 value="<?php echo $membre_fiche->urgence_tel_bur; ?>"></td>
			</tr>
			<tr>
				<td>Autre t&eacute;l&eacute;phone du contact en cas d'urgence:</td>
				<td><input type=text name="Telephoneautrepersonne" size=30 value="<?php echo $membre_fiche->urgence_tel_autre; ?>"></td>
			</tr>
		</table>
		<input type="submit" value="Enregistrer"><input type="button" value="Annuler" onclick="history.back();" />
		
	</div>                  	