#include<bits/stdc++.h>
using namespace std;
#define int long long
bool test(const vector<int>&a,const string& b,int n)
{
    map<int,char>ic;
    map<char,int>ci;
    for(int i=0;i<n;++i)
    {
        if(ci.count(b[i]))
        {
            if(ci[b[i]]!=a[i])return false;
        }
        if(ic.count(a[i]))
        {
            if(ic[a[i]]!=b[i])return false;
        }
        ci[b[i]]=a[i];
        ic[a[i]]=b[i];
    }
    return true;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& i:a)cin>>i;
    int m;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        string s;
        cin>>s;
        if(n!=s.size())
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<((test(a,s,n))?"YES":"NO")<<endl;
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