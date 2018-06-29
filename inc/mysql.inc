<?php
mysql_connect('localhost', 'user', 'password') or die("Kan geen database-server connectie maken");
mysql_select_db('database') or die("kan database niet vinden: " . mysql_error());
?>