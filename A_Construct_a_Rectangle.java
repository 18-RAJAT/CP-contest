import java.util.*;
import java.io.*;
public class A_Construct_a_Rectangle{
public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            int a=sc.nextInt();
            int b=sc.nextInt();
            int c=sc.nextInt();
            int addA=b+c;
            int addB=a+c;
            int addC=a+b;
            if((a+b+c)%2==0 && ((a==b || b==c || c==a) || (a==addA || b==addB || c==addC)))
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
    }
}