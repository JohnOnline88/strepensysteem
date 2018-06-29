<?php
ob_start();
include 'inc/config.inc';
include 'inc/mysql.inc';

session_start();
extract($_SESSION);  
if(isset($level)){
	$levelid = $level;
	}
else{
	$levelid = 0;
	}

if (isset($_GET["id"])){
	$pageid = $_GET['id'];
	}
else{
	$pageid = 1;
	}
	
$sql = "SELECT * FROM pagina WHERE id='".$pageid."' AND level='".$levelid."'";
$result = mysql_query($sql) or die(mysql_error());
	 if(mysql_num_rows($result) == 1) {
	    $regel = mysql_fetch_array($result);

	    $pagina = "inc/".$regel[link].".inc";  

	} else {
		$pagina = "inc/errorrights.inc";
		} 

?>

<?php

if (file_exists($pagina))

{	
	include 'inc/header.inc';
	include($pagina);
	include 'inc/footer.inc';

}
else
{
		include 'inc/header.inc';
      	include('inc/error404.inc');
		include 'inc/footer.inc';
}
ob_flush();
?>



