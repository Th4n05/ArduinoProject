<?php
  $localhost = "localhost";
  $username = "root";
  $password = "";
  $servername = "sgh";

  $mysqli = new mysqli($localhost, $username, $password, $servername);
  if($mysqli->connect_error){
    die("error: ".$mysqli->connect_error);
  }

  $conn = $mysqli->prepare("SELECT value, tempo FROM dati WHERE type = 'E'");
  $conn->execute();
  $conn->store_result();
  if ($conn->num_rows > 0) {}
  $conn->bind_result($val, $t);
  $conn->fetch();

  echo "<table>";
  echo "<tr>";
  echo "<th>DATE</th>";
  echo "<td>TYPE ERROR</td>";
  echo "</tr>";
  echo "<tr>";
  echo "<th>". $t ."</th>";
  echo "<td>". $val ."</td>";
  echo "</tr>";
  echo "</table>";
  $conn->close();

  $st = $mysqli->prepare("UPDATE `dati` SET `type`='Z' WHERE type = 'E'");
  $st->execute();
  $st->store_result();
  $st->close();
  $mysqli->close();
 ?>
