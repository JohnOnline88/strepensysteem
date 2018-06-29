<?php
$person = $_GET['pid'];

$title = FALSE;
$sql = "SELECT St.naam AS naam, Sc.aantal AS aantal, P.omschrijving AS omschrijving, Sc.prijs AS prijs, Sc.datum AS datum, Sc.id AS id, Sc.product_id AS product
		FROM schuld Sc, stamleden St, product P
		WHERE Sc.product_id=P.id AND Sc.lid_id=St.id AND St.id=$person
		ORDER BY Sc.datum DESC;";
		
$result = mysql_query($sql) or die(mysql_error());		
	while ($resultaat = mysql_fetch_array($result)){
	if($title==FALSE){
		echo "<h2 class='title'>".$resultaat['naam']."</h2>
				<table border='1'>
				<tr>
					<td>Product</td>
					<td>Aantal</td>
					<td>Prijs</td>
					<td>Datum</td>
					<td>Delete</td>
				</tr>";
		$title = TRUE;
	}
	
	echo "<tr>
			<td><a href='index.php?id=150&amp;pid=".$resultaat['product']."'>".$resultaat['omschrijving']."</a></td>
			<td>".$resultaat['aantal']."</td>
			<td>".$resultaat['prijs']."</td>
			<td>".$resultaat['datum']."</td>
			<td><a href='index.php?id=141&amp;delete=".$resultaat['id']."'>Delete</a></td>
		</tr>";
	
	}
echo "</table>";
?>
