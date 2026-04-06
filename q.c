**********************************************************************************
class Student{
	String name;
	int marks;
	
	void displayDetails(){
		System.out.println("Name: " + name);
		System.out.println("Marks: " + marks);
	}
}

public class Main{
	public static void main(String args[]){
		
		Student s1 = new Student();
		Student s2 = new Student();
		Student s3 = new Student();
		
		s1.name = "Akeef";
		s1.marks = 80;
		
		s2.name = "Ahmed";
		s2.marks = 85;
		
		s3.name = "Mubeen";
		s3.marks = 90;
		
		s1.displayDetails();
		s2.displayDetails();
		s3.displayDetails();
	}
}
********************************************************************************
class Car{
	String brand;
	String color;
	int speed;
	
	void drive(){
		speed += 10;
		
		System.out.println(brand + " " + "is driving. Current speed: " + speed);
	}
	
	void breake(){
		speed -= 5;
		
		System.out.println(brand + " " + "is breaking. Current speed: " + speed);
		
	}
}

public class Main1{
	public static void main(String args[]){
		
		Car c1 = new Car();
		Car c2 = new Car();
		
		c1.brand = "Audi";
		c1.color = "Blue";
		c1.speed = 120;
		
		c2.brand = "Benz";
		c2.color = "Black";
		c2.speed = 130;
		
		c1.drive();
		c1.breake();
		
		System.out.println();
		
		c2.drive();
		c2.breake();
	}
}
************************************************************************************
class Circle{
	double radius;
	
	/*double getArea(){							
		return Math.PI * radius *radius;
	}*/
	
	void getArea(){
		double area = Math.PI * radius *radius;
		System.out.println("Area is: " + area);
	}
	
	/*double getPerimeter(){
		return 2 * Math.PI * radius;
	}*/
	
	void getPerimeter(){
		double perimeter = 2 * Math.PI * radius;
		System.out.println("Perimeter is: " + perimeter);
	}
}

public class Main2{
	public static void main(String args[]){
		
		Circle c1 = new Circle();
		Circle c2 = new Circle();
		
		c1.radius = 4;
		c2.radius = 5;
		
		System.out.println("Circle 1:");
        System.out.println("Radius: " + c1.radius);
        c1.getArea();
        c1.getPerimeter();

        System.out.println();

        
        System.out.println("Circle 2:");
        System.out.println("Radius: " + c2.radius);
        c2.getArea();
        c2.getPerimeter();
	}
}
******************************************************************************************
class BankAccount {
    private double balance;

    public void deposit(double amount) {
        balance += amount;
    }

    public double getBalance() {
        return balance;
    }
}

public class Main3 {
    public static void main(String[] args) {

        BankAccount account = new BankAccount();

        account.deposit(2000);
		account.deposit(500);

        System.out.println("Balance: " + account.getBalance());

    }
*******************************************************************************************
abstract class Player {
    int playerID;
    String name;
    String country;
    int[] scores;

    public Player(int playerID, String name, String country, int[] scores) {
        this.playerID = playerID;
        this.name = name;
        this.country = country;
        this.scores = scores;
    }

    public int getPlayerID() {
        return playerID;
    }

    public String getName() {
        return name;
    }

    public String getCountry() {
        return country;
    }

    abstract void addScore(int score);
    abstract void printDetails();
}

class Batsman extends Player {
    int runs;

    public Batsman(int playerID, String name, String country, int[] scores) {
        super(playerID, name, country, scores);
        calculateRuns();
    }

    private void calculateRuns() {
        runs = 0;
        for (int s : scores) {
            runs += s;
        }
    }

    public int getRuns() {
        return runs;
    }

    @Override
    void addScore(int score) {
        if (score >= 0 && score <= 100) {
            int[] newScores = new int[scores.length + 1];
            System.arraycopy(scores, 0, newScores, 0, scores.length);
            newScores[scores.length] = score;
            scores = newScores;
            runs += score;
        }
    }

    @Override
    void printDetails() {
        System.out.println("\nBatsman ID: " + playerID);
        System.out.println("Name: " + name);
        System.out.println("Country: " + country);
        System.out.print("Scores: ");
        for (int s : scores) System.out.print(s + " ");
        System.out.println("\nTotal Runs: " + runs);
    }
}

class Bowler extends Player {
    int wickets;

    public Bowler(int playerID, String name, String country, int[] scores) {
        super(playerID, name, country, scores);
        calculateWickets();
    }

