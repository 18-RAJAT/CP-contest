#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int m;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int l,r,k;
        cin>>l>>r>>k;
        l--,r--;
        k%=(r-l+1);
        string tmp=s.substr(l,r-l+1);
        for(int j=0;j<k;++j)
        {
            // cout<<tmp[r-l-k+j+1]<<" "<<s[l+j]<<endl;
            s[l+j]=tmp[r-l-k+j+1];
        }
        for(int j=k;j<r-l+1;++j)
        {
            // cout<<tmp[j-k]<<" "<<s[l+j]<<endl;
            s[l+j]=tmp[j-k];
        }
    }
    cout<<s;
}
signed main()
{
    sol();
    return 0;
}