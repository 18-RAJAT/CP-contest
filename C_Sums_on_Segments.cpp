#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int Cnt=0,pos=-1,x=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]!=1 && ~a[i])
        {
            if(!Cnt)
            {
                Cnt=1;pos=i;x=a[i];
            }
        }
    }
    vector<pair<int,int>>vp;
    if(Cnt)
    {
        vector<int>L,R;
        if(pos>0)L.assign(a.begin(),a.begin()+pos);
        if(pos+1<n)R.assign(a.begin()+pos+1,a.end());

        //Rajat joshi template
        auto recur1=[&](vector<int>&arr)
        {
            int pref=0,suf=0,mn=LLONG_MAX,mx=LLONG_MIN,tmp1=0,tmp2=0,cnt1=0,cnt2=0;
            for(auto& it:arr)
            {
                pref+=it;
                mn=min(mn,pref-cnt2);
                mx=max(mx,pref-cnt1);
                cnt1=min(cnt1,pref);
                cnt2=max(cnt2,pref);
            }
            suf=0;
            for(int i=arr.size()-1;~i;--i)
            {
                suf+=arr[i];
                tmp1=min(tmp1,suf);
                tmp2=max(tmp2,suf);
            }
            return make_tuple(mn,mx,tmp1,tmp2,cnt1,cnt2);
        }; 
        auto Lpos=L.empty()?make_tuple(LLONG_MAX,LLONG_MIN,0LL,0LL,0LL,0LL):recur1(L);
        int MnL=get<0>(Lpos),MxL=get<1>(Lpos),Tp1=get<2>(Lpos),Tp2=get<3>(Lpos);
        auto Rpos=R.empty()?make_tuple(LLONG_MAX,LLONG_MIN,0LL,0LL,0LL,0LL):recur1(R);
        int MnR=get<0>(Rpos),MxR=get<1>(Rpos),ok1=get<2>(Rpos),ok2=get<3>(Rpos),cnt1_r=get<4>(Rpos),cnt2_r=get<5>(Rpos);
        if(!L.empty())vp.emplace_back(MnL,MxL);
        if(!R.empty())vp.emplace_back(MnR,MxR);
        if(!L.empty() && !R.empty())
        {
            vp.emplace_back(Tp1+x+cnt1_r,Tp2+x+cnt2_r);
        }
        else if(!L.empty())
        {
            vp.emplace_back(Tp1+x,Tp2+x);
        }   
        else if(!R.empty())
        {
            vp.emplace_back(x+cnt1_r,x+cnt2_r);
        }
        else
        {
            vp.emplace_back(x,x);
        }
        vp.emplace_back(0,0);
    }
    else
    {
        
        //Rajat joshi template
        auto recur1=[&](vector<int>&arr)
        {
            int pref=0,suf=0,mn=LLONG_MAX,mx=LLONG_MIN,tmp1=0,tmp2=0,cnt1=0,cnt2=0;
            for(auto& it:arr)
            {
                pref+=it;
                mn=min(mn,pref-cnt2);
                mx=max(mx,pref-cnt1);
                cnt1=min(cnt1,pref);
                cnt2=max(cnt2,pref);
            }
            suf=0;
            for(int i=arr.size()-1;~i;--i)
            {
                suf+=arr[i];
                tmp1=min(tmp1,suf);
                tmp2=max(tmp2,suf);
            }
            return make_tuple(mn,mx,tmp1,tmp2,cnt1,cnt2);
        };
        auto take=recur1(a);
        int mn=get<0>(take),mx=get<1>(take),tmp1=get<2>(take),tmp2=get<3>(take),cnt1=get<4>(take),cnt2=get<5>(take);
        vp.emplace_back(mn,mx);
        vp.emplace_back(0,0);
    }
    sort(vp.begin(),vp.end());
    vector<pair<int,int>>pr;
    pr.emplace_back(vp[0]);
    for(int i=1;i<vp.size();++i)
    {
        if(vp[i].first<=pr.back().second+1) pr.back().second=max(pr.back().second,vp[i].second);
        else pr.emplace_back(vp[i]);
    }
    vector<int>ans;
    for(auto& it:pr)
    {
        for(int i=it.first;i<=it.second;++i) ans.emplace_back(i);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
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