#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mx=0,index=0;
        for(int i=1;i<=n;i+=1)
        {
            int a,b;
            cin>>a>>b;
            if(a<=10 && b>mx)
            {
                mx=b;
                index=i;
            }
        }
        cout<<index<<"\n";
    }
}