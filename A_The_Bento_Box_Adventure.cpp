#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    unordered_set<int>s={a,b,c,d};
    for(int i=1;i<=5;i++)
    {
        if(s.find(i)==s.end())
        {
            cout<<i<<endl;
            return;
        }
    }
}
signed main()
{
    sol();
    return 0;
}