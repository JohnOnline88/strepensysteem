<?php

if (is_numeric($_POST['eur'])){
			if($_POST['eur']!=0){
				$prijs = $_POST['eur'] * -1;
				$aantal = $_POST['eur'];
				$sql2 = "INSERT INTO schuld(id, lid_id, product_id, actie, aantal, prijs, datum)
						VALUES(NULL, '".$_GET['pid']."', '7', '1', '".$aantal."', ".$prijs.", CURRENT_TIMESTAMP);";
				$result2 = mysql_query($sql2) or die(mysql_error());
			}
		}

$sql = "SELECT *
		FROM stamleden
		WHERE id=".$_GET['pid'].";";
$result = mysql_query($sql) or die(mysql_error());		

while ($resultaat = mysql_fetch_array($result)){		
		
	$to = "".$resultaat['email']."";
	$subject = "Stambetaling verwerkt";

	$headers = "From: ".$email_from."\n";

	$body = "Beste ".$resultaat['naam'].",\n\n";
	$body .= "Zojuist is er een betaling aan de stam verwerkt van ".$aantal." euro. Daar zijn we blij mee!.\n\n";
	$body .= "Wil je weten wat je actuele saldo is? Kijk dan op ".$url.".\n\n";
	$body .= "Groeten, \n\n";
	$body .= "Het stambestuur"; 

	$mail_sent = @mail( $to, $subject, $body, $headers );
	echo $mail_sent ? "<p>Er is tevens een bericht verzonden naar ".$resultaat['email'].".</p>" : "<p>Er is een fout opgetreden bij het verzenden van een email. 
					Anders had je ook een bericht in je mail gehad over je schuld!</p>";
	}	
//header("Location: index.php?id=54")

?>