#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n<=2)
    {
        cout<<0<<"\n";
        return;
    }
    function<int(vector<int>&)->int>check=[&](vector<int>&v)->int
    {
        int res=0;
        int factor=v[1]-v[0];
        for(int i=2;i<v.size();++i)
        {
            if(v[i]-v[i-1]!=factor)
            {
                if(v[i]-v[i-1]+1==factor)
                {
                    res++;
                    v[i]++;
                }
                else if(v[i]-v[i-1]-1==factor)
                {
                    res++;
                    v[i]--;
                }
                else
                {
                    return INT_MAX;
                }
            }
        }
        return res;
    };
    vector<int>v(n);
    for(auto &val:v)
    {
        cin>>val;
    }
    int res=INT_MAX;
    // pair<int,int>dir[5]={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
    for(auto val:{pair<int,int>{0,0},{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,-1},{1,1},{-1,1}})
    // for(auto val:dir)
    {
        vector<int>temp=v;
        temp[0]+=val.first;
        temp[1]+=val.second;
        int c=0;
        if(val.first!=0)
        {
            c++;
        }
        if(val.second!=0)
        {
            c++;
        }
        res=min(res,c+check(temp));
    }
    cout<<((res==INT_MAX)?-1:res)<<"\n";
}
signed main()
{
    sol();
    return 0;
}