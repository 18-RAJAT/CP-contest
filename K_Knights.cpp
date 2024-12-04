#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    int id,l,r,Mn,Mx;
    vector<int>ch;
    bool Knight,NotKnight;
};
void sol()
{
    int n;
    cin>>n;
    vector<Node>nodes(n+1);
    for(int i=1;i<=n;++i)
    {
        nodes[i].id=i;
        cin>>nodes[i].l>>nodes[i].r;
        int k;
        cin>>k;
        for(int j=0;j<k;++j)
        {
            int c;
            cin>>c;
            nodes[i].ch.push_back(c);
        }
    }
    stack<pair<int,bool>>s;
    s.emplace(1,false);
    while(!s.empty())
    {
        auto top=s.top();
        s.pop();
        int u=top.first;
        bool vis=top.second;
        if(!vis)
        {
            s.emplace(u,true);
            for(auto& c:nodes[u].ch)s.emplace(c,false);
        }
        else
        {
            auto& cur=nodes[u];
            if(cur.ch.empty())
            {
                bool NotKnight=(cur.l<=0 && 0<=cur.r);
                bool Knight=(cur.l<=1 && 1<=cur.r);
                cur.NotKnight=NotKnight;
                cur.Knight=Knight;
                vector<int>arr;
                if(NotKnight)arr.push_back(0);
                if(Knight)arr.push_back(1);
                cur.Mn=*min_element(arr.begin(),arr.end());
                cur.Mx=*max_element(arr.begin(),arr.end());
            }
            else
            {
                int sum_min=0,sum_max=0;
                for(auto& c:cur.ch)
                {
                    sum_min+=nodes[c].Mn;
                    sum_max+=nodes[c].Mx;
                }
                int nk_low=max(cur.l,sum_min),nk_high=min(cur.r,sum_max);
                cur.NotKnight=(nk_low<=nk_high);
                int k_low=max(cur.l,sum_min+1),k_high=min(cur.r,sum_max+1);
                cur.Knight=(k_low<=k_high);
                vector<int>arr;
                if(cur.NotKnight)
                {
                    arr.push_back(nk_low);
                    arr.push_back(nk_high);
                }
                if(cur.Knight)
                {
                    arr.push_back(k_low);
                    arr.push_back(k_high);
                }
                cur.Mn=*min_element(arr.begin(),arr.end());
                cur.Mx=*max_element(arr.begin(),arr.end());
            }
        }
    }
    vector<int>res;
    stack<pair<int,int>>assign;
    assign.emplace(1,nodes[1].Mn);
    while(!assign.empty())
    {
        auto top=assign.top();
        assign.pop();
        int u=top.first;
        int target=top.second;
        auto& cur=nodes[u];
        int sum_min=0,sum_max=0;
        for(auto& c:cur.ch)
        {
            sum_min+=nodes[c].Mn;
            sum_max+=nodes[c].Mx;
        }
        bool nk=false,k=false;
        if(cur.Knight && (target>=(sum_min+1)) && (target<=(sum_max+1)))k=true;
        if(cur.NotKnight && (target>=sum_min) && (target<=sum_max))nk=true;
        int sums;
        if(nk)sums=target;
        else
        {
            res.push_back(u);
            sums=target-1;
        }
        if(!cur.ch.empty())
        {
            int tot=0,rem=sums;
            vector<pair<int,int>>AssignK;
            for(auto& c:cur.ch)tot+=nodes[c].Mn;
            for(auto& c:cur.ch)
            {
                int mini=min(nodes[c].Mx-nodes[c].Mn,rem);
                AssignK.emplace_back(c,nodes[c].Mn+mini);
                rem-=mini;
            }
            for(int i=AssignK.size()-1;~i;--i)assign.emplace(AssignK[i].first,AssignK[i].second);
        }
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(auto& x:res)cout<<x<<" ";
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}