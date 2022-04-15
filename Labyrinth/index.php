<?php
session_start();
if (!isset($_SESSION["livello"])) {
  $_SESSION["livello"]=0;
} 
?>
<!DOCTYPE html>
<html>
  <title>labirinto</title>
  <div id="game-container-1" class="game-container">
    <link rel="stylesheet" href="css/labcss.css">
    
      <div id="map-and-controls">
      <div id="game-map-1" class="game-map">
        <div id="tiles" class="layer"></div>
        <div id="sprites" class="layer"></div>
        <div id="success-msg">Obbiettivo raggiunto! Tocca il labirininto con il cursore per cambiare livello!</div>
      </div>
      
      
       <!--
      <div id="controls">
        <button id="up"></button>
        <div id="horiz">
           <button id="left"></button>
           <button id="right"></button>
        </div>
         <button id="down"></button>
       </div>
      </div>
        <p id="text-1" class="text">muoviti</p>
    </div> -->
    <script src="js/labjs.js"></script>
</html>
