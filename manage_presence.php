<?php												

require_once('classes/mysql.inc');

$mysql = new MySQL();

   if((int)$_GET['presence'] > 0 || $_GET['action'] == 'ajout')
   switch($_GET['action']) {
	case 'supprimer':
            $query = 'DELETE FROM presence WHERE id_presence = '.(int)$_GET['presence'].';';
            $mysql->Query($query);
            echo 'done';
            break;
	case 'present':
            $query = 'UPDATE presence SET est_present = "Y" WHERE id_presence = '.(int)$_GET['presence'].';';
            $mysql->Query($query);
            echo 'done';
            break;
	case 'absent':
            $query = 'UPDATE presence SET est_present = "N" WHERE id_presence = '.(int)$_GET['presence'].';';
            $mysql->Query($query);
            echo 'done';
            break;
	case 'change_groupe':
			$query = 'UPDATE presence SET id_groupe_vitesse_demande	 = "'.(int)$_GET['groupe'].'" WHERE id_presence = '.(int)$_GET['presence'].';';
            $mysql->Query($query);
            echo 'done';
			break;
	case 'ajout':
			$query = 'INSERT INTO presence SET participation = "Y", id_membre = '.(int)$_GET['membre'].', id_activite = '.(int)$_GET['activite'].', id_groupe_vitesse_demande = '.(int)$_GET['groupe'].', date_confirmation = "'.date('Y-m-d H:i:s').'";';
			$mysql->Query($query);
			echo $mysql->LastInsertId();
			break;
   }