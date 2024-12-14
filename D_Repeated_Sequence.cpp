#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,s;
    cin>>n>>s;
    vector<int>a(n);
    int tot=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        tot+=a[i];
    }
    int res=s/tot;
    vector<int>Arr;
    Arr.push_back(res);
    if(res>=1)Arr.push_back(res-1);
    auto SubArr=[&](vector<int>& a,int n,int t)
    {
        vector<int>Arr(2*n);
        for(int i=0;i<2*n;++i)
        {
            Arr[i]=a[i%n];
        }
        int l=0,r=0,cur=0;
        while(l<2*n)
        {
            while(cur<t && r<2*n)
            {
                cur+=Arr[r],r++;
            }
            if(cur==t)return true;
            cur-=Arr[l],l++;
        }
        return false;
    };
    bool ok=false;
    for(auto it:Arr)
    {
        if(it<0)continue;
        int t=s-it*tot;
        if(t<=0)continue;
        if(SubArr(a,n,t))
        {
            ok=true;
            break;
        }
    }
    if(ok)cout<<"Yes";
    else cout<<"No";
}
signed main()
{
    sol();
    return 0;
}