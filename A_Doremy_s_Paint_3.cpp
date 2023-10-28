#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int c1=0,c2=0;
    set<int>s;
    vector<int>v;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        v.push_back(x);
        s.insert(x);
    }
    if(s.size()>=3)
    {
        puts("No");
        return;
    }
    if(s.size()==1)
    {
        puts("Yes");
        return;
    }
    for(int i=0;i<n;++i)
    {
        if(v[0]==v[i])
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    if(abs(c1-c2)<2)
    {
        puts("Yes");
        return;
    }
    puts("No");
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