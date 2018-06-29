			<br />
			<p><a href="#boven">Terug naar bovenkant pagina</a></p>
		</div>
	</div>
</div>


<div id="sidebar">
<ul>
<li>
<h2>Nieuws</h2>

<ul>
<?php
$sql = "SELECT id, UNIX_TIMESTAMP(datum) AS datum, onderwerp
		FROM nieuws
		ORDER BY datum DESC
		LIMIT 0,5;";
	$result = mysql_query($sql) or die(mysql_error());
	while ($resultaat = mysql_fetch_array($result)){
	$datum = strtotime($resultaat['datum']);
	echo "<li><a href=\"index.php?id=15&amp;newsId=".$resultaat['id']."\">".$resultaat['onderwerp']."</a></li>";
	}
?>
</ul>
</li>
</ul>
</div>
</div>
<div style="clear: both;">&nbsp;</div>

<div id="footer">
	<p>&copy;<?php echo date(Y); ?> - Stambestuur</p>
</div>
</body>
</html>
<?php
mysql_close();
?>
