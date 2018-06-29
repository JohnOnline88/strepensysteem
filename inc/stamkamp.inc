<?php
/******************************
*  Script:   Form Mail        *
*  Versie:   4.0              *
*  Author:   SkYcE            *
*  Released: 07-12-2006       *
******************************/

//Set sessie voor flood optie
session_start();

/*
** Variabelen instellen
*/

// Naam voor als afzender van het bevestigingsmailtje
$var_name      = "Stamkamp";
// Het mail adres waarnaar de data verstuurd moet worden en afzender adres
$var_email     = "webmaster@diekantankys.nl";
// Bevestigingsmail naar de verstuurder aanzetten (true = aan / false = uit)
$var_confirm   = true;
// Om flooden te voorkomen (true = aan / false = uit)
$var_noflood   = true;
//Bericht wat een bezoeker te zien krijgt als er sprake is van flooden
$var_flood_msg = "U bent aan het flooden!";
//Aantal flood seconden dat het formulier buiten gebruik moet zijn na het versturen van een bericht
$var_flood_sec = 20;
// Geblokkeerde ip adressen, nieuw ip adres toevoegen is nieuwe waarde in de array
$var_ban_ips   = array('255.255.255.0');
// Bericht wat een bezoeker te zien krijgt indien diegene geblokkeerd is
$var_ban_msg   = "U bent geblokkeerd van het versturen van het inschrijf formulier.";

/*
** Hieronder niks veranderen, tenzij je weet wat je doet
*/

//Functie voor ipadres verkrijgen
$ipadres = $_SERVER['REMOTE_ADDR'];
//Host verkrijgen
$hostmask = gethostbyaddr($ipadres);
// Formulier weergeven
$form_view = true;
//Formulier versturen, als er iets misgaat word $ok = false
$ok = true;
// Bestandsnaam verkrijgen
$filename = basename($_SERVER['PHP_SELF']);
// Errors
$error = '';

function checkemail($email)
{
    // Kijk of er een @ in zit, zo nee false
    if(!stristr($email, '@'))
    {
        return false;
    }
    $email_split = explode("@", $email);
    // Er mag slecht één @ inzitten dus het array moet 2 records tellen
    if(count($email_split) != 2)
    {
        return false;
    }
    $email_user = $email_split[0];
    $email_host = $email_split[1];
    // Kijk of er MX-servers zijn, zo nee false
    if(!getmxrr($email_host, $var))
    {
        return false;
    }
    // Kijk of het usergedeelte okee is, zo nee false
    if(!preg_match("/^[0-9a-z]([-_.~]?[0-9a-z])*$/i", $email_user))
    {
        return false;
    }
    return true;
}

