<h2 class="title">Nieuws</h2>
<table class="news">
	<tr>
		<td align="left">Datum</td>
		<td align="left">Onderwerp</td>
	</tr>
<?php
$sql = "SELECT id, UNIX_TIMESTAMP(datum) AS datum, onderwerp
		FROM nieuws
		ORDER BY datum DESC
		LIMIT 0,10;";
	$result = mysql_query($sql) or die(mysql_error());
	while ($resultaat = mysql_fetch_array($result)){
	$datum = strtotime($resultaat['datum']);
	echo "<tr>
			<td align='left'>".date('d-m-Y', $resultaat['datum'])."&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
			<td align='left'><a href=\"index.php?id=15&amp;newsId=".$resultaat['id']."\">".$resultaat['onderwerp']."</a></td>
		</tr>";
	}
?>
</table>
