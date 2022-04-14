<?php
session_start();

$conn = new mysqli("localhost","root","","labirinto");



$data = $conn->query("insert into dati ('x','y','livello','conferma') values ({$_POST["x"]},{$_POST["y"]},{$_SESSION["livello"]}),{$_POST["conferma"]}");

?>