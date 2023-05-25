#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;
        if(n%k==0)
        {
            cout<<2<<"\n";
            cout<<1<<" "<<n-1<<"\n";
        }
        else
        {
            cout<<1<<"\n";
            cout<<n<<"\n";
        }
    }
    return 0;
}