#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>zero,one,ans;
    int current=1;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='0')
        {
            if(one.empty())
            {
                zero.push_back(current);
                ans.push_back(current);
                current++;
            }
            else
            {
                int x=one.back();
                one.pop_back();
                zero.push_back(x);
                ans.push_back(x);
            }
        }
        else
        {
            if(zero.empty())
            {
                one.push_back(current);
                ans.push_back(current);
                current++;
            }
            else
            {
                int x=zero.back();
                zero.pop_back();
                one.push_back(x);
                ans.push_back(x);
            }
        }
    }
    cout<<current-1<<'\n';
    for(auto& i:ans)
    {
        cout<<i<<' ';
    }
    cout<<'\n';
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