if($_SERVER['REQUEST_METHOD'] == 'POST') {
    //Validate form
    if(!trim($_POST['voornaam'])) {
        $ok = false;
        $error .= '- Er is geen voornaam ingevuld<br />';
    }
	if(!trim($_POST['achternaam'])) {
        $ok = false;
        $error .= '- Er is geen achternaam ingevuld<br />';
    }
    if(!checkemail($_POST['email'])) { 
        $ok = false; 
        $error .= '- Er is geen geldig e-mailadres ingevuld<br />'; 
    }
	
// Gegevens in database opslaan
		$voornaam = $_POST['voornaam'];
		$achternaam = $_POST['achternaam'];
		$geboortedatum = $_POST['geboortedatum'];
		$straat = $_POST['straat'];
		$postcode = $_POST['postcode'];
		$plaats = $_POST['plaats'];
		$telefoon = $_POST['telefoon'];
		$email = $_POST['email'];
		$naam_nood = $_POST['naam_nood'];
		$verzekering = $_POST['verzekering'];
		$polisnummer = $_POST['polisnummer'];
		$dieet = $_POST['dieet'];
		$huisarts = $_POST['huisarts'];
		$aanvullend = $_POST['aanvullend'];
		$rijden = $_POST['rijden'];
		$aantal_personen = $_POST['aantal_personen'];
		$ip = $ipadres;
		$tijd = date('d-m-Y G:i:s');
		$sql ="INSERT INTO stamkamp(voornaam, achternaam, geboortedatum, straat, postcode, plaats, telefoon, email, naam_nood, verzekering, polisnummer, dieet, huisarts, aanvullend, rijden, aantal_personen, ip, tijd)
				VALUES ('".$voornaam."', '".$achternaam."', '".$geboortedatum."', '".$straat."', '".$postcode."', '".$plaats."', '".$telefoon."', '".$email."', '".$naam_nood."', '".$verzekering."', '".$polisnummer."', '".$dieet."', '".$huisarts."', '".$aanvullend."', '".$rijden."', '".$aantal_personen."', '".$ip."', '".$tijd."');";

		$result = mysql_query($sql);
       
// E-mail naar $var_email (webmaster)
$msg_2_admin = "
   Voornaam:				".$_POST['voornaam']."
   Achternaam:				".$_POST['achternaam']."
   Geboortedatum:			".$_POST['geboortedatum']."
   Adres:					".$_POST['straat']."
   Postcode:				".$_POST['postcode']."
   
   Plaats:					".$_POST['plaats']."
   
   Telefoonnummer bij nood:	".$_POST['telefoon']."
   
   Naam bij nood:			".$_POST['naam_nood']."
   E-mailadres:				".$_POST['email']."
   Verzekering:				".$_POST['verzekering']."
   
   Polisnummer:				".$_POST['polisnummer']."
   
   Dieet:					".$_POST['dieet']."
   Huisarts+telefoonnummer:	".$_POST['huisarts']."
   Aanvullende gegevens:	".$_POST['aanvullend']."
   
   Kan rijden:				".$_POST['rijden']."
   Aantal meerijdende personen:	".$_POST['aantal_personen']."
======================================================================
Note:        ".$_POST['voornaam']." ".$_POST['achternaam']." stuurde deze email op ".date('d-m-Y')." om ".date('H:i').".

             Het IP adres van ".$_POST['voornaam']." is: ".$ipadres."
             Het hostadres van ".$_POST['voornaam']." is: ".$hostmask."";

// E-mail naar $_POST['email'] (poster)
$msg_2_poster = "Hallo ".$_POST['voornaam']." ".$_POST['achternaam'].",

Je bent ingeschreven voor Stamkamp 2012 met onderstaande gegevens: 
======================================================================
    Voornaam:				".$_POST['voornaam']."
   Achternaam:				".$_POST['achternaam']."
   Geboortedatum:			".$_POST['geboortedatum']."
   Adres:					".$_POST['straat']."
   Postcode:				".$_POST['postcode']."
   
   Plaats:					".$_POST['plaats']."
   
   Telefoonnummer bij nood:	".$_POST['telefoon']."
   
   Naam bij nood:			".$_POST['naam_nood']."
   E-mailadres:				".$_POST['email']."
   Verzekering:				".$_POST['verzekering']."
   
   Polisnummer:				".$_POST['polisnummer']."
   
   Dieet:					".$_POST['dieet']."
   Huisarts+telefoonnummer:	".$_POST['huisarts']."
   Aanvullende gegevens:	".$_POST['aanvullend']."
   
   Kan rijden:				".$_POST['rijden']."
   Aantal meerijdende personen:	".$_POST['aantal_personen']."
======================================================================

Om de inschrijving helemaal compleet te maken willen wij je vragen om het kampgeld, 150 euro, te storten op girorekening 4074156 t.n.v. HR. O.P. Bubberman o.v.v. je naam.

Mochten er gegevens niet kloppen, of heb je jezelf helemaal niet ingeschreven dan kunnen wij de inschrijving aanpassen/verwijderen. Daarvoor kan geantwoord worden op dit mailtje.

Met vriendelijke groet,
 
Het stambestuur";

    if(in_array($ipadres,$var_ban_ips)) {
        echo $var_ban_msg;
        $form_view = false;
    } elseif ($var_noflood == true && (time()-$_SESSION['"antiflood"']) <= $var_flood_sec) {
        echo $var_flood_msg;
        $form_view = false;
    } elseif ($ok == true) {
        @$send = mail($var_email,
                      "Stamkamp inschrijving van: ".$_POST['voornaam']." ".$_POST['achternaam']."" ,
                      $msg_2_admin,
                      "From: ".$_POST['voornaam']." ".$_POST['achternaam']." <".$_POST['email'].">");
       
        if($send == 1) { 
            if($var_confirm == true){ 
                mail($_POST['email'],
                     "Bevestiging inschrijving Stamkamp: ".$_POST['voornaam']."  ".$_POST['achternaam']." ",
                     $msg_2_poster,
                     "From: ".$var_name."<".$var_email.">"); 
            }
           
            echo'Beste '.$_POST['voornaam'].' '.$_POST['achternaam'].', je inschrijving is verzonden, bedankt!';
           
            if($var_confirm == true){ 
                echo'<br /><br />Er is een bevestigingsmail onderweg met wat je hebt ingevuld.';
            }
        }else{ 
            echo'Beste '.$_POST['voornaam'].', Je inschrijving is helaas niet verzonden.<br /><br />
            Er is een fout opgetreden bij het verzenden. Wij zullen proberen het probleem zo snel mogelijk
            te verhelpen.<br /><br />
           
            Mocht dit probleem na enkele dagen niet verholpen zijn,neem dan contact op met 
            <a href="mailto:'.$var_email.'">John</a><br /><br />
           
            Bedankt voor je medewerking.'; 
        }
       
        $form_view = false;
       
        $_SESSION['"antiflood"'] = time();
    }
}