    private void calculateWickets() {
        wickets = 0;
        for (int s : scores) {
            wickets += s;
        }
    }

    public int getWickets() {
        return wickets;
    }

    @Override
    void addScore(int score) {
        if (score >= 0 && score <= 10) {
            int[] newScores = new int[scores.length + 1];
            System.arraycopy(scores, 0, newScores, 0, scores.length);
            newScores[scores.length] = score;
            scores = newScores;
            wickets += score;
        }
    }

    @Override
    void printDetails() {
        System.out.println("\nBowler ID: " + playerID);
        System.out.println("Name: " + name);
        System.out.println("Country: " + country);
        System.out.print("Scores: ");
        for (int s : scores) System.out.print(s + " ");
        System.out.println("\nTotal Wickets: " + wickets);
    }
}

public class CricketApp {
    public static void main(String[] args) {

        // Batsmen
        Batsman[] batsmen = {
            new Batsman(1, "Sachin Tendulkar", "India", new int[]{42,0,61,15,0,100,23,64,41,0,26}),
            new Batsman(2, "Virat Kohli", "India", new int[]{0,25,10,60,11,0,40,11,0,2,0}),
            new Batsman(3, "MS Dhoni", "India", new int[]{6,22,48,0,11,69,0,21,19,0,42}),
            new Batsman(4, "Ricky Ponting", "Australia", new int[]{11,0,28,0,64,18,45,26,0,11,0}),
            new Batsman(5, "Brian Lara", "West Indies", new int[]{0,13,21,47,0,69,17,0,12,0,40})
        };

        // Bowlers
        Bowler[] bowlers = {
            new Bowler(1, "Muralitharan", "Sri Lanka", new int[]{0,10,6,8,0,1,0,2,4,0,6}),
            new Bowler(2, "Shane Warne", "Australia", new int[]{6,0,1,0,2,0,4,10,0,6,8}),
            new Bowler(3, "Hasaranga", "Sri Lanka", new int[]{0,1,0,6,8,4,2,0,6,0,10}),
            new Bowler(4, "McGrath", "Australia", new int[]{4,2,6,0,10,0,1,8,6,0,0}),
            new Bowler(5, "Dale Steyn", "South Africa", new int[]{0,4,0,2,1,6,10,0,8,6,0})
        };

        // Print all
        for (Batsman b : batsmen) b.printDetails();
        for (Bowler b : bowlers) b.printDetails();

        // Add score 14 to Batsman 1
        batsmen[0].addScore(14);

        // Highest Runs
        Batsman topBatsman = batsmen[0];
        for (Batsman b : batsmen) {
            if (b.getRuns() > topBatsman.getRuns()) {
                topBatsman = b;
            }
        }
        System.out.println("\nTop Batsman:");
        topBatsman.printDetails();

        // Highest Wickets
        Bowler topBowler = bowlers[0];
        for (Bowler b : bowlers) {
            if (b.getWickets() > topBowler.getWickets()) {
                topBowler = b;
            }
        }
        System.out.println("\nTop Bowler:");
        topBowler.printDetails();

        // Players from Australia
        System.out.println("\nPlayers from Australia:");
        for (Batsman b : batsmen) {
            if (b.getCountry().equals("Australia")) b.printDetails();
        }
        for (Bowler b : bowlers) {
            if (b.getCountry().equals("Australia")) b.printDetails();
        }
    }
}
************************************************************************************************
import java.util.Scanner;

public class SeatReservation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int rows = 5;
        int cols = 8;
        String[][] seats = new String[rows][cols];

        // Assign seat numbers
        int seatNo = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                seats[i][j] = String.valueOf(seatNo++);
            }
        }

        while (true) {
            // Display seats
            System.out.println("\nSeat Layout:");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    System.out.print(seats[i][j] + "\t");
                }
                System.out.println();
            }

            System.out.print("\nEnter seat number (0 to exit): ");
            int input = sc.nextInt();

            if (input == 0) {
                System.out.println("Exiting...");
                break;
            }

            boolean found = false;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (seats[i][j].equals(String.valueOf(input))) {
                        seats[i][j] = "X";
                        System.out.println("Seat successfully reserved");
                        found = true;
                    } else if (seats[i][j].equals("X") && input == (i * cols + j + 1)) {
                        System.out.println("Ok (Already Reserved)");
                        found = true;
                    }
                }
            }

            if (!found) {
                System.out.println("Invalid seat number!");
            }
        }

        sc.close();
    }
}
******************************************************************************************************************
class Customer {
    private int customerId;
    private String name;
    private String address;

