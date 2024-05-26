#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    char ch[n][m];
    vector<int>a[n];
    int b[m+1]={0};
    multiset<int>ms;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>ch[i][j];
            if(ch[i][j]=='1')
            {
                a[i].push_back(j),b[j]++;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(auto& it:a[i])
        {
            if(b[it]>=1)b[it]--;
        }
        int turned=0;
        for(int j=0;j<m;++j)
        {
            if(b[j]<1)turned=1;
        }
        if(turned==0)
        {
            cout<<"YES"<<endl;return;
        }
        for(auto& it:a[i])b[it]++;
    }
    cout<<"NO"<<endl;
}
signed main()
{
    sol();
    return 0;
}