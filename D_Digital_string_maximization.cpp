#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<n;++i)
    {
        int j=i;
        while(j>=1 && s[j]>'0' && s[j]>s[j-1]+1)
        {
            s[j]--;
            swap(s[j],s[j-1]);
            j--;
        }
    }
    cout<<s<<endl;
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