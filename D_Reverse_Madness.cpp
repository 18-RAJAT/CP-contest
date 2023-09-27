#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>left(k),right(k);
    for(auto& it:left)
    {
        cin>>it;it--;
    }
    for(auto& it:right)
    {
        cin>>it;it--;
    }
    int q;
    cin>>q;
    vector<vector<int>>a(k);
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        x--;
        // int LB=lower_bound(left.begin(),left.end(),x)-left.begin();
        // a[LB].push_back(max(left[LB]+right[LB]-x,0LL));

        int LB=lower_bound(right.begin(),right.end(),x)-right.begin();
        //calc left
        int mx=max(left[LB]+right[LB]-x,x);
        a[LB].push_back(mx);
        // cout<<a.size();
    }
    for(int i=0;i<k;++i)
    {
        int lPos=left[i],rPos=right[i];
        auto& tmp=a[i];
        sort(tmp.begin(),tmp.end());
        int sza=tmp.size();
        // cout<<"sza: "<<sza<<endl;
        while(lPos<rPos)
        {
            while(sza>0 && tmp[sza-1]==rPos)
            {
                // tmp.pop_back();
                sza--;
                // tmp.size()--;
            }
            if((tmp.size()-sza)%2)
            {
                // left[i]=lPos;
                swap(s[lPos],s[rPos]);
            }
            else
            {
                left[i]=rPos;
            }
            lPos++,rPos--;
        }   
    }
    // vector<int>ans(n+1);
    cout<<s<<endl;
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