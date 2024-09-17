#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<n;++i)
    {
        if(s.substr(0,n-i)==s.substr(i,n-i))
        {
            if(i<n-i)
            {
                cout<<"YES"<<endl;
                cout<<s.substr(0,n-i);
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}
signed main()
{
    sol();
    return 0;
}