#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int ans=1;
        while(n%ans==0)
        {
            ans++;
        }
        for(int i=0;i<n;++i)
        {
            cout<<(char)('a'+(i%ans));
        }
        cout<<"\n";
    }
}