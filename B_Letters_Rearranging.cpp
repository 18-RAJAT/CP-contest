#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t-->0)
    {
        string s;cin>>s;
        sort(s.begin(),s.end());
        cout<<((s[0]==s.back())?"-1":s)<<"\n";
    }
}