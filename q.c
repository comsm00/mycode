import java.util.Scanner;

public class mainLL {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList route = new LinkedList();

        route.insertBeginning("A");
        route.insertBeginning("B");
        route.insertBeginning("C");
        route.insertBeginning("D");

        route.insertEnd("E");
        route.insertEnd("F");

        route.insertAfter("B", "G");
        route.insertAfter("E", "H");

        System.out.println("Initial route:");
        route.displayForward();

        System.out.print("Stop name to delete: ");
        System.out.println(
            route.deleteByName(sc.nextLine())
                ? "Deleted." : "Not found."
        );

        System.out.print("Position to delete: ");
        System.out.println(
            route.deleteByPosition(sc.nextInt())
                ? "Deleted." : "Invalid position."
        );

        System.out.println("Forward:");
        route.displayForward();

        System.out.println("Reverse:");
        route.displayReverse();

        System.out.println("Stop count: " + route.count());
        sc.close();
    }
}

*!****
public class LinkedList {
    private Node head;
    private Node tail;
    private int size;

    public void insertBeginning(String value) {
        Node node = new Node(value);
        node.next = head;

        if (head == null) {
            tail = node;
        } else {
            head.prev = node;
        }

        head = node;
        size++;
    }

    public void insertEnd(String value) {
        Node node = new Node(value);
        node.prev = tail;

        if (tail == null) {
            head = node;
        } else {
            tail.next = node;
        }

        tail = node;
        size++;
    }

    private Node find(String value) {
        Node current = head;

        while (current != null) {
            if (current.data.equals(value)) {
                return current;
            }

            current = current.next;
        }

        return null;
    }

    public boolean insertAfter(String target, String value) {
        Node current = find(target);

        if (current == null) {
            return false;
        }

        Node node = new Node(value);
        node.prev = current;
        node.next = current.next;

        if (current.next == null) {
            tail = node;
        } else {
            current.next.prev = node;
        }

        current.next = node;
        size++;
        return true;
    }

    private void unlink(Node node) {
        if (node.prev == null) {
            head = node.next;
        } else {
            node.prev.next = node.next;
        }

        if (node.next == null) {
            tail = node.prev;
        } else {
            node.next.prev = node.prev;
        }

        size--;
    }

    public boolean deleteByName(String name) {
        Node node = find(name);

        if (node == null) {
            return false;
        }

        unlink(node);
        return true;
    }

    public boolean deleteByPosition(int position) {
        if (position < 1 || position > size) {
            return false;
        }

        Node current = head;

        for (int i = 1; i < position; i++) {
            current = current.next;
        }

        unlink(current);
        return true;
    }

    public void displayForward() {
        for (Node p = head; p != null; p = p.next) {
            System.out.print(p.data + " ");
        }

        System.out.println();
    }

    public void displayReverse() {
        for (Node p = tail; p != null; p = p.prev) {
            System.out.print(p.data + " ");
        }

        System.out.println();
    }

    public int count() {
        return size;
    }
}
***

    
import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a word: ");
        String word = sc.next();

        ArrayStack<Character> stack =
            new ArrayStack<>(word.length());

        for (int i = 0; i < word.length(); i++) {
            stack.push(word.charAt(i));
        }

        StringBuilder reversed = new StringBuilder();

        while (!stack.isEmpty()) {
            reversed.append(stack.pop());
        }

        System.out.println("Reversed: " + reversed);

        System.out.println(
            word.equals(reversed.toString())
                ? "Palindrome"
                : "Not Palindrome"
        );

        sc.close();
    }
}

