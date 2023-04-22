#include<bits/stdc++.h>
using namespace std;

int sol()
{
    int l1,l2,r1,r2;
    cin>>l1>>r1>>l2>>r2;

    if(l1!=l2)
    {
        cout<<l1<<" "<<l2;
    }
    else
    {
        cout<<l1<<" "<<l1+1;
    }
    cout<<"\n";
}

int main()
{
    int testCase;
    cin>>testCase;
    while(testCase-->0)
    {
        sol();
    }
}