<?php

class Calendrier {
        private $mysql;
        private $mois;
        private $annee;
		private $annees = array();

	public function __construct(MySQL $mysql, $annee, $mois) {
	     $this->mysql = $mysql;
             $this->type = $type;
             $this->annee = $annee;
			 
			$query = 'SELECT DISTINCT YEAR(date_activite) FROM activite;';
			$result = $mysql->Query($query);
			while($row = $result->fetch_row()) {
				$this->annees[] = $row[0];
			}
			$result->close();
			
			if(!$this->annee) {
				$this->annee = $this->annees[count($this->annees)-1];
			}
			 
             if(!$mois) {
	         $query = 'SELECT MIN(MONTH(date_activite)) FROM activite WHERE YEAR(date_activite) = "'.$this->annee.'" AND MONTH(date_activite) >= MONTH(NOW());';
                 $result = $mysql->Query($query);
                 $row = $result->fetch_row();
                 $this->mois = $row[0];
                 $result->close();
             }
	     else  {
	         $this->mois = $mois;
             }
        }

	public function NomMois($mois) {
		switch($mois) {
			case '1':
				return 'Janvier';
				break;
			case '2':
				return 'F&eacute;vrier';
				break;
			case '3':
				return 'Mars';
				break;
			case '4':
				return 'Avril';
				break;
			case '5':
				return 'Mai';
				break;
			case '6':
				return 'Juin';
				break;
			case '7':
				return 'Juillet';
				break;
			case '8':
				return 'Ao&ucirc;t';
				break;
			case '9':
				return 'Septembre';
				break;
			case '10':
				return 'Octobre';
				break;
			case '11':
				return 'Novembre';
				break;
			case '12':
				return 'Décembre';
				break;
		}
	}

	public function AfficherMois() {
                echo '<p>Voir les activit&eacute;s du mois de <select id="selection_mois">';

                $mois = array();
		$query = 'SELECT DISTINCT MONTH(date_activite) AS mois FROM activite WHERE YEAR(date_activite) = "'.$this->annee.'" ORDER BY MONTH(date_activite);';
		$result = $this->mysql->Query($query);
		while($row = $result->fetch_assoc()) {	
		    $mois[] = (int)$row['mois'];
		}
                $result->close();

                if(!in_array($this->mois, $mois)) {
			echo '<option value="#EMPTY#">Choisissez un mois</option>';
		}
                foreach($mois as $m) {
			echo '<option value="'.$m.'"'.($this->mois == $m ? ' selected="selected"' : '').'>'.$this->NomMois($m).'</option>';
		}

                echo '</select></p><script type="text/javascript">
			$("#selection_mois").change(function() {
				location = "/calendrier_encadrements.php?y='.$this->annee.'&m="+this.value;
			});
		</script>';
	}

        public function Afficher() {
             echo '<p align="center"><font size="5" face="Arial" color="#ed1b24">Activit&eacute;s de '.$this->NomMois($this->mois).' '.$this->annee.'</font></p>';

             $this->AfficherMois();

	     echo '<table width="100%" cellspacing="0" cellpadding="4" bordercolor="#ffcc33" border="1"><thead><tr>
<td width="14%" valign="middle" bgcolor="#000000" align="center" style="color: #ffffff;">Dimanche</td>
<td width="14%" valign="middle" bgcolor="#000000" align="center" style="color: #ffffff;">Lundi</td>
<td width="14%" valign="middle" bgcolor="#000000" align="center" style="color: #ffffff;">Mardi</td>
<td width="14%" valign="middle" bgcolor="#000000" align="center" style="color: #ffffff;">Mercredi</td>
<td width="14%" valign="middle" bgcolor="#000000" align="center" style="color: #ffffff;">Jeudi</td>
<td width="14%" valign="middle" bgcolor="#000000" align="center" style="color: #ffffff;">Vendredi</td>
<td width="14%" valign="middle" bgcolor="#000000" align="center" style="color: #ffffff;">Samedi</td>
</tr></thead><tbody>';

             $ts = mktime(0,0,0, $this->mois, 1, $this->annee);
             $last_ts = mktime(0,0,0, $this->mois+1, 0, $this->annee);
             
             $jour = date('w', $ts);
             echo '<tr>';
             if($jour != 0) {
	         echo '<td colspan="'.$jour.'"><br /><br /><br /><br /></td>';
             }
             $j = 1;
             for($i = $jour; $i < 7; $i++) {
                 if($html = $this->GetActivites($j)) {
	             echo '<td valign="top" bgcolor="#ed1b24" align="left">'.$j++.'<br />'.$html.'</td>';
                 }
                 else {
	             echo '<td valign="top" bgcolor="#ffffcc" align="left">'.$j++.'<br /><br /><br /><br /></td>';
                 }
             }
             echo '</tr>';
  
             $l = date('j', $last_ts);

             while($j < $l + 1) {
                 echo '<tr>';
	         for($i = 0; $i < 7; $i++) {
                     if($j == $l + 1)
                          break;

	             if($html = $this->GetActivites($j)) {
	                 echo '<td valign="top" bgcolor="#ed1b24" align="left">'.$j++.'<br />'.$html.'</td>';
                     }
                     else {
	                 echo '<td valign="top" bgcolor="#ffffcc" align="left">'.$j++.'<br /><br /><br /><br /></td>';
                     }
                 }
                 if($i != 7) {
	             echo '<td colspan="'.(7-$i).'"></td>';
                     break;
                 }
                 else {
                     echo '</tr>';
                 }
             }

             echo '</tbody></table>';
			 
			 echo '<br /><span>Voir les activit&eacute;s de </span><select onchange="location = \'/calendrier_encadrements.php?y=\'+this.value;">';
			 foreach($this->annees as $a_annee) { 
				 echo '<option '.($a_annee == $this->annee ? 'selected="selected"' : '').' value="'.$a_annee.'">'.$a_annee.'</option>';
			 }
			 echo '</select><br /><a href="encadrements2010.php"><font color="#FF0000">Cliquez ici</font></a> pour voir le calendrier de 2010.';
        }

        public function GetActivites($jour) {
		$html = '';
        	$i = 0;
        	$query = 'SELECT id_activite, nom_activite FROM activite WHERE date_activite = "'.$this->annee.'-'.str_pad($this->mois, 2, '0', STR_PAD_LEFT).'-'.str_pad($jour, 2, '0', STR_PAD_LEFT).'" ORDER BY nom_activite;';
		$result = $this->mysql->Query($query);
		if($row = $result->fetch_assoc()) {
			do {
                                if($i > 0) $html .= '<hr style="color: #ffffcc;" />';
		        	$i++;
				$html .= '<a href="fiche_encadrement.php?id='.$row['id_activite'].'" style="color: white;">'.htmlentities($row['nom_activite']).'</a><br />';
			} while($row = $result->fetch_assoc());
			$result->close();

			if($i < 3) {
				$html .= str_repeat('<br />', 3 - $i);
			}

                	return $html;
		}
		else return false;
	}
}