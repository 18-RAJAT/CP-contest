#include<bits/stdc++.h>
using namespace std;
#define int long long
struct z_algo
{
    vector<int>z;
    z_algo(const string &s)
    {
        int n=s.size();
        z.resize(n+1);
        z[0]=0;
        for(int i=1,j=0;i<=n;++i)
        {
            auto &k=z[i];
            k=(j+z[j]<=i)?0:min(j+z[j]-i,z[i-j]);
            while(i+k<n && s[k]==s[i+k])k++;
            if(j+z[j]<i+z[i])j=i;
        }
        z[0]=n;
    }

};
void sol()
{
    string s;
    cin>>s;
    z_algo z(s);
    for(int i=0;i<s.size();++i)
    {
        cout<<z.z[i];
        if(i+1!=s.size())cout<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}