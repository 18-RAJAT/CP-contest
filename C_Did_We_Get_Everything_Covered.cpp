#include<bits/stdc++.h>
using namespace std;
#define int long long
char ch[2000005];
map<char,int>mp;
void init()
{
    for(char ch='a';ch<='z';++ch)
    {
        mp[ch]=0;
    }
}
void sol()
{
    init();
    int n,k,m;
    cin>>n>>k>>m;
    int total=0,ans=0;
    vector<int>arr;
    arr.clear();
    cin>>ch;
    for(int i=0;i<m;++i)
    {
        // mp[ch[i]]++;
        if(mp[ch[i]] || (ch[i]-'a'+1)>k)
        {
            continue;
        }
        total++;
        mp[ch[i]]=1;
        if(total==k)
        {
            arr.push_back(ch[i]);
            ans++;  
            total=0;
            init();
        }
    }
    for(int i=1;i<=n;++i)
    {
        arr.emplace_back(0);
    }
    if(n<=ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
        for(int i=0;i<n-1;++i)
        {
            // cout<<arr[i]<<" ";
            if(arr.at(i))
            {
                cout<<(char)arr[i];
            }
            else
            {
                cout<<'a';
            }
            // cout<<(arr[i]?arr[i]:ch[i]);
        }
        for(char ch='a';ch<='z';++ch)
        {
            // if(!mp[ch])
            // {
            //     cout<<ch;
            //     break;
            // }
            if(mp[ch]==0)
            {
                cout<<ch<<endl;
                break;
            }
        }
    }
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