    public Customer(int customerId, String name, String address) {
        this.customerId = customerId;
        setName(name);
        this.address = address;
    }

    // Read-only customerId
    public int getCustomerId() {
        return customerId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name != null && !name.trim().isEmpty()) {
            this.name = name;
        } else {
            this.name = "Unknown";
        }
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }
}

abstract class UtilityAccount {
    private Customer customer;
    private double unitsConsumed;
    private double billAmount;

    public UtilityAccount(Customer customer, double unitsConsumed) {
        this.customer = customer;
        setUnitsConsumed(unitsConsumed);
    }

    public Customer getCustomer() {
        return customer;
    }

    public double getUnitsConsumed() {
        return unitsConsumed;
    }

    public void setUnitsConsumed(double unitsConsumed) {
        if (unitsConsumed >= 0) {
            this.unitsConsumed = unitsConsumed;
        } else {
            this.unitsConsumed = 0;
        }
    }

    public double getBillAmount() {
        return billAmount;
    }

    protected void setBillAmount(double billAmount) {
        this.billAmount = billAmount;
    }

    public abstract void calculateBill();
    public abstract void generateBill();
}

class ElectricityAccount extends UtilityAccount {
    private final double RATE = 6.0;

    public ElectricityAccount(Customer customer, double unitsConsumed) {
        super(customer, unitsConsumed);
    }

    @Override
    public void calculateBill() {
        double amount = getUnitsConsumed() * RATE;

        if (getUnitsConsumed() > 300) {
            amount = amount + (amount * 0.10);
        }

        setBillAmount(amount);
    }

    @Override
    public void generateBill() {
        calculateBill();
        System.out.println("----- Electricity Bill -----");
        System.out.println("Customer ID   : " + getCustomer().getCustomerId());
        System.out.println("Customer Name : " + getCustomer().getName());
        System.out.println("Address       : " + getCustomer().getAddress());
        System.out.println("Units         : " + getUnitsConsumed());
        System.out.println("Bill Amount   : $" + getBillAmount());
        System.out.println();
    }
}

class WaterAccount extends UtilityAccount {
    private final double RATE = 2.0;

    public WaterAccount(Customer customer, double unitsConsumed) {
        super(customer, unitsConsumed);
    }

    @Override
    public void calculateBill() {
        double amount = getUnitsConsumed() * RATE;

        if (getUnitsConsumed() > 500) {
            amount = amount + 150;
        }

        setBillAmount(amount);
    }

    @Override
    public void generateBill() {
        calculateBill();
        System.out.println("------- Water Bill -------");
        System.out.println("Customer ID   : " + getCustomer().getCustomerId());
        System.out.println("Customer Name : " + getCustomer().getName());
        System.out.println("Address       : " + getCustomer().getAddress());
        System.out.println("Units         : " + getUnitsConsumed());
        System.out.println("Bill Amount   : $" + getBillAmount());
        System.out.println();
    }
}

public class BillingApp {
    public static void main(String[] args) {
        Customer c1 = new Customer(101, "Risi", "Trincomalee");
        Customer c2 = new Customer(102, "Ahamed", "Kinniya");
        Customer c3 = new Customer(103, "Nizam", "Batticaloa");

        UtilityAccount[] accounts = new UtilityAccount[3];
        accounts[0] = new ElectricityAccount(c1, 350);
        accounts[1] = new WaterAccount(c2, 600);
        accounts[2] = new ElectricityAccount(c3, 250);

        for (UtilityAccount acc : accounts) {
            acc.generateBill();
        }
    }
}
***************____________****************************************************
import java.util.Scanner;

class Customer {
    private int customerId;
    private String name;
    private String address;

    public Customer(int customerId, String name, String address) {
        this.customerId = customerId;
        setName(name);
        setAddress(address);
    }

    public int getCustomerId() {
        return customerId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name != null && !name.trim().isEmpty()) {
            this.name = name;
        } else {
            this.name = "Unknown";
        }
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        if (address != null && !address.trim().isEmpty()) {
            this.address = address;
        } else {
            this.address = "No Address";
        }
    }
}

abstract class BankAccount {
    private Customer customer;
    private String accountNumber;
    private double balance;

