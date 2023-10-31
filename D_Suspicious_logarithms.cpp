#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;

int binary_search(vector<int>&a,int l,int r,int key)
{
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]<=key)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}
void sol()
{
    int l,r;
    cin>>l>>r;
    vector<int>pref(100001);
    vector<int>suf(100001);

    function<int(vector<int>&,int&,int&)>fx=[&](vector<int>&side1,int l,int r)->int
    {
        //min side
        int mini=min(side1[l],side1[r]);
        for(int i=l;i<=r;++i)
        {
            mini=min(mini,side1[i]);
        }
        int ans=0;
        for(int i=l;i<=r;++i)
        {
            ans+=side1[i]-mini;
        }
        for(int i=l;i<=r;++i)
        {
            side1[i]=mini;
        }
        return ans;
    };
    
    function<int(vector<int>&,int&,int&)>gx=[&](vector<int>&side2,int l,int r)->int
    {
        //max side
        int maxi=max(side2[l],side2[r]);
        for(int i=l;i<=r;++i)
        {
            maxi=max(maxi,side2[i]);
        }
        int ans=0;
        for(int i=l;i<=r;++i)
        {
            ans+=maxi-side2[i];
        }
        for(int i=l;i<=r;++i)
        {
            side2[i]=maxi;
        }
        return ans;
    };
    int sumOF=0;
    for(int i=1;i<=100000;++i)
    {
        sumOF+=i;
        pref[i]=pref[i-1]+sumOF;
    }
    sumOF=0;
    for(int i=100000;i>=1;--i)
    {
        sumOF+=i;
        suf[i]=suf[i+1]+sumOF;
    }
    int ans=0;
    for(int i=1;i<=100000;++i)
    {
        int l1=binary_search(pref,0,100000,l/i);
        int r1=binary_search(pref,0,100000,r/i);
        int l2=binary_search(suf,0,100000,l/i);
        int r2=binary_search(suf,0,100000,r/i);
        int base1=log2(i);
        int base2=log2(i+1);
        if(base1==base2)
        {
            if(~l1)
            {
                ans+=fx(pref,l1,r1);
            }
            if(~l2)
            {
                ans+=gx(suf,l2,r2);
            }
            continue;
        }
    }
    assert(ans>=0);
    cout<<ans%mod<<"\n";
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