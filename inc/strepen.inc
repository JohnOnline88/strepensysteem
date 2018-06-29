<h2 class="title">Strepen</h2>
<?php
$ip=$_SERVER['REMOTE_ADDR'];
//echo $ip;
//87.211.88.179 = John thuis
//87.211.111.51 = Clubhuis

if($ip=="87.211.111.51" //clubhuis
		or $ip=="145.132.88.28" //Thuis
		or $ip=="90.145.53.100") { //Vosko
?>
<p><b>Let op! Vanaf 1 januari 2014 mag er alleen alcohol gekocht worden als je boven de 18 bent!</b></p>

<p><b>Gelijk betalen = Invoeren onder naam Contant!!!!</b></p>
<form method="post" action="index.php?id=3">
<table border="1">
	<tr>
		<td>Naam</td>
		<td><select name="naam">
		<?php
			echo "<option value='naam'>Naam</option>";
			$sql = "SELECT *
					FROM stamleden
					WHERE active='1'
					ORDER BY naam ASC";
					$result = mysql_query($sql) or die(mysql_error());		
			while ($resultaat = mysql_fetch_array($result))
			echo "<option value='".$resultaat['id']."'>".$resultaat['naam']."</option>";	
		?>
			</select>
	</td>
	</tr>
	<tr>
	<td>Product</td>
	<td>Prijs</td>
	<td>Aantal</td>
	</tr>
<?php
		$sql = "SELECT *
		FROM product
		WHERE active='1';";
		$result = mysql_query($sql) or die(mysql_error());		
		while ($resultaat = mysql_fetch_array($result)){
		echo "	<tr><td>".$resultaat['omschrijving']."</td>
				<td>".number_format(($resultaat['prijs']),2)." euro</td>
				<td><select name='".$resultaat['id']."'>";
				for($t=0;$t<25;$t++)
					echo "<option value='".$resultaat['id'].";".$t."'>".$t."</option> \n";
				echo "</select></td></tr>";
				}				
?>
<tr>
<td></td>
<td></td>
<td><input type="submit" name="Submit" value="Strepen" /></td>
</tr>
</table>
<br />
<br />
</form>
<?php
}
else{
?>
<p>Helaas, deze pagina is alleen vanaf het clubhuis te bezoeken.</p>
<?php
}
?>
