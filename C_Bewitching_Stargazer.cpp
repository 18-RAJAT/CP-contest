#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    struct st
    {
        int l,r,ok;
        pair<int,int>res;
    };
    stack<st>stk;
    stk.push({1,n,0,{0,0}});
    pair<int,int>Ans={0,0};
    while(!stk.empty())
    {
        st cur=stk.top();
        stk.pop();
        int l=cur.l,r=cur.r,sza=r-l+1;
        if(sza<k)
        {
            if(!stk.empty())
            {
                st ert=stk.top();
                stk.pop();
                ert.res.first+=0,ert.res.second+=0;
                stk.push(ert);
            }
            else Ans={0,0};
            continue;
        }
        if(sza==1)
        {
            pair<int,int>res={l,1};
            if(!stk.empty())
            {
                st ert=stk.top();
                stk.pop();
                ert.res.first+=res.first,ert.res.second+=res.second;
                stk.push(ert);
            }
            else Ans=res;
            continue;
        }
        if(!cur.ok)
        {
            stk.push({l,r,1,{0,0}});
            int mid=l+(r-l)/2;
            if(sza&1) stk.push({l,mid-1,0,{0,0}});
            else stk.push({l,mid,0,{0,0}});
        }
        else
        {
            pair<int,int>rem=cur.res;
            int mid=l+(r-l)/2;
            if(sza&1)
            {
                int tot=mid+2*rem.first+mid*rem.second;
                int nxt=2*rem.second+1;
                Ans={tot,nxt};
            }
            else
            {
                int tot=2*rem.first+mid*rem.second,nxt=2*rem.second;
                Ans={tot,nxt};
            }
            if(!stk.empty())
            {
                st ert=stk.top();
                stk.pop();
                ert.res.first+=Ans.first,ert.res.second+=Ans.second;
                stk.push(ert);
            }
        }
    }
    cout<<Ans.first<<endl;
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