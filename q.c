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
}
***********************************************************************************************
	}
}
