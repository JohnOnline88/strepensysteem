<h2 class="title">Voorraad</h2>
<table border='1'>
<tr>
	<td>Product</td>
	<td>Voorraad</td>
	<td>Edit</td>
</tr>
	
<?php
$sql = "SELECT p.omschrijving AS product, SUM(s.aantal) AS verkocht, p.id AS id
		FROM schuld s, product p
		WHERE s.product_id=p.id AND p.active='1'
		GROUP BY p.id, p.omschrijving;";
$result = mysql_query($sql) or die(mysql_error());
while ($resultaat = mysql_fetch_array($result)){
	$sql2 = "SELECT SUM(aantal) AS ingekocht
			FROM inkoop
			WHERE product_id=".$resultaat['id'].";";
	$result2 = mysql_query($sql2) or die(mysql_error());
	while ($resultaat2 = mysql_fetch_array($result2)){
		if($resultaat['id']==1){
		$voorraad="".$resultaat2['ingekocht'] - $resultaat['verkocht']." / ".number_format(($resultaat2['ingekocht'] - $resultaat['verkocht'])/24,2)."";
		}
		else{
		$voorraad=$resultaat2['ingekocht'] - $resultaat['verkocht'];
		}
	
	echo "<tr>
			<td><a href='index.php?id=150&amp;pid=".$resultaat['id']."'>".$resultaat['product']."</a></td>
			<td>$voorraad</td>
			<td><a href='index.php?id=162&amp;pid=".$resultaat['id']."'>Edit</a></td>
		</tr>
	";	
	}
}
?>
</table>