    public BankAccount(Customer customer, String accountNumber, double balance) {
        this.customer = customer;
        this.accountNumber = accountNumber;
        if (balance >= 0) {
            this.balance = balance;
        } else {
            this.balance = 0;
        }
    }

    public Customer getCustomer() {
        return customer;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    protected void setBalance(double balance) {
        this.balance = balance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Invalid withdraw amount or insufficient balance.");
        }
    }

    public abstract void displayAccountDetails();
}

class SavingsAccount extends BankAccount {
    private final double INTEREST_RATE = 0.05;
    private final double MIN_BALANCE = 1000;

    public SavingsAccount(Customer customer, String accountNumber, double balance) {
        super(customer, accountNumber, balance);
    }

    public void addInterest() {
        double interest = getBalance() * INTEREST_RATE;
        setBalance(getBalance() + interest);
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && (getBalance() - amount) >= MIN_BALANCE) {
            setBalance(getBalance() - amount);
        } else {
            System.out.println("Cannot withdraw. Minimum balance of 1000 must be maintained.");
        }
    }

    @Override
    public void displayAccountDetails() {
        System.out.println("\n----- Savings Account -----");
        System.out.println("Customer ID    : " + getCustomer().getCustomerId());
        System.out.println("Customer Name  : " + getCustomer().getName());
        System.out.println("Address        : " + getCustomer().getAddress());
        System.out.println("Account Number : " + getAccountNumber());
        System.out.println("Balance        : " + getBalance());
        System.out.println("Interest Rate  : 5%");
    }
}

class CurrentAccount extends BankAccount {
    private final double SERVICE_CHARGE = 500;

    public CurrentAccount(Customer customer, String accountNumber, double balance) {
        super(customer, accountNumber, balance);
    }

    public void applyServiceCharge() {
        if (getBalance() < 500) {
            setBalance(getBalance() - SERVICE_CHARGE);
        }
    }

    @Override
    public void displayAccountDetails() {
        System.out.println("\n----- Current Account -----");
        System.out.println("Customer ID    : " + getCustomer().getCustomerId());
        System.out.println("Customer Name  : " + getCustomer().getName());
        System.out.println("Address        : " + getCustomer().getAddress());
        System.out.println("Account Number : " + getAccountNumber());
        System.out.println("Balance        : " + getBalance());
        System.out.println("Service Charge : 500 if balance < 500");
    }
}

public class BankApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of accounts: ");
        int n = sc.nextInt();
        sc.nextLine();

        BankAccount[] accounts = new BankAccount[n];

        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Account " + (i + 1));

            System.out.print("Enter Customer ID: ");
            int customerId = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Customer Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Address: ");
            String address = sc.nextLine();

            Customer customer = new Customer(customerId, name, address);

            System.out.print("Enter Account Number: ");
            String accountNumber = sc.nextLine();

            System.out.print("Enter Initial Balance: ");
            double balance = sc.nextDouble();

            System.out.print("Enter Account Type (1 for Savings, 2 for Current): ");
            int choice = sc.nextInt();

            if (choice == 1) {
                accounts[i] = new SavingsAccount(customer, accountNumber, balance);
            } else {
                accounts[i] = new CurrentAccount(customer, accountNumber, balance);
            }

            System.out.print("Enter deposit amount: ");
            double depositAmount = sc.nextDouble();
            accounts[i].deposit(depositAmount);

            System.out.print("Enter withdraw amount: ");
            double withdrawAmount = sc.nextDouble();
            accounts[i].withdraw(withdrawAmount);

            if (accounts[i] instanceof SavingsAccount) {
                ((SavingsAccount) accounts[i]).addInterest();
            } else if (accounts[i] instanceof CurrentAccount) {
                ((CurrentAccount) accounts[i]).applyServiceCharge();
            }

            sc.nextLine();
        }

        System.out.println("\n========== ACCOUNT DETAILS ==========");
        for (BankAccount acc : accounts) {
            acc.displayAccountDetails();
        }

        sc.close();
    }
}



******************************************************************************************************8
import java.util.Scanner;

class Customer {
    private int customerId;
    private String name;
    private String address;

    public Customer(int customerId, String name, String address) {
        this.customerId = customerId;
        setName(name);
        setAddress(address);
    }

    public int getCustomerId() {
        return customerId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name != null && !name.trim().isEmpty()) {
            this.name = name;
        } else {
            this.name = "Unknown";
        }
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        if (address != null && !address.trim().isEmpty()) {
            this.address = address;
        } else {
            this.address = "No Address";
        }
    }
}

