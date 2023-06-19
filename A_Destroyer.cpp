#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int count[100];
        memset(count,0,sizeof(count));
        for(int i=0;i<n;++i)
        {
            cin>>arr[i];
            count[arr[i]]++;
        }
        bool ok=true;
        for(int i=0;i<100;++i)
        {
            if(count[i]>count[i-1])
            {
                ok=false;
                break;
            }
        }
        cout<<((ok)?"YES":"NO")<<"\n";
    }
}