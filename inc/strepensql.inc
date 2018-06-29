<?php
$t = 0;
if($_POST['naam'] != naam){

$array_producten = array("0" => Product);
$array_aantal = array("0" => Aantal);
$sql = "SELECT *
		FROM product;";
		$result = mysql_query($sql) or die(mysql_error());		
		while ($resultaat = mysql_fetch_array($result)){
			list($id, $aantal) = split('[;]', $_POST[$resultaat['id']]);			
			$prijs = $aantal * $resultaat['prijs'];
			if($aantal < 0 or $aantal > 24) {
				echo "<p>Je hebt een ongeldig aantal ingevoerd bij een product! Deze is niet verwerkt!</p>";
			}
			elseif($aantal!=0){
				if($_POST['naam']==48){
				//Er wordt contant betaald!
				$prijs=0;
				}
				$array_producten [$t] = $resultaat['omschrijving'];
				$array_aantal [$t] = $aantal;
				$sql2 = "INSERT INTO schuld(id, lid_id, product_id, actie, aantal, prijs, datum)
						VALUES(NULL, '".$_POST['naam']."', '".$id."', '0', '".$aantal."', '".$prijs."', CURRENT_TIMESTAMP);";
				$result2 = mysql_query($sql2) or die(mysql_error());
				$t = $t + 1;
			}
		}
include 'inc/overzicht_invoer.inc';
}

else{
echo "<p>Je hebt geen naam ingevuld!</p>";
}


?>