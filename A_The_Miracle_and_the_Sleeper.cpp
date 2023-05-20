#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        long long int L,R;
        cin>>L>>R;

        long long int ans=0;
        if(2*L<=R)
        {
            ans=(R-1)/2;
        }
        else
        {
            ans=R-L;
        }
        cout<<ans<<"\n";
    }
}