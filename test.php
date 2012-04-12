<?php											

$mysql = new MySQL();

$query = 'SELECT * FROM membre;';
$result = $mysql->Query($query);
if($row = $result->fetch_assoc()) {
  echo '<table><thead><tr>';
  foreach(array_keys($row) as $header) {
    echo '<th>'.htmlentities($header).'</th>';
  }
  echo '</thead><tbody>';
  do {
    echo '<tr>';
    foreach($row as $field) {
      echo '<td>'.htmlentities($field).'</td>';	
    }
    echo '</tr>';
  } while($row = $result->fetch_assoc());
  echo '</tbody></table>';
}
else {
  echo 'Aucune membre trouvé';
}
$result->close();

?>