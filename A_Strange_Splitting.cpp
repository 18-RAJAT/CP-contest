#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(a[0]==a[n-1])
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {   
        cout<<"YES"<<endl;
    }
    string s(n,'R');
    if(n>=2)s[1]='B';
    cout <<s<<endl;
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