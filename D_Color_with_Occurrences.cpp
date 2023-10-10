#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<pair<string,int>>check;
    for(int i=0;i<n;++i)
    {
        string nw;
        cin>>nw;
        check.push_back({nw,i+1});
    }
    sort(check.begin(),check.end(),[](pair<string,int>&a,pair<string,int>&b)
    {
        return a.first.length()<b.first.length();
    });
    vector<pair<int,int>>ans;
    int previous=-1,curr=0;
    for(int i=0;i<s.size();++i)
    {
        if(i<=previous)
        {
            curr=0;
            break;
        }
        int flag=0;
        for(int j=0;j<check.size();++j)
        {
            // cout<<check[j].first<<" "<<check[j].second<<endl;
            if(i+check[j].first.size()==s.size())//ans get?
            {
                flag=1;
                ans.push_back({check[j].second,i});
                previous=i;
                i+=check[j].first.size();
                break;
            }
        }
        if(!flag)
        {
            i--;
        }
        if(i==s.size())
        {
            curr=0;
        }
    }
    if(!curr)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();++i)
        {
            cout<<ans[i].first<<" "<<1+ans[i].second<<endl;
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