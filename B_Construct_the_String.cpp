#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string ans="";
        char c='a';
        for(int i=1;i<=b;++i)
        {
            ans+=c;
            if(i!=b)
            {
                c++;
            }
        }
        for(int i=b+1;i<=a;++i)
        {
            ans+=c;
        }
        for(int i=a;i<n;++i)
        {
            ans+=ans[i-a];
        }
        cout<<ans<<"\n";
    }
}