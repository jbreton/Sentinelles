<?php

echo '<h2>' . htmlentities($row['nom']) . '</h2>';

echo '<p><b>objet</b> : '.  htmlentities($row['objet']).'</p>';
echo '<p><b>courriel</b> : '.  htmlentities($row['message']).'</p>';
