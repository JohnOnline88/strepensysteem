<?php

$naam = $_GET['naam'];

echo "<p>$naam wil het volgende afbetalen:</p>";

?>
<p><b>Let op!</b> Komma's in bedragen moeten ingevoerd worden als een punt!</p>
<form method="post" action="index.php?id=98&amp;pid=<?php echo $_GET['pid']; ?>">
<table>
<tr>
	<td>Aantal:</td>
	<td>Eenheid:</td>
</tr>
<tr>
	<td><input name="eur" type="text" /></td>
	<td>Euro's</td>
</tr>
<tr>
	<td></td>
	<td><input type="submit" name="Submit" value="Afbetalen" /></td>
</tr>
</table>
</form>