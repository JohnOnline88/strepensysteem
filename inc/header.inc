<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta name="robots" content="noindex, nofollow" />

<title><?php 
$pageid = $_GET['id'];
if($pageid == null)
	$pageid = 1;
if(isset($level)){
	$levelid = $level;
	}
else{
	$levelid = 0;
	}
	
$sql = "SELECT * FROM pagina WHERE id='".$pageid."' AND level='".$levelid."'";
$result = mysql_query($sql) or die(mysql_error());
if(mysql_num_rows($result) == 1) {
	    $regel = mysql_fetch_array($result);
		echo "".$regel['naam']."";
		}

?></title>

<link rel="stylesheet" type="text/css" href="orangeandblack/style.css" title="Default" />

</head>

<body>
<div id="header-wrapper">
	<div id="header">
		<div id="menu">
			<ul>
				<?php

				$sql = "SELECT * FROM pagina WHERE level='".$levelid."' ORDER BY id";
				$result = mysql_query($sql) or die(mysql_error());
				while ($resultaat = mysql_fetch_array($result))
				{
					if($resultaat['zichtbaar'] == 1)
					{
						echo "<li ";
						if($pageid == $resultaat['id']) 
						{
						echo "class='current_page_item' ";
						}
						echo "><a href=\"index.php?id=".$resultaat['id']."\">".$resultaat['naam']."</a></li>";
						}
				}
				?>
			</ul>
		</div>
	</div>
</div>
<div id="page">
	<div id="logo">
		<a name="boven"></a>
		<h1><a href="index.php">Strepen <span class="text1">Systeem</span></a></h1>
		<p><em>{ Hét strepensysteem van stam Eureka! }</em></p>
	</div>
	<hr />
	<div id="content">
		<div class="post">
			<div class="entry">

