<?php

$conn = new mysqli("localhost", "root", "", "labirinto");


$stmt = $conn->query("select * from dati order by id");

?>