import java.util.*;
import java.io.*;
public class B_Motarack_s_Birthday
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            int[] arr=new int[n];
            for(int i=0;i<n;++i)
            {
                arr[i]=sc.nextInt();
            }
            int minimum=Integer.MAX_VALUE;
            int maximum=Integer.MIN_VALUE;
            for(int i=0;i<n;++i)
            {
                if(arr[i]<0)
                {
                    int left=Math.max(0,i-1);
                    int right=Math.min(n-1,i+1);
                    if(arr[left]>=0)
                    {
                        minimum=Math.min(minimum,arr[left]);
                        maximum=Math.max(maximum,arr[left]);
                    }
                    if(arr[right]>=0)
                    {
                        minimum=Math.min(minimum,arr[right]);
                        maximum=Math.max(maximum,arr[right]);
                    }
                }
            }
            int ans=(minimum+maximum)/2;
            int m=Integer.MIN_VALUE;
            for(int i=0;i<n-1;++i)
            {
                if(arr[i]<0)
                {
                    arr[i]=ans;
                }
                if(arr[i+1]<0)
                {
                    arr[i+1]=ans;
                }
                m=Math.max(m,Math.abs(arr[i]-arr[i+1]));
            }
            System.out.println(m+" "+ans);
        }
        sc.close();
    }
}