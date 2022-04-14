<?php
$conn = new mysqli("localhost","root","","labirinto");

$rmv = $conn->query("delete from dati");
?>