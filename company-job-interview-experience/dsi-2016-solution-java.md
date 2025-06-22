# Solutions
1.
```
class Bike {
    void run() {
        System.out.println("running");
    }
}
class Splender extends Bike {
    void run() {
        System.out.println("running safely with 60km");
    }
}
public class Main {
    public static void main(String args[]) {
        Bike b = new Splender();
        b.run();
    }
}
/*
running safely with 60km
*/
```
2. Error will occur. Static method must be accessed either directly, through class reference or through object from static area.
3. One object will be created by JVM after compiling the provided code.
4. Inheritance exhibits the IS-A relationship while COMPOSITION exhibits the HAS-A relationship.
5. StringBuffer is suitable for multi-threaded environments whereas StringBuilder is suitable for single-threaded environment.
6.
```
class AB {
    AB() {
        System.out.println("Constructor of A");
    }
}
class Main extends AB {
    public Main() {
        System.out.println("Constructor of HelloWorld");
    }
    public static void main(String args[]) {
        Main ob = new Main();
    }
}
/*
Constructor of A
Constructor of HelloWorld
*/
```
7. base is not a Java keyword.
8. todo
9.
```
public class Main{
    public static void main(String args[]) {
        int a = 5;
        System.out.println("Value is - " + ((a < 5)? 9.9 : 9.0));
    }
}
/*
Value is - 9.0
*/
```
10. When subclass declares a method that has the same name, same type arguments as a method declared by one its superclass, it is termed as Method overriding.
11. Superclass of every Java class is Object class.
12. List -> Contains sequence of elements with duplicates
    Set -> Contains only distinct elements
    Map -> Stores key and value pairs where keys are distinct
13. In interface variables are by default public, static and final, and the methods are by default public, abstract. But in abstract class they are not. Interface can extends multiple interfaces but abstract class can't.
14. In stack data structure lastly entered element is popped first whereas in queue firstly entered element is popped first.
15. If Java would not have run on JVM it could have missed the basic feature of portability.
16. todo
17.
```
public class Main{
    public static String reverse(String name) {
        int n = name.length();
        if (n == 1) {
            return name;
        }
        String r = "";
        for (int i = 0; i < n-1; i++) {
            r += name.charAt(i);
        }
        String rev_name = name.charAt(n-1) + reverse(r);
        return rev_name;
    }
    public static void main(String args[]) {
       String name = "JakirHasan";
       int n = name.length();
       String name_ = Main.reverse(name);
       System.out.println(name_);

    }
}
/*
nasaHrikaJ
*/
```

18.
```
import java.util.HashSet;

public class Main{
    public static void main(String args[]) {
        HashSet shortSet = new HashSet();
        for (short i = 0; i < 100; i++) {
            shortSet.add(i);
            shortSet.remove(i-1);
        }
        System.out.println(shortSet.size());
    }
}
/*
100
*/
```
19.
```
public class Main{
    public static void main(String args[]) {
        String s3 = "GuybrushThreepwood";
        int start = 1;
        char end = 5;
        System.out.println(start + end);
        System.out.println(s3.substring(start, end));
    }
}
/*
6
uybr
*/
```
20.
```
public class Main{
    static {
        System.out.println("Inside parent static");
    }
    {
        System.out.println("Inside parent init");
    }
    public Main() {
        System.out.println("Parent const.");
    }
    public static void main(String args[]) {
        new MyChild();
    }
}
class MyChild extends Main {
    static {
        System.out.println("Inside child static");
    }
    {
        System.out.println("Inside child init");
    }
    MyChild() {
        System.out.println("Child const.");
    }
}
/*
Inside parent static
Inside child static
Inside parent init
Parent const.
Inside child init
Child const.
*/
```

21.
```
public class Main{
    public void doSomething() {
        int i = 5;
        Thread t = new Thread(new Runnable() {
            public void run() {
                for (int j = 0; j <= i; j++) {
                    System.out.println(" " + j);
                }
            }
        });
        t.start();
    }
    public static void main(String args[]) {
        new Main().doSomething();
    }
}
/*
 0
 1
 2
 3
 4
 5
*/
```
