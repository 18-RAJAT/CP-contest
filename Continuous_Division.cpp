#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    /*
        Problem statement:
        You are given two integers, a and b, along with a variable x initialized to 0. Your task is to continuously increment x by a until a condition is met. At each iteration, check whether dividing x by b yields a quotient of 1. If such a quotient is found, return true; otherwise, return false.
        Input:
        Two integers a and b, where a represents the increment value and b represents the divisor.
        Output:
        Return true if there exists an x such that x divided by b equals 1; otherwise, return false.
        Example:
        Input: a=3, b=4
        Output: true
        Explanation: Starting with x=0, incrementing x by 3 at each step eventually results in x=12, which yields a quotient of 1 when divided by 4.
    */
    int a,b;
    cin>>a>>b;
    int x=0;
    while(true)
    {
        x+=a;
        if(x%b==1)
        {
            cout<<"false";
            return;
        }
        if(x/b==1)
        {
            cout<<"false";
            return;
        }
        if(x/b==0)
        {
            cout<<"true";
            return;
        }
    }
}
signed main()
{
    sol();
    return 0;
}