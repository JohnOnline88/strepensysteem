<?php
if($_SERVER['REQUEST_METHOD']=="POST"){
	$sql = "SELECT *
				FROM stamleden
				WHERE active='1'
				ORDER BY naam ASC";
				$result = mysql_query($sql) or die(mysql_error());		
		while ($resultaat = mysql_fetch_array($result)) {
			$prijs = $_POST[$resultaat['id']];
			if($prijs != null){
				$sql2 = "INSERT INTO schuld(id, lid_id, product_id, actie, aantal, prijs, datum)
						VALUES(NULL, '".$resultaat['id']."', '10', '0', '1', '".$prijs."', CURRENT_TIMESTAMP);";
				$result2 = mysql_query($sql2) or die(mysql_error());
		}

	}
	echo "<p>Het strepen van het eten is verwerkt.</p>";
}
?>



<?php
if($_SERVER['REQUEST_METHOD']!="POST"){
?>

<p>Vul achter de personen die meegegeten hebben de prijs van het eten in. Geen komma's gebruiken in de prijs. Gebruik daarvoor een punt.</p>
<form method="post" action="">
<table>
	<?php
		$sql = "SELECT *
				FROM stamleden
				WHERE active='1'
				ORDER BY naam ASC";
				$result = mysql_query($sql) or die(mysql_error());		
		while ($resultaat = mysql_fetch_array($result))
		echo "	<tr>
					<td>".$resultaat['naam']."</td>
					<td align='left'> <input name=".$resultaat['id']." type='text' /></td>
				</tr>";
		?>
	<tr>
		<td></td>
		<td align="left"><input type="submit" name="Submit" value="Eten verwerken"/></td>
	</tr>
</table>
</form>

<?php
}
?>