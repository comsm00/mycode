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
			...................................................

			roman......
<!DOCTYPE HTML>
<html>
	<head></head>
	<body>
		<h2>Roman To Numerical</h2>
		<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
			Enter the No:
			<input type="text" name="roman">
			<br><br>
			
			<input type="submit" name="submit">
		</form>
		
		<?php 
			if($_SERVER["REQUEST_METHOD"]=="POST"){

				$roman = $_POST["roman"];
				$roman = strtoupper($roman);
				
				if(empty($roman)){
					echo "Enter the currect value";
				}
				else{
					$values = ["I"=>1,"V"=>5,"X"=>10,"L"=>50,"C"=>100,"D"=>500,"M"=>1000];
				
					$total = $values[$roman[0]];
					
					$i =1;
					
					while($i < strlen($roman)){
						$curr = $values[$roman[$i]];
						$prev = $values[$roman[$i-1]];
						
						if($curr > $prev){
							$total = $total +  $curr - 2*$prev;
						}
						else{
							$total = $total + $curr;
						}
						$i++;
					}
					
					echo "Decimal : ".$total;
					}
				
			}
		?>
	</body>
</html>
	...................................................
			<!DOCTYPE html>
<html>
<head>
    <title>Matrix Multiplication</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        table {
            border-collapse: collapse;
            margin-bottom: 20px;
        }
        td {
            padding: 5px;
        }
        input[type=text], input[type=number] {
            width: 60px;
            padding: 5px;
            text-align: center;
        }
        .matrix-title {
            font-weight: bold;
            margin-top: 15px;
        }
    </style>
</head>
<body>

<h2>Square Matrix Multiplication</h2>

<?php
$n = 0;

if (isset($_POST['set_size'])) {
    $n = $_POST['n'];
}
else if (isset($_POST['multiply'])) {
    $n = $_POST['n'];
}
?>

<!-- Step 1: Enter matrix size -->
<form method="post" action="">
    Enter size of square matrix (n):
    <input type="number" name="n" min="1" required value="<?php echo $n; ?>">
    <input type="submit" name="set_size" value="Create Matrices">
</form>

<?php
if ($n > 0 && isset($_POST['set_size'])) {
?>
    <!-- Step 2: Enter matrix values -->
    <form method="post" action="">
        <input type="hidden" name="n" value="<?php echo $n; ?>">

        <div class="matrix-title">Enter values for Matrix A</div>
        <table border="1">
            <?php
            for ($i = 0; $i < $n; $i++) {
                echo "<tr>";
                for ($j = 0; $j < $n; $j++) {
                    echo "<td><input type='text' name='A[$i][$j]' required></td>";
                }
                echo "</tr>";
            }
            ?>
        </table>

        <div class="matrix-title">Enter values for Matrix B</div>
        <table border="1">
            <?php
            for ($i = 0; $i < $n; $i++) {
                echo "<tr>";
                for ($j = 0; $j < $n; $j++) {
                    echo "<td><input type='text' name='B[$i][$j]' required></td>";
                }
                echo "</tr>";
            }
            ?>
        </table>

        <input type="submit" name="multiply" value="Multiply Matrices">
    </form>
<?php
}
?>

<?php
if (isset($_POST['multiply'])) {

    $n = $_POST['n'];
    $A = $_POST['A'];
    $B = $_POST['B'];

    $C = array();

    // Matrix multiplication
    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $n; $j++) {
            $C[$i][$j] = 0;
            for ($k = 0; $k < $n; $k++) {
                $C[$i][$j] = $C[$i][$j] + ($A[$i][$k] * $B[$k][$j]);
            }
        }
    }

    echo "<h3>Matrix A</h3>";
    echo "<table border='1'>";
    for ($i = 0; $i < $n; $i++) {
        echo "<tr>";
        for ($j = 0; $j < $n; $j++) {
            echo "<td>" . $A[$i][$j] . "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";

    echo "<h3>Matrix B</h3>";
    echo "<table border='1'>";
    for ($i = 0; $i < $n; $i++) {
        echo "<tr>";
        for ($j = 0; $j < $n; $j++) {
            echo "<td>" . $B[$i][$j] . "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";

    echo "<h3>Multiplication Matrix C = A × B</h3>";
    echo "<table border='1'>";
    for ($i = 0; $i < $n; $i++) {
        echo "<tr>";
        for ($j = 0; $j < $n; $j++) {
            echo "<td>" . $C[$i][$j] . "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
}
?>

</body>
</html>..............................
		
