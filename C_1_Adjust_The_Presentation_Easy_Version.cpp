#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>Adjust;
    unordered_set<int>seen;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        if(Adjust.empty()||Adjust.back()!=x)Adjust.push_back(x);
    }
    int move=0,ans=1;
    int i=0;
    while(i<Adjust.size())
    {
        if(move<n&&Adjust[i]==a[move])
        {
            seen.insert(Adjust[i]);
            move++;
        }
        else if(seen.find(Adjust[i])==seen.end())
        {
            ans=0;
            break;
        }
        else
        {
            i++;
        }
    }
    cout<<(ans?"YA":"TIDAK")<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)sol();
    return 0;
}
