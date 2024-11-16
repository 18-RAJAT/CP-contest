#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<array<int,2>>ans;
    int idx=0;
    while(idx<n)
    {
        if(s[idx]=='1')
        {
            int tmp=idx;
            while(idx<n && s[idx]=='1')idx++;
            ans.push_back({tmp,idx-1});
        }
        else idx++;
    }
    int m1=ans[k-2][1],m2=ans[k-1][0],m3=ans[k-1][1];
    for(int i=m2;i<=m3;++i)s[i]='0';
    int segment=1+m1+(m3-m2);
    for(int i=m1;i<=segment;++i)s[i]='1';
    cout<<s;
}
signed main()
{
    sol();
    return 0;
}