abstract class UtilityAccount {
    private Customer customer;
    private double unitsConsumed;
    private double billAmount;

    public UtilityAccount(Customer customer, double unitsConsumed) {
        this.customer = customer;
        setUnitsConsumed(unitsConsumed);
    }

    public Customer getCustomer() {
        return customer;
    }

    public double getUnitsConsumed() {
        return unitsConsumed;
    }

    public void setUnitsConsumed(double unitsConsumed) {
        if (unitsConsumed >= 0) {
            this.unitsConsumed = unitsConsumed;
        } else {
            this.unitsConsumed = 0;
        }
    }

    public double getBillAmount() {
        return billAmount;
    }

    protected void setBillAmount(double billAmount) {
        this.billAmount = billAmount;
    }

    public abstract void calculateBill();
    public abstract void generateBill();
}

class ElectricityAccount extends UtilityAccount {
    private final double RATE = 6.0;

    public ElectricityAccount(Customer customer, double unitsConsumed) {
        super(customer, unitsConsumed);
    }

    @Override
    public void calculateBill() {
        double amount = getUnitsConsumed() * RATE;

        if (getUnitsConsumed() > 300) {
            amount = amount + (amount * 0.10);
        }

        setBillAmount(amount);
    }

    @Override
    public void generateBill() {
        calculateBill();

        System.out.println("\n===== Electricity Bill =====");
        System.out.println("Customer ID   : " + getCustomer().getCustomerId());
        System.out.println("Customer Name : " + getCustomer().getName());
        System.out.println("Address       : " + getCustomer().getAddress());
        System.out.println("Units Used    : " + getUnitsConsumed());
        System.out.println("Rate per Unit : $6");
        if (getUnitsConsumed() > 300) {
            System.out.println("Extra Charge  : 10% surcharge applied");
        } else {
            System.out.println("Extra Charge  : No surcharge");
        }
        System.out.println("Bill Amount   : $" + getBillAmount());
        System.out.println("============================");
    }
}

class WaterAccount extends UtilityAccount {
    private final double RATE = 2.0;

    public WaterAccount(Customer customer, double unitsConsumed) {
        super(customer, unitsConsumed);
    }

    @Override
    public void calculateBill() {
        double amount = getUnitsConsumed() * RATE;

        if (getUnitsConsumed() > 500) {
            amount = amount + 150;
        }

        setBillAmount(amount);
    }

    @Override
    public void generateBill() {
        calculateBill();

        System.out.println("\n======= Water Bill =======");
        System.out.println("Customer ID   : " + getCustomer().getCustomerId());
        System.out.println("Customer Name : " + getCustomer().getName());
        System.out.println("Address       : " + getCustomer().getAddress());
        System.out.println("Units Used    : " + getUnitsConsumed());
        System.out.println("Rate per Unit : $2");
        if (getUnitsConsumed() > 500) {
            System.out.println("Extra Charge  : $150 fixed charge applied");
        } else {
            System.out.println("Extra Charge  : No fixed charge");
        }
        System.out.println("Bill Amount   : $" + getBillAmount());
        System.out.println("==========================");
    }
}

public class BillingApp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of utility accounts: ");
        int n = sc.nextInt();
        sc.nextLine();

        UtilityAccount[] accounts = new UtilityAccount[n];

        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Account " + (i + 1));

            System.out.print("Enter Customer ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Enter Customer Name: ");
            String name = sc.nextLine();

            System.out.print("Enter Address: ");
            String address = sc.nextLine();

            Customer customer = new Customer(id, name, address);

            System.out.print("Enter Utility Type (1 for Electricity, 2 for Water): ");
            int choice = sc.nextInt();

            System.out.print("Enter Units Consumed: ");
            double units = sc.nextDouble();
            sc.nextLine();

            if (choice == 1) {
                accounts[i] = new ElectricityAccount(customer, units);
            } else if (choice == 2) {
                accounts[i] = new WaterAccount(customer, units);
            } else {
                System.out.println("Invalid choice! Defaulting to Water Account.");
                accounts[i] = new WaterAccount(customer, units);
            }
        }

        System.out.println("\n\n========== GENERATED BILLS ==========");
        for (UtilityAccount acc : accounts) {
            acc.generateBill();
        }

        sc.close();
    }
}