/*
** Formulier
*/
if($form_view == true) {
    echo '
    <html>
    <head>
        <title>Inschrijven Stamkamp</title>
        <style type="text/css">
            body {
                font-family: Verdana;
                font-size:12px;
            }
            td {
                font-family: Verdana;
                font-size:12px;
            }
        </style>
    </head>
   
    <body>';
   
    if($error != '') {
        echo '<font style="color:#FF0000;"><b>'.$error.'</b></font><br />';
    }
	echo '<p>Door onderstaand formulier in te vullen en op versturen te drukken kun je jezelf opgeven voor het Stamkamp</p>';
   
    echo '<form method="POST" style="border:0px; margin:0px; padding:0px;">
    <table width="55%" cellspacing="0" cellpadding="5">
    <tr>
        <td align="right"><b>Voornaam:</b></td>
        <td><input type="text" name="voornaam" size="40" maxlength="40" value="'.(isset($_POST['voornaam']) ? $_POST['voornaam'] : '').'"></td>
    </tr>
	<tr>
        <td align="right"><b>Achternaam:</b></td>
        <td><input type="text" name="achternaam" size="40" maxlength="40" value="'.(isset($_POST['achternaam']) ? $_POST['achternaam'] : '').'"></td>
    </tr>
	<tr>
        <td align="right"><b>Geboortedatum:</b></td>
        <td><input type="text" name="geboortedatum" size="40" maxlength="40" value="'.(isset($_POST['geboortedatum']) ? $_POST['geboortedatum'] : '').'"></td>
    </tr>
	<tr>
        <td align="right"><b>Adres:</b></td>
        <td><input type="text" name="straat" size="40" maxlength="40" value="'.(isset($_POST['straat']) ? $_POST['straat'] : '').'"></td>
    </tr>
	<tr>
        <td align="right"><b>Postcode:</b></td>
        <td><input type="text" name="postcode" size="40" maxlength="40" value="'.(isset($_POST['postcode']) ? $_POST['postcode'] : '').'"></td>
    </tr>
	<tr>
        <td align="right"><b>Plaats:</b></td>
        <td><input type="text" name="plaats" size="40" maxlength="40" value="'.(isset($_POST['plaats']) ? $_POST['plaats'] : '').'"></td>
    </tr>
   <tr>
        <td align="right"><b>Telefoonnummer bij nood:</b></td>
        <td><input type="text" name="telefoon" size="40" maxlength="40" value="'.(isset($_POST['telefoon']) ? $_POST['telefoon'] : '').'"></td>
    </tr>
	<tr>
        <td align="right" valign="top"><b>Naam bij nood:</b></td>  
        <td><textarea rows="3" cols="40" name="naam_nood" style="overflow:auto;">'.(isset($_POST['naam_nood']) ? $_POST['naam_nood'] : '').'</textarea></td>
    </tr>
	
    <tr>
        <td align="right"><b>E-mailadres:</b></td>
        <td><input type="text" name="email" size="40" maxlength="40" value="'.(isset($_POST['email']) ? $_POST['email'] : '').'"></td>
    </tr>
	<tr>
        <td align="right"><b>Verzekering:</b></td>
        <td><input type="text" name="verzekering" size="40" maxlength="40" value="'.(isset($_POST['verzekering']) ? $_POST['verzekering'] : '').'"></td>
    </tr>
	<tr>
        <td align="right"><b>Polisnummer:</b></td>
        <td><input type="text" name="polisnummer" size="40" maxlength="40" value="'.(isset($_POST['polisnummer']) ? $_POST['polisnummer'] : '').'"></td>
    </tr>
	<tr>
        <td align="right" valign="top"><b>Dieet:</b></td>  
        <td><textarea rows="8" cols="40" name="dieet" style="overflow:auto;">'.(isset($_POST['dieet']) ? $_POST['dieet'] : '').'</textarea></td>
    </tr>
	<tr>
        <td align="right" valign="top"><b>Huisarts + telefoonnummer:</b></td>  
        <td><textarea rows="3" cols="40" name="huisarts" style="overflow:auto;">'.(isset($_POST['huisarts']) ? $_POST['huisarts'] : '').'</textarea></td>
    </tr>
    <tr>
        <td align="right" valign="top"><b>Aanvullende gegevens:</b></td>  
        <td><textarea rows="8" cols="40" name="aanvullend" style="overflow:auto;">'.(isset($_POST['aanvullend']) ? $_POST['aanvullend'] : '').'</textarea></td>
    </tr>
<tr>
        <td align="right"><b>Kan rijden:</b></td>
        <td><INPUT TYPE="radio" NAME="rijden" VALUE="Ja">Ja <INPUT TYPE="radio" NAME="rijden" VALUE="Nee">Nee</td>
    </tr>
<tr>
        <td align="right"><b>Aantal meerijdende personen:</b></td>
        <td><input type="text" name="aantal_personen" size="40" maxlength="40" value="'.(isset($_POST['aantal_personen']) ? $_POST['aantal_personen'] : '').'"></td>
    </tr>
    <tr>
        <td>&nbsp;</td>
        <td><input type="submit" name="submit" value="Versturen"></td>
    </tr>
    </table>
    </form>
    </body>
    </html>';
}
?> 
