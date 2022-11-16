package java_source;
import java.util.Random;

public class Helloworld{
    public static void main(String[] args)
    {
        Random rand = new Random();
        System.out.println("랜덤 숫자" + rand.nextInt(10));
        System.out.print("Helloworld");
        
        
    }

}