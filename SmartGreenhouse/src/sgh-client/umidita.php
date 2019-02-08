<?php
  $localhost = "localhost";
  $username = "root";
  $password = "";
  $servername = "sgh";

  $mysqli = new mysqli($localhost, $username, $password, $servername);
  if($mysqli->connect_error){
    die("error: ".$mysqli->connect_error);
  }
  $conn = $mysqli->prepare("SELECT value, tempo FROM dati WHERE type = 'H' ORDER BY tempo DESC LIMIT 10");
  $conn->execute();
  $conn->store_result();
  $time = array();
  $value = array();
  $i = 0;
  if ($conn->num_rows > 0) {
    while ($i < $conn->num_rows) {
        $conn->bind_result($val, $t);
        $conn->fetch();
        $value[$i] = $val;
        $time[$i] = $t;
        $i++;
    }
  }
  echo "<table>";
  echo "<tr>";
  echo "<th>DATE</th>";
  echo "<td>VALUE</td>";
  echo "</tr>";
  for($i = 0; $i <= $conn->num_rows - 1; $i++){
    echo "<tr>";
    echo "<th>" . $time[$i] . "</th>";
    echo "<td>" . $value[$i] . "%</td>";
    echo "</tr>";
  }
  echo "</table>";
  $conn->close();
  $mysqli->close();
 ?>
