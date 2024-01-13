import java.util.*;
import java.io.*;
public class D_Array_Painting{
public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int count=0,move=0;
        while(n-->0)
        {
            int a=sc.nextInt();
            if(a==0)
            {
                if(move==2)
                {
                    move=0;
                }
                else
                {
                    count++;
                    move=1;
                }
            }
            if(a==1)
            {
                if(move==0)
                {
                    count++;
                    move=2;
                }
            }
            if(a==2)
            {
                if(move==0)
                {
                    count++;
                }
                move=2;
            }
        }
        System.out.println(count);
    }
}