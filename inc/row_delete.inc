<?php
$regel = $_GET['delete'];

$sql = "DELETE FROM schuld
		WHERE id=$regel;";

$result = mysql_query($sql) or die(mysql_error());

?>
<p>Regel verwijderd!</p>