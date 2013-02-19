<?php

class Prospect {
	private $id_prpspect;
	private $courriel;
	private $nom;
	private $prenom;
   private $telephone_residence;
   private $telephone_bureau;
   private $telephone_autre;
   private $adresse;
   private $ville;
   private $code_postal;
   private $date_naissance;
   private $maillot_grandeur;
   private $groupe_vitesse;
   private $no_assurance_maladie;
   private $urgence_nom;
   private $urgence_lien;
   private $urgence_tel_res;
   private $urgence_tel_bur;
   private $urgence_tel_autre;

	public function __construct(MySQL $mysql, $id_prospect) {
	   $query  = 'SELECT id_prospect, nom, prenom, courriel,telephone_residence,telephone_bureau,telephone_autre, ';
	   $query .= 'adresse,ville,code_postal,date_naissance,maillot_grandeur,groupe_vitesse,no_assurance_maladie,urgence_nom,urgence_lien, ';
      $query .= 'urgence_tel_res,urgence_tel_bur,urgence_tel_autre FROM prospect WHERE id_prospect= ? ';

		$stmt = $mysql->Prepare($query);
		$stmt->bind_param('d', $id_prospect);
		$stmt->execute();
		$stmt->bind_result($id, $nom, $prenom, $courriel,$telephone_residence,$telephone_bureau,$telephone_autre,$adresse,$ville,$code_postal,$date_naissance,$maillot_grandeur,$groupe_vitesse,$no_assurance_maladie,$urgence_nom,$urgence_lien,$urgence_tel_res,$urgence_tel_bur,$urgence_tel_autre);
		if($stmt->fetch()) {
			$stmt->close();

			$this->id_prospect = $id;
			$this->nom = $nom;
			$this->prenom = $prenom;
			$this->courriel = $courriel;
			
         $this->telephone_residence  = $telephone_residence;
         $this->telephone_bureau     = $telephone_bureau;
         $this->telephone_autre      = $telephone_autre;
         $this->adresse              = $adresse;
         $this->ville                = $ville;
         $this->code_postal          = $code_postal;
         $this->date_naissance       = $date_naissance;
         $this->maillot_grandeur     = $maillot_grandeur;
         $this->groupe_vitesse       = $groupe_vitesse;
         $this->no_assurance_maladie = $no_assurance_maladie;
         $this->urgence_nom          = $urgence_nom;
         $this->urgence_lien         = $urgence_lien;
         $this->urgence_tel_res      = $urgence_tel_res;
         $this->urgence_tel_bur      = $urgence_tel_bur;
         $this->urgence_tel_autre    = $urgence_tel_autre;

      }
		else {
			$stmt->close();

			throw new Exception('Prospect inconnu : '.$id_prospect);
		}
	}

	public function __get($attr) {
		if(isset($this->$attr)) return $this->$attr;
		else return "";
	}
}