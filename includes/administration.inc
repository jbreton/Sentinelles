<?php

if(!$membre->EstCA()) {
	include('includes/accueil.inc');
	return false;
}

echo '<h2>Liste des courriels</h2>';
include('liste_courriel.inc');