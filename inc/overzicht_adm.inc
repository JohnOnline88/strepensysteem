<h2 class="title"> Overzicht schulden</h2>

<table border='1'>
<tr>
<td>Naam</td>
<td>Schuld (EUR)</td>
<td>Betalen</td>
<td>Edit</td>
</tr> 
<?php
$sql = "SELECT s.lid_id AS id, n.naam AS naam, SUM( s.prijs ) AS totaleSchuld
		FROM stamleden n
			JOIN schuld s ON n.id = s.lid_id
		WHERE n.active='1'
		GROUP BY naam
		ORDER BY naam ASC";
$result = mysql_query($sql) or die(mysql_error());		
while ($resultaat = mysql_fetch_array($result)){
	$schuld_eur = number_format($resultaat['totaleSchuld'] ,2);
	echo "<tr>
			<td><a href='index.php?id=140&amp;pid=".$resultaat['id']."'>".$resultaat['naam']."</a></td>
			<td>".$schuld_eur."</td>
			<td><a href='index.php?id=97&amp;pid=".$resultaat['id']."&amp;naam=".$resultaat['naam']."'>Betalen</a></td>
			<td><a href='index.php?id=161&amp;person=".$resultaat['id']."'>Edit</a></td>
			</tr> ";
	}
?>
<tr>
<td>Totaal:</td>
<?php
$sql = "SELECT SUM(prijs ) AS totaleSchuld
		FROM schuld";
$result = mysql_query($sql) or die(mysql_error());		
while ($resultaat = mysql_fetch_array($result)){
echo "<td>".number_format($resultaat['totaleSchuld'] ,2)."</td>";
}
?>
<td></td>
<td></td>
</tr>
</table>
<p><a href='index.php?id=161&amp;person=nieuw'>Persoon toevoegen</a></p>

