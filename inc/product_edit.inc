<?php
if($_GET['product'] != 'nieuw'){
	if($_SERVER['REQUEST_METHOD']=="POST"){
	if(isset($_POST['delete'])){
		$sql = "UPDATE product
				SET active='0'
				WHERE id=".$_GET['product'].";";
		mysql_query($sql);
		}
	else{
		$sql = "UPDATE product
				SET omschrijving='".$_POST['omschrijving']."', prijs=".$_POST['prijs']."
				WHERE id=".$_GET['product'].";";
	mysql_query($sql);	
	}
	
	header('Location: index.php?id=60');
	}
	$sql = "SELECT *
			FROM product
			WHERE id=".$_GET['product'].";";
	$result = mysql_query($sql) or die(mysql_error());		
	while ($resultaat = mysql_fetch_array($result)){
?>
<form method="post" action="">
<table>
	<tr>
		<td>Omschrijving:</td>
		<td> <input name="omschrijving" type="text" value="<?php echo $resultaat['omschrijving']; ?>" /></td>
	</tr>
	<tr>
		<td>Prijs (EUR):</td>
		<td><input name="prijs" type="text" value="<?php echo $resultaat['prijs']; ?>" /></td>
	</tr>
	<tr>
		<td>Verwijderen:</td>
		<td align="left"><input name="delete" type="checkbox" /></td>
	</tr>
	<tr>
		<td></td>
		<td align="left"><input type="submit" name="Submit" value="<?php echo "Aanpassen";?> " /></td>
	</tr>
</table>
</form>
<?php
	}
}
else{
	if($_SERVER['REQUEST_METHOD']=="POST"){
		$sql = "INSERT INTO product(id,omschrijving,prijs,active)
				VALUES(NULL,'".$_POST['omschrijving']."',".$_POST['prijs'].",'1');";
	mysql_query($sql);
	$last_id = mysql_insert_id();
		$sql = "INSERT INTO inkoop(id,product_id,aantal,actie,datum)
				VALUES (NULL,'".$last_id."','0','gekocht',CURRENT_TIMESTAMP);";
		mysql_query($sql);
	$sql = "INSERT INTO schuld(id,lid_id,product_id,actie,aantal,prijs,datum)
				VALUES(NULL,'48','".$last_id."','gekocht',0,0,CURRENT_TIMESTAMP);";
	mysql_query($sql);
	header('Location: index.php?id=60');
	}
?>
<form name="edit" method="post" action="">
<table>
	<tr>
		<td>Omschrijving:</td>
		<td> <input name="omschrijving" type="text" /></td>
	</tr>
	<tr>
		<td>Prijs (eur):</td>
		<td><input name="prijs" type="text" /></td>
	</tr>
	<tr>
		<td></td>
		<td><input type="submit" name="Submit" value="<?php echo "Toevoegen";?> " /></td>
	</tr>
</table>
</form>
<?php
}
?>


