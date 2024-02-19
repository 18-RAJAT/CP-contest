#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    char ch;
    cin>>ch;
    map<char,vector<string>>hash;
    hash.clear();
    for(int i=0;i<2*n;++i)
    {
        string s;
        cin>>s;
        hash[s[1]].push_back(s);
    }
    vector<char>arr={'C','D','H','S'};
    vector<pair<string,string>>ans;
    ans.clear();
    for(auto &i:arr)
    {
        sort(hash[i].begin(),hash[i].end());
    }
    int count=0;
    for(auto &i:arr)
    {
        if(i!=ch)
        {
            if(hash[i].size()%2==1)
            {
                count++;
            }
        }
    }
    if(count>hash[ch].size())
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else if(count%2!=hash[ch].size()%2)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(auto &i:arr)
        {
            if(ch!=i)
            {
                if(hash[i].size()%2==1)
                {
                    int sza=hash[i].size();
                    int szb=hash[ch].size();
                    cout<<hash[i][sza-1]<<" "<<hash[ch][szb-1]<<endl;
                    hash[i].pop_back();
                    hash[ch].pop_back();
                }
            }
        }
        for(auto &i:arr)
        {
            char temp=i;
            int j=0;
            while(j<hash[temp].size())
            {
                cout<<hash[temp][j]<<" "<<hash[temp][j+1]<<endl;
                j+=2;
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