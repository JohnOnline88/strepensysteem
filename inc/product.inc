<h2 class="title">Producten</h2>
<p>Hieronder een overzicht van de producten en de mogelijkheid ze aan te passen of te verwijderen. 
Let op! Het afbetalen gebruikt de regel Lekkere Wijven. Deze regel dus niet verwijderen!</p>
<table border='1'>
	<tr>
		<td>Product</td>
		<td>Prijs</td>
		<td>Edit</td>
	</tr>
	<?php
	$sql = "SELECT *
			FROM product
			WHERE active='1';";
	$result = mysql_query($sql) or die(mysql_error());		
	while ($resultaat = mysql_fetch_array($result)){
	echo "<tr>
			<td><a href='index.php?id=150&amp;pid=".$resultaat['id']."'>".$resultaat['omschrijving']."</a></td>
			<td>".number_format($resultaat['prijs'],2)." euro</td>
			<td><a href='index.php?id=160&amp;product=".$resultaat['id']."'>Edit</a></td>
		</tr>";	
	}
	?>
</table><br />
<p><a href='index.php?id=160&amp;product=nieuw'>Product toevoegen</a></p>
