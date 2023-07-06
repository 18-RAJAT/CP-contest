#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        long long x=1,y=0;
        while(y<m)
        {
            y+=x;
            x++;
        }
        string s(n,'a');
        s[n-x]='b';
        s[n-x+1+y-m]='b';
        cout<<s<<"\n";
    }
}