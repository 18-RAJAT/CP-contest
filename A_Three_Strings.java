// Problem: A. Three Strings
// Contest: Codeforces - Codeforces Round 619 (Div. 2)
// URL: https://codeforces.com/contest/1301/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: Rajat.18
// Created: Tue 8/10/2024 12:50:47 GMT+5:30,India

import java.util.*;
import java.io.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            String s1=sc.next();
            String s2=sc.next();
            String s3=sc.next();
            boolean ok=true;
            for(int i=0;i<s1.length();++i)
            {
            	if(s1.charAt(i)==s3.charAt(i) || s2.charAt(i)==s3.charAt(i)){continue;}
            	else
            	{
            		ok=false;
            		break;
            	}
            }
            System.out.println(ok?"YES":"NO");
        }
        sc.close();
    }
}