#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,x;
    cin>>n>>m>>x;
    set<int> s;
    s.insert(x-1);
    while(m--)
    {
        int d;
        char c;
        cin>>d>>c;
        set<int> t;
        for(auto i:s)
        {
            if(c!='1')
            {
                t.insert((i+d)%n);
            }
            if(c!='0')
            {
                t.insert((i+n-d)%n);
            }
        }
        s=t;
    }
    cout<<s.size()<<endl;
    for(int i=0;i<n;i++)
    {
        if(s.find(i)!=s.end())
        {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}