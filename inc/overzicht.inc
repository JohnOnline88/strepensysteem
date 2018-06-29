<h2 class="title"> Overzicht schulden</h2>
<?php
$ip=$_SERVER['REMOTE_ADDR'];

if (in_array($ip, $ip_array)) {

?>
<p>Kom je niet in het overzicht voor? Dan sta je op nul. Je hebt dus geen schuld. Heb je een schuld en wil je betalen? Dan kun je geld overmaken naar
rekening 
<?php
echo $stamrekening;
?>
</p>
<table border='1'>
<tr>
<td>Naam</td>
<td>Schuld (EUR)</td>
</tr> 
<?php
if ($_GET['order'] != "abc") {
	$order = "totaleSchuld DESC";
}

else {
	$order = "naam ASC";
}

$sql = "SELECT n.naam AS naam, SUM( s.prijs ) AS totaleSchuld
		FROM stamleden n
			JOIN schuld s ON n.id = s.lid_id
		WHERE n.active='1'
		GROUP BY naam
		ORDER BY ".$order."";
$result = mysql_query($sql) or die(mysql_error());		
while ($resultaat = mysql_fetch_array($result)){
if($resultaat['totaleSchuld']!=0){
	$schuld_eur = number_format($resultaat['totaleSchuld'] ,2);
	echo "<tr>
			<td>".$resultaat['naam']."</td>
			<td>".$schuld_eur."</td>
			</tr> ";
	}
}
?>
</table>
<?php
if ($_GET['order'] != "abc") {
	echo "<p><a href='index.php?id=4&order=abc'>Sorteren op alfabet</a> ".$_GET['order']." </p>";
}

else {
	echo "<p><a href='index.php?id=4'>Sorteren op schuld</a></p>";
}
}
else{

echo "<p>Helaas, deze pagina is alleen vanaf het clubhuis te bezoeken.</p>";

}
?>	
