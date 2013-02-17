<?php

if(!$membre->EstCA()) {
	include('../includes/accueil.inc');
	return false;
}

echo '<h2>Liste des courriel</h2>';
include('list_courriel.inc');