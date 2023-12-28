import java.util.*;
import java.io.*;
public class A_Arya_and_Bran{
public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int days=sc.nextInt();
        int amount=sc.nextInt();
        int canday=0,have=0,sum=0;
        for(int i=1;i<=days;++i)
        {
            canday=sc.nextInt();
            have+=canday;
            if(have>7)
            {
                sum+=8;
                have-=8;
            }
            else
            {
                sum+=have;
                have=0;
            }
            // sum+=Math.min(have,8);
            if(sum>=amount)
            {
                System.out.println(i);
                System.exit(0);
            }
        }
        System.out.println("-1");
    }
}