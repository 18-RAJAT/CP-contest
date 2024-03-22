#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char>a[2];
    for(int i=0;i<n;++i)
    {
        a[(s[i]-'a')%2].push_back(s[i]);
    }
    sort(a[0].begin(),a[0].end());
    sort(a[1].begin(),a[1].end());
    for(int i=0,j=0,k=0;i<n;++i)
    {
        (s[i]-'a')%2?cout<<(a[1][j++]):cout<<(a[0][k++]);
    }
    cout<<endl;
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