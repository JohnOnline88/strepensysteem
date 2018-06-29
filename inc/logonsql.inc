<?php 

extract($_POST);

if($id != "" && $pw != "") {
  $id = mysql_real_escape_string($id);
  $pw = mysql_real_escape_string($pw);
	$query = "SELECT *
			  FROM user
			  WHERE naam='".$id."'
			  AND wachtwoord='".md5($pw)."'";
	$result = mysql_query($query) or die(mysql_error());

    if(mysql_num_rows($result) == 1) {
	    $regel = mysql_fetch_array($result);
		$_SESSION['userid'] = $regel['id'];
		$_SESSION['username'] = $regel['naam'];
		$_SESSION['hash'] = $regel['wachtwoord'];
	    $_SESSION['level'] = $regel['ulevel'];

	    header("Location: index.php");
	}
	else{
		$query = "SELECT *
			  FROM user
			  WHERE naam='".$id."'";
	$result = mysql_query($query) or die(mysql_error());
	if(mysql_num_rows($result) == 1) {
		echo "Wachtwoord fout!";
		}
		else 
			echo "Gebruiker bestaat niet!";
	}
		
		
	
	
}
else
		echo "<p>Niet alles ingevuld lul!</p>";
?>