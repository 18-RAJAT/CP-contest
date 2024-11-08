#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;++i)
    {
        int tmp=i;
        set<int>st;
        for(int j=2;j<=i;++j)
        {
            while(tmp%j==0)
            {
                st.insert(j);
                tmp/=j;
            }
        }
        if(st.size()==2)count++;
    }
    cout<<count;
}
signed main()
{
    sol();
    return 0;
}