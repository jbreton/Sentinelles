<?php												

require_once('classes/mysql.inc');

$mysql = new MySQL();

   if((int)$_GET['presence'] > 0)
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
   }