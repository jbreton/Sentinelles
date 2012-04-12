
<?php

	
	$QSTRING = $QUERY_STRING; 
	$id = "";
	while (list ($header, $value) = each ($HTTP_GET_VARS)) 
	{ 
		if($header == 'id' || $header == 'ID')
		{
			$id = $value;
		}
		else
		{
		  $QSTRING = $QSTRING.'&'.$header.'='.$value; 
		}
	}
	$section = explode("&", $QSTRING);

	$theLink = "includes/accueil.inc";
	switch($section[0])
	{
		case 'encadrements' :
			$theLink = "includes/encadrements.inc";
			break;	
		case 'historique_mission' :
			$theLink = "includes/historique_mission.inc";
			break;
		case '' :
			$theLink = "includes/accueil.inc";
			break;
		
		default :
		
		//if($value->IsFileExists("2008/".$id.".html"))
			//	{
					$theLink = $id.".html";
					
						
			//	}
				
				
			//$theLink = "includes/accueil.inc";
			break;
	}
	include($theLink);


?>