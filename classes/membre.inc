<?php

class Membre {
	private $id_membre;
	private $courriel;
	private $mot_passe;
	private $nom;
	private $prenom;
	private $est_ca;
	private $cotisation_payee;
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
   private $est_inscrit;
   private $formulaire_recu;
   private $inscription_envoyee;

	public function __construct(MySQL $mysql, $id_membre) {
	   $query  = 'SELECT membre.id_membre, nom, prenom, courriel, mot_passe, est_ca, cotisation_payee,telephone_residence,telephone_bureau,telephone_autre, ';
	   $query .= 'adresse,ville,code_postal,date_naissance,maillot_grandeur,groupe_vitesse,no_assurance_maladie,urgence_nom,urgence_lien, ';
      $query .= 'urgence_tel_res,urgence_tel_bur,urgence_tel_autre,maillot_remis,dossard_remis,coordonnees_publique, est_inscrit, formulaire_recu, id_inscription FROM membre ';
      $query .= 'LEFT JOIN (inscription INNER JOIN saison ON saison.id_saison = inscription.id_saison AND saison.active = "Y") ON inscription.id_membre = membre.id_membre ';
		$query .= 'WHERE membre.id_membre = ? AND membre.actif = "Y";';

		$stmt = $mysql->Prepare($query);
		$stmt->bind_param('d', $id_membre);
		$stmt->execute();
		$stmt->bind_result($id, $nom, $prenom, $courriel, $mot_passe, $est_ca, $cotisation_payee,$telephone_residence,$telephone_bureau,$telephone_autre,$adresse,$ville,$code_postal,$date_naissance,$maillot_grandeur,$groupe_vitesse,$no_assurance_maladie,$urgence_nom,$urgence_lien,$urgence_tel_res,$urgence_tel_bur,$urgence_tel_autre,$maillot_remis,$dossard_remis,$coord_public, $est_inscrit, $formulaire_recu, $id_inscription);
		if($stmt->fetch()) {
			$stmt->close();

			$this->id_membre = $id;
			$this->nom = $nom;
			$this->prenom = $prenom;
			$this->courriel = $courriel;
			$this->mot_passe = $mot_passe;
			$this->est_ca = $est_ca == 'Y';
			$this->cotisation_payee = $cotisation_payee == 'Y';
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
			$this->maillot_remis        = $maillot_remis == 'Y';
			$this->dossard_remis        = $dossard_remis == 'Y';
			$this->coord_public         = $coord_public == 'Y';
			$this->est_inscrit         = $est_inscrit == 'Y';
			$this->formulaire_recu         = $formulaire_recu == 'Y';
                        $this->inscription_envoyee = $id_inscription != "";

      }
		else {
			$stmt->close();

			throw new Exception('Membre inconnu : '.$id_membre);
		}
	}

	public function __get($attr) {
		if(isset($this->$attr)) return $this->$attr;
		else return "";
	}

	public function EstCA() {
		return $this->est_ca;
	}

        public function EstInscrit() {
	        return $this->est_inscrit == 'Y';
        }

	public function CotisationPayee() {
		return $this->cotisation_payee;
        }

	public function FormulaireRecu() {
		return $this->formulaire_recu;
	}
	
	public function Refresh(MySQL $mysql) {
	   $query  = 'SELECT membre.id_membre, nom, prenom, courriel, est_ca, cotisation_payee,telephone_residence,telephone_bureau,telephone_autre, ';
	   $query .= 'adresse,ville,code_postal,date_naissance,maillot_grandeur,groupe_vitesse,no_assurance_maladie,urgence_nom,urgence_lien, ';
      $query .= 'urgence_tel_res,urgence_tel_bur,urgence_tel_autre,maillot_remis,dossard_remis,coordonnees_publique, est_inscrit, formulaire_recu, id_inscription FROM membre ';
      $query .= 'LEFT JOIN (inscription INNER JOIN saison ON saison.id_saison = inscription.id_saison AND saison.active = "Y") ON inscription.id_membre = membre.id_membre ';
		$query .= 'WHERE membre.id_membre = ? AND membre.actif = "Y";';

		$stmt = $mysql->Prepare($query);
		$stmt->bind_param('d', $this->id_membre);
		$stmt->execute();
		$stmt->bind_result($id, $nom, $prenom, $courriel, $est_ca, $cotisation_payee,$telephone_residence,$telephone_bureau,$telephone_autre,$adresse,$ville,$code_postal,$date_naissance,$maillot_grandeur,$groupe_vitesse,$no_assurance_maladie,$urgence_nom,$urgence_lien,$urgence_tel_res,$urgence_tel_bur,$urgence_tel_autre,$maillot_remis,$dossard_remis,$coord_public, $est_inscrit, $formulaire_recu, $id_inscription);
		if($stmt->fetch()) {
			$stmt->close();

			$this->nom = $nom;
			$this->prenom = $prenom;
			$this->courriel = $courriel;
			$this->est_ca = $est_ca == 'Y';
			$this->cotisation_payee = $cotisation_payee == 'Y';
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
			$this->maillot_remis        = $maillot_remis == 'Y';
			$this->dossard_remis        = $dossard_remis == 'Y';
			$this->coord_public         = $coord_public == 'Y';
			$this->est_inscrit         = $est_inscrit == 'Y';
			$this->formulaire_recu         = $formulaire_recu == 'Y';
                        $this->inscription_envoyee = $id_inscription != "";
      }

	}
}