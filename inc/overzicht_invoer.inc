<h2 class="title">Overzicht invoer</h2>
<?php

$sql = "SELECT *
		FROM stamleden
		WHERE id=".$_POST['naam'].";";
		$result = mysql_query($sql) or die(mysql_error());		
		while ($resultaat = mysql_fetch_array($result)){
			echo "<p>Voor ".$resultaat['naam']." is het volgende ingevoerd: </p>
			<table border='1'>";
			for($t=0;$t<sizeof($array_producten);$t++){
				echo "<tr>
						<td>".$array_producten[$t]."</td>
						<td>".$array_aantal[$t]."</td>
						</tr>";
				}
			echo "</table>";
			$sql2 = "SELECT SUM(prijs) AS schuld
					FROM schuld 
					WHERE lid_id = ".$_POST['naam'].";";
			$result2 = mysql_query($sql2) or die(mysql_error());		
			while ($resultaat2 = mysql_fetch_array($result2)){
				$schuld_eur = number_format($resultaat2['schuld'] ,2);
				echo "<p>Dit betekent dat ".$resultaat['naam']." nu een schuld heeft van <b>".$schuld_eur." euro</b>.</p>";
				if($resultaat2['schuld'] > 10){
					echo "<p><b>Deze schuld is naar de mening van het stambestuur teveel!!! Graag zo snel mogelijk betalen bij iemand van het stambestuur!!</b></p>";
					
					$to = "".$resultaat['email']."";
					$subject = "Stamschuld te hoog!";

					$headers = "From: Stambestuur <stambestuur@diekantankys.nl>\n";

					$body = "Beste ".$resultaat['naam']."\n\n";
					$body .= "Na het invoeren van je laatst gekochte producten op de stam is gebleken dat je schuld boven de
10 euro staat. Je schuld is op dit moment:
".number_format($resultaat2['schuld'],2)."  euro\n\n";
					$body .= "Dit is volgens het stambestuur teveel! We willen je dan ook vragen om zo snel mogelijk te betalen! Dit kan door geld over te maken naar rekening NL 70 INGB 066 323 4417 t.n.v. Hr J J den Hertog \n\n";
					$body .= "Mocht je nog vragen hebben of denk je dat er iets niet klopt beantwoord dan dit mailtje.\n\n";
					$body .= "Groeten, \n\n";
					$body .= "Het stambestuur"; 

					$mail_sent = @mail( $to, $subject, $body, $headers );
					echo $mail_sent ? "<p>Er is tevens een bericht verzonden naar ".$resultaat['email'].".</p>" : "<p>Er is een fout opgetreden bij het verzenden van een email. 
					Anders had je ook een bericht in je mail gehad over je schuld!</p>";
					}

				}

			
			}

$sql = "SELECT SUM( aantal) AS aantal
			FROM schuld
			WHERE product_id =1;";
		$result = mysql_query($sql) or die(mysql_error());		
				while ($resultaat = mysql_fetch_array($result)){
				$aantal=$resultaat['aantal']-53483;	
				$teveel=$aantal / 10;
				//$f_teveel=return number_format((float)$teveel, 2, ',', '');
					
				//echo "<p>Er zijn nu <b>".$resultaat['aantal']."</b> flesjes bier verkocht! Veel hé!</p>";
				//echo "<p>Er zijn nu <b>".$resultaat['aantal']."</b> flesjes bier verkocht! Daarvan kostte er 53483 slechts 50 eurocent en al <b>".$aantal." kostte 60 eurocent!</b> </br>
				//Hierdoor hebben wij als stamleden al ".number_format((float)$teveel, 2, ',', '')." euro meer betaald aan bier! Veel hé!</p>";
		}


/*
$sql = "SELECT SUM( aantal) AS aantal
			FROM schuld
			WHERE product_id =1;";
		$result = mysql_query($sql) or die(mysql_error());		
		while ($resultaat = mysql_fetch_array($result)){
			$aantal= $resultaat['aantal'] ;
			if ($resultaat['aantal'] > 50000){
				$sql3 = mysql_query("SELECT * FROM prijsvraag");
				$num_rows = mysql_num_rows($sql3);
				if($num_rows < 1) {
						$sql2 = "INSERT INTO prijsvraag(id, aantal, naam, tijd)
						VALUES(NULL, '".$aantal."', '".$_POST['naam']."', CURRENT_TIMESTAMP);";
						$result2 = mysql_query($sql2) or die(mysql_error());
						echo "<p><b>Eureka! Je hebt het 50000e biertje gekocht!! Daar moet op gezongen worden Hi Ha Ho! Het stambestuur maakt zo snel mogelijk bekend wie de winnaar van de prijsvraag is!</b></p>";
						echo "<p><iframe width='420' height='315' src='//www.youtube.com/embed/4O_iBqdQLzk?autoplay=1' frameborder='0' allowfullscreen></iframe></p>";
					}
				else { 
					echo "<p><b>Eureka! Er zijn ondertussen 50000 flesjes verkocht! Proost!</b></p>";
					}
				}
			else {			
					echo "<p>Er zijn nog geen 50000 flesjes bier verkocht.</p>";
//					echo "<p><iframe width='420' height='315' src='//www.youtube.com/embed/4O_iBqdQLzk?autoplay=1' frameborder='0' allowfullscreen></iframe></p>";
			}
		}		
*/		

?>
