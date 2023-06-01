#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int vals=100;
        int GCD=__gcd(n,vals);
        cout<<vals/GCD<<"\n";
    }
}