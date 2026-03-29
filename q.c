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


----form------------------------------------------------------------------
<!DOCTYPE HTML>
<html>
	<head>
		<title>PHP Form Validation</title>
		<style>
			.error{
				color:red; 
			}
			
			div{
				border: 1px solid blue;
				margin:10px;
				padding:10px;
			}
		</style>
	</head>
	
	<body>
	<div>
		<?php
			$nameErr = $emailErr = $genderErr = "";
			$name = $email= $website= $Comment= $gender="";
			
			if($_SERVER["REQUEST_METHOD"] == "POST"){
				if(empty($_POST["name"])){
					$nameErr = "Name is required";
				}
				else{
					$name = test_input($_POST["name"]);
				}
				if(empty($_POST["email"])){
					$emailErr = "Email is required";
				}
				else{
					$email = test_input($_POST["email"]);
				}
				
				if(empty($_POST["website"])){
					$website="";
				}
				else{
					$website = test_input($_POST["website"]);
				}
				
				if(empty($_POST["Comment"])){
					$comment="";
				}
				else{
					$comment = test_input($_POST["comment"]);
				}
				if(empty($_POST["gender"])){
					$genderErr = "Gender is required";
				}
				else{
					$gender = test_input($_POST["gender"]);
				}
			}
			function test_input($data){
				$data = trim($data);
				$data = stripslashes($data);
				$data = htmlspecialchars($data);
				return $data;
			}
		?>
		<Form method= "post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" >
			<p><span class = "error">* required field</span></p>
			Name:<input type="text" name="name">
			<span class = "error">*<?php echo $nameErr;?></span><br><br>
			
			Email:<input type="email" name="email">
			<span class = "error">*<?php echo $emailErr;?></span><br><br>
			
			Website:<input type="text" name="website">
			<br><br>
			
			Comment:<textarea name="comment" rows="5" cols= "40"></textarea>
			<br><br>
			
			Gender:
			<input type="radio" name="gender" value="Female">Female
			<input type="radio" name="gender" value="Male">Male
			<input type="radio" name="gender" value="Other">Other
			<span class = "error">*<?php echo $genderErr;?></span><br><br>
			
			<input type ="submit" name="submit" value= "Submit">
		</form>
	</div>	
	</body>
	
	
</html>
