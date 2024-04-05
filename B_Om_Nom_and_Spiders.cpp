#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            char ch;
            cin>>ch;
            if(ch=='U')
            {
                if(~i&1)a[j]++;
            }
            else if(ch=='R')
            {
                if(i+j<m)
                {
                    a[i+j]++;
                }
            }
            else if(ch=='L')
            {
                if(j-i>=0)
                {
                    a[j-i]++;
                }
            }
        }
    }
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i]<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}