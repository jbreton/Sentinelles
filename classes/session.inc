<?php

class Session {
        private $_mysql;
        private $_from_post = false;
        private $_from_authentification = false;

	public function __construct() {
	     $this->_mysql = new MySQL();
        }

        public function Start($membre=false) {
           session_name('SENTINELLES');
           session_set_cookie_params(60 * 60 * 24 * 14); // 2 weeks
	   session_start();
	   if($_POST['logout'] == 1) {
	      session_destroy();
              session_start();
              return false;
           }
           else if($membre instanceof Membre) {
             $_SESSION['membre'] = $membre;
             return $membre;
           }
           else if($_POST['email'] && $_POST['passwd']) {
              $stmt = $this->_mysql->Prepare('SELECT id_membre FROM membre WHERE courriel = ? AND mot_passe = ?;');
              $stmt->bind_param('ss', $_POST['email'], $_POST['passwd']);
              $stmt->execute();
	      $stmt->bind_result($id_membre);
              if($stmt->fetch()) {
                $stmt->close();

                $membre = new Membre($this->_mysql, $id_membre);
                $_SESSION['membre'] = $membre;

                $this->_from_post = true;

                return $membre;
              }
              else {
                $stmt->close();
	        return false;
              }
           }
           else if($_SESSION['membre'])
               return $_SESSION['membre'];
           else if($_GET['authentification']) {
               $query = 'DELETE FROM authentification_membre WHERE timestamp < '.time().';';
               $this->_mysql->Query($query);

               $stmt = $this->_mysql->Prepare('SELECT membre.id_membre, id_authentification FROM authentification_membre 
                                               INNER JOIN membre ON membre.id_membre = authentification_membre.id_membre
                                               WHERE membre.actif = "Y" AND authentification_membre.authentification = ? LIMIT 1;');
               $stmt->bind_param('s', $_GET['authentification']);
               $stmt->execute();
               $stmt->bind_result($id_membre, $id_auth);
               if($stmt->fetch()) {
                 $stmt->close();

	         $membre = new Membre($this->_mysql, $id_membre);
                 $_SESSION['membre'] = $membre;

                 $query = 'DELETE FROM authentification_membre WHERE id_authentification = '.$id_auth.';';
                 //$this->_mysql->Query($query);

                 $this->_from_authentification = true;

                 return $membre;
               }
               else {
	          $stmt->close();

                  return false;
               }
           }
           else
               return false;
        }

        public function FromPost() {
	   return $this->_from_post;
        }

        public function FromAuthentification() {
	   return $this->_from_authentification;
        }

        public function Write() {
	  session_commit();
        }

        public function MySQL() {
	   return $this->_mysql;
        }
}