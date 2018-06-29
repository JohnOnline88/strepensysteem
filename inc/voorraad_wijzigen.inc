

<?php
$sql = "SELECT *
		FROM product
		WHERE id=".$_GET['pid'].";";
$result = mysql_query($sql) or die(mysql_error());
while ($resultaat = mysql_fetch_array($result)){
	echo "<p>Voorraad aanpassen voor ".$resultaat['omschrijving']."</p>";
}

if($_SERVER['REQUEST_METHOD']=="POST"){
	$sql = "INSERT INTO inkoop(id,product_id,aantal,actie,datum)
			VALUES(NULL,'".$_GET['pid']."','".$_POST['aantal']*$_POST['verpakking']."','".$_POST['actie']."',CURRENT_TIMESTAMP);";
	mysql_query($sql);
	header('Location: index.php?id=55');
}

?>
<form method="post" action="">
<table>
	<tr>
		<td>Aantal:</td>
		<td> <input name="aantal" type="text" /></td>
	</tr>
	<tr>
		<td>Verpakking:</td>
		<td><select name="verpakking">
				<option value="1">Per stuk</option>
				<option value="6">6-Pack</option>
				<option value="15">Chips verzamel (15x)</option>
				<option value="24">Krat(24 stuks)</option>
			</select></td>
	</tr>
	<tr>
		<td>Actie:</td>
		<td><select name="actie">
				<option value="gekocht">Gekocht</option>
				<option value="mutatie">Mutatie</option>
			</select></td>
	</tr>
	<tr>
		<td></td>
		<td align="left"><input type="submit" name="Submit" value="<?php echo "Aanpassen";?> " /></td>
	</tr>
</table>
</form>