<?php
mysql_connect($mysql_server, $mysql_user, $mysql_password) or die("Kan geen database-server connectie maken");
mysql_select_db($mysql_database) or die("kan database niet vinden: " . mysql_error());
?>