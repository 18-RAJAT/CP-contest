#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int ok=0,f=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='0')
        {
            ok=1,f=s.size()-i;
            break;
        }
    }
    if(!ok)
    {
        cout<<1<<" "<<s.size()<<" "<<1<<" "<<1<<endl;
        return;
    }
    vector<vector<int>>arr;
    for(int i=0;i<s.size()-f+1;++i)
    {
        vector<int>v;
        int ele=s.size()-1;
        for(int j=i+f-1;j>=i;--j)
        {
            if(s[ele]!=s[j])v.push_back(s.size()-1-ele);
            ele--;
        }
        reverse(v.begin(),v.end());
        arr.push_back(v);
    }
    vector<int>brr(s.size()-f+1);
    iota(brr.begin(),brr.end(),0);
    sort(brr.begin(),brr.end(),[&](int x,int y){return arr[y]<arr[x];});
    cout<<1<<" "<<s.size()<<" "<<1+brr[0]<<" "<<f+brr[0]<<endl;
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