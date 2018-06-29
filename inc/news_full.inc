<?php
$sql = "SELECT *
		FROM nieuws
		WHERE id=".$_GET['newsId'].";";
	$result = mysql_query($sql) or die(mysql_error());
	while ($resultaat = mysql_fetch_array($result)){
	echo "<h2 class='title'> Nieuws: ".$resultaat['onderwerp']."</h2>
			<p>".date('d-m-Y',strtotime($resultaat['datum']))."</p>
			<p>".$resultaat['bericht']."</p>
			<p>Ga terug naar het <a href='index.php'>overzicht</a></p>";
	}
?>
