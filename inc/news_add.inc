<?php
if($_SERVER['REQUEST_METHOD']=="POST"){
	$bericht = nl2br($_POST['bericht']);
	$sql = "INSERT INTO nieuws(id,datum,onderwerp,bericht)
			VALUES(NULL,CURRENT_TIMESTAMP,'".$_POST['onderwerp']."','".$bericht."');";
	mysql_query($sql);
	
					$to = "Stam <webmaster@diekantankys.nl>";
					$subject = "Stam Mailing: ".$_POST['onderwerp']."";
					$headers = "From: Stambestuur <stambestuur@diekantankys.nl>";
					$body = "Beste Stam,\n\n";
					$body .= "".$_POST['bericht']."\n\n";
					$body .= "Groeten, \n\n";
					$body .= "Het stambestuur"; 

					$mail_sent = @mail( $to, $subject, $body, $headers );
	
	if(isset($_POST['mail'])){
	$sql = "SELECT *
			FROM stamleden
			WHERE mailinglist='1' AND active='1';";
	$result = mysql_query($sql) or die(mysql_error());		
	while ($resultaat = mysql_fetch_array($result)){
					$to = "".$reultaat['naam']." <".$resultaat['email'].">";
					$subject = "Stam Mailing: ".$_POST['onderwerp']."";

					$headers = "From: Stambestuur <stambestuur@diekantankys.nl>\n";

					$body = "Beste ".$resultaat['naam'].",\n\n";
					$body .= "".$_POST['bericht']."\n\n";
					$body .= "Groeten, \n\n";
					$body .= "Het stambestuur"; 

					$mail_sent = @mail( $to, $subject, $body, $headers );
					echo $mail_sent ? "<p>Er is een bericht verzonden naar ".$resultaat['email'].".</p>" : "<p>Er is een fout opgetreden bij het verzenden van de mail naar ".$resultaat['email'].".</p>";
	}
	}
	
	if(isset($_POST['mailschuld'])){
	$sql = "SELECT n.naam AS naam, n.email AS email, SUM( s.prijs ) AS totaleSchuld
			FROM stamleden n
				JOIN schuld s ON n.id = s.lid_id
			GROUP BY naam, n.email
			HAVING SUM( s.prijs ) >0;";
	$result = mysql_query($sql) or die(mysql_error());		
	while ($resultaat = mysql_fetch_array($result)){
					$to = "".$reultaat['naam']." <".$resultaat['email'].">";
					$subject = "Stam Mailing: ".$_POST['onderwerp']."";

					$headers = "From: Stambestuur <stambestuur@diekantankys.nl>";


					$body = "Beste ".$resultaat['naam'].",\n\n";
					$body .= "".$_POST['bericht']."\n\n";
					$body .= "Groeten, \n\n";
					$body .= "Het stambestuur"; 

					$mail_sent = @mail( $to, $subject, $body, $headers );
					echo $mail_sent ? "<p>Er is een bericht verzonden naar ".$resultaat['email'].".</p>" : "<p>Er is een fout opgetreden bij het verzenden van de mail naar ".$resultaat['email'].".</p>";
	}
	//header('Location: index.php');
	}
}
?>
<p>Als je het vinkje mailen aanzet krijgt ieder stamlid ook een mailtje van dit bericht. Automatisch komt er boven het
bericht  "Beste naam," te staan en onderaan "Groeten, Het stambestuur".</p>
<form method="post" action="">
<table>
	<tr>
		<td>Onderwerp:</td>
		<td align="left"> <input name="onderwerp" type="text" /></td>
	</tr>
	<tr>
		<td>Bericht:</td>
		<td> <textarea name="bericht" cols="50" rows="10"></textarea></td>
	</tr>
	<tr>
		<td>Mailen:</td>
		<td align="left"><input name="mail" type="checkbox" /></td>
	</tr>
	<tr>
		<td>Mailen schuld:</td>
		<td align="left"><input name="mailschuld" type="checkbox" /></td>
	</tr>
	<tr>
		<td></td>
		<td align="left"><input type="submit" name="Submit" value="Verzenden"/></td>
	</tr>
</table>
</form>