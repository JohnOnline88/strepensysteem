<?php
if($_GET['person'] != 'nieuw'){
	if($_SERVER['REQUEST_METHOD']=="POST"){
	if(isset($_POST['delete'])){
		$sql = "UPDATE stamleden
				SET active='0', mailinglist='0'
				WHERE id=".$_GET['person']."";
		mysql_query($sql);
		}
	else{
		if(isset($_POST['mailinglist'])){
			$mailinglist=1;
		}
		else{
			$mailinglist=0;
	}
		$sql = "UPDATE stamleden
				SET naam='".$_POST['naam']."', email='".$_POST['email']."', mailinglist='".$mailinglist."'
				WHERE id=".$_GET['person']."";
	mysql_query($sql);	
	}
	
	header('Location: index.php?id=54');
	}
	$sql = "SELECT *
			FROM stamleden
			WHERE id=".$_GET['person']."";
	$result = mysql_query($sql) or die(mysql_error());		
	while ($resultaat = mysql_fetch_array($result)){
?>
<form method="post" action="">
<table>
	<tr>
		<td>Naam:</td>
		<td> <input name="naam" type="text" value="<?php echo $resultaat['naam']; ?>" /></td>
	</tr>
	<tr>
		<td>E-mail:</td>
		<td><input name="email" type="text" value="<?php echo $resultaat['email']; ?>" /></td>
	</tr>
	<tr>
		<td>Mailing:</td>
		<td align="left"><input name="mailinglist" type="checkbox" <?php if($resultaat['mailinglist']==1){ echo "checked"; } ?> /></td>
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
		$sql = "INSERT INTO stamleden(id,naam,email,active,mailinglist)
				VALUES(NULL,'".$_POST['naam']."','".$_POST['email']."','1','1');";
	mysql_query($sql);
	$last_id = mysql_insert_id();
	$sql = "INSERT INTO schuld(id,lid_id,product_id,actie,aantal,prijs,datum)
				VALUES(NULL,'".$last_id."',7,'0',0,0,CURRENT_TIMESTAMP);";
	mysql_query($sql);
	header('Location: index.php?id=54');
	}
?>
<form method="post" action="">
<table>
	<tr>
		<td>Naam:</td>
		<td> <input name="naam" type="text" /></td>
	</tr>
	<tr>
		<td>E-mail:</td>
		<td><input name="email" type="text" /></td>
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


