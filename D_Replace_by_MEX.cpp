#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
multiset<int>s;
int Mex()
{
    for(int i=0;i<=n;++i)
    {
        if(s.find(i)==s.end())return i;
    }
}
void sol()
{
    s.clear();
    cin>>n;
    vector<int>v(n),ans;
    for(int i=0;i<n;++i)cin>>v[i],s.insert(v[i]);
    int k=0;
    for(int i=0;i<2*n;++i)
    {
        int res=Mex();
        if(res!=n)
        {
            s.erase(s.find(v[res]));
            v[res]=res;
            s.insert(res);
            k++;
            ans.push_back(res);
        }
        else
        {
            int ok=0;
            for(int i=0;i<n;++i)
            {
                if(v[i]!=i)
                {
                    s.erase(s.find(v[i]));
                    v[i]=n;
                    s.insert(n);
                    ans.push_back(i);
                    ok=1,k++;
                    break;
                }
            }
            if(!ok)break;
        }
    }
    cout<<k<<endl;
    for(int i=0;i<ans.size();++i)cout<<ans[i]+1<<" ";
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