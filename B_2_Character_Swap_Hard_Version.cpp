#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    if(s.size()!=t.size())
    {
        cout<<"NO\n";
        return;
    }
    vector<pair<int,int>>chars;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=t[i])
        {
            bool ok=false;
            for(int j=i+1;j<n;++j)
            {
                if(s[i]==s[j])
                {
                    ok=true;
                    chars.push_back({j+1,i+1});
                    swap(s[j],t[i]);
                    break;
                }
            }
            if(ok==false)
            {
                for(int j=i+1;j<n;++j)
                {
                    if(s[i]==t[j])
                    {
                        ok=true;
                        swap(s[n-1],t[j]);
                        swap(s[n-1],t[i]);
                        chars.push_back({n,j+1});
                        chars.push_back({n,i+1});
                        ok=true;
                        break;
                    }
                }
                if(ok==false)
                {
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    if(chars.size()<=2*n)
    {
        cout<<"YES\n";
        cout<<chars.size()<<endl;
        for(int i=0;i<(int)chars.size();++i)
        {
            cout<<chars[i].first<<" "<<chars[i].second<<endl;
        }
    }
    else
    {
        cout<<"NO\n";
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