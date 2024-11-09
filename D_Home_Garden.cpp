#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int q;
    cin>>q;
    multiset<int>s;
    int cur=0;
    vector<int>ans;
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            s.insert(cur);
        }
        else if(x==2)
        {
            int t;
            cin>>t;cur+=t;
        }
        else if(x==3)
        {
            int h;
            cin>>h;
            if(h>cur)ans.push_back(0);
            else
            {
                multiset<int>::iterator it=s.upper_bound(cur-h);
                ans.push_back(distance(s.begin(),it));
                s.erase(s.begin(),it);
            }
        }
    }
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<endl;
}
signed main()
{
    sol();
    return 0;
}