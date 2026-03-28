   <?php
$gender = "";
$dob = "";

if (isset($_POST['submit'])) {

    $nic = $_POST['nic'];

    if (strlen($nic) >= 7) {

        $year = substr($nic, 0, 4);
        $dayCount = (int) substr($nic, 4, 3);

        $months = [31,29 ,31,30,31,30,31,31,30,31,30,31];
		
		 // Month names
        //$monthNames = ["January","February","March","April","May","June","July","August","September","October","November","December"];

        // Leap year check
        if ($year % 4 == 0) {
            $months[1] = 29;
        }

        // Gender
        if ($dayCount > 500) {
            $gender = "Female";
            $dayCount -= 500;
        } else {
            $gender = "Male";
        }

        // Find month & day
        for ($i = 0; $i < 12; $i++) {
            if ($dayCount > $months[$i]) {
                $dayCount -= $months[$i];
            } else {
                $month = $i + 1;
                $day = $dayCount;
                break;
            }
        }
		
	        // DOB with month name
            // $dob = $year . " / " . $monthNames[$month - 1] . " / " . $day;
			
        $dob = $year . "/" . $month . "/" . $day; // If you want month name don't want this line
    }
}
?>
 <!DOCTYPE html>
<html>
<head>
    <title>NIC Details</title>
		
</head>
<body>

<h2>Enter NIC Number</h2>

<form method="post">
    NIC Number:
    <input type="text" name="nic" required>
    <br><br>
    <input type="submit" name="submit" value="Check">
</form>
<br>
<?php if ($gender != "") { ?>
    <h3>Results</h3>
	<P>  NIC NO: <?php echo $nic; ?><br>
    Gender: <?php echo $gender; ?><br>
    Date of Birth: <?php echo $dob; ?>
<?php } ?>
</P>
</body>
</html> 



