<?php
$product = $_GET['pid'];

$title = FALSE;
$sql = "SELECT St.naam AS naam, Sc.aantal AS aantal, P.omschrijving AS omschrijving, Sc.prijs AS prijs, Sc.datum AS datum, Sc.id AS id, Sc.lid_id AS lid
		FROM schuld Sc, stamleden St, product P
		WHERE Sc.product_id=P.id AND Sc.lid_id=St.id AND P.id=$product
		ORDER BY Sc.datum DESC
		LIMIT 0,500;";
		
$result = mysql_query($sql) or die(mysql_error());		
	while ($resultaat = mysql_fetch_array($result)){
	if($title==FALSE){
		echo "<h2 class='title'>".$resultaat['omschrijving']."</h2>
				<table border='1'>
				<tr>
					<td>Naam</td>
					<td>Aantal</td>
					<td>Prijs</td>
					<td>Datum</td>
					<td>Delete</td>
				</tr>";
		$title = TRUE;
	}
	
	echo "<tr>
			<td><a href='index.php?id=140&amp;pid=".$resultaat['lid']."'>".$resultaat['naam']."</a></td>
			<td>".$resultaat['aantal']."</td>
			<td>".$resultaat['prijs']."</td>
			<td>".$resultaat['datum']."</td>
			<td><a href='index.php?id=141&amp;delete=".$resultaat['id']."'>Delete</a></td>
		</tr>";
	
	}
echo "</table>";
?>
