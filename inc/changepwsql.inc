<?php 

extract($_POST);
if($_SESSION['hash'] == md5($pwold))
{
if(isset($pw1) && isset($pw2)){
	if($pw1 == $pw2){
	$query = "UPDATE user
			  SET wachtwoord='".md5($pw1)."'
			  WHERE id='".$_SESSION['userid']."';";
	$result = mysql_query($query) or die(mysql_error());
		$_SESSION['hash'] = md5($pw1);
		echo "Wachtwoord veranderd!";
	}
	else
		echo "Nieuwe wachtwoorden niet gelijk!";
}
	else
		echo "<p>Niet alles ingevuld!</p>";
}
else
	echo "Oude wachtwoord niet goed!";

?>