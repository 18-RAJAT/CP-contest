#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int q;
    cin>>q;
    deque<int>a,b;
    int res=0;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int l;
            cin>>l;
            if(a.empty())a.push_back(0);
            else a.push_back(a.back()+b.back());
            b.push_back(l);
        }
        else if(t==2)
        {
            res+=b.front();
            a.pop_front(),b.pop_front();
        }
        else
        {
            int k;
            cin>>k;
            cout<<a[k-1]-res<<endl;
        }
    }
}
signed main()
{
    sol(); 
    return 0;
}