#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int x,y;
    cin>>x>>y; 
    if(x==y)
    { 
        cout<<"YES"<<"\n"; 
        return; 
    } 
    int cnt=0; 
    int cnt1=0; 
    int G=__gcd(x,y); 
    x/=G;
    y/=G; 
    while(x%3==0)
    { 
        cnt++;
        x/=3; 
    } 
    while(y%2==0)
    { 
       cnt1++;
       y/=2; 
    } 
    if(x==1 and y ==1 and cnt1<=cnt) 
    { 
        cout<<"YES"<<"\n"; 
    } 
    else
    { 
        cout<<"NO"<<"\n"; 
    }
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}