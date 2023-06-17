#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        bool ok=true;
        for(int i=0;i<n;++i)
        {
            int vals=abs(s[i]-s[n-i-1]);
            if(vals==1 or vals>2)
            {
                ok=false;
                break;
            }
        }
        cout<<((ok)?"YES":"NO")<<"\n";
    }
}