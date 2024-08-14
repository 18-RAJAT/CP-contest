#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
        b[i]=(i!=0)?(b[i]+b[i-1]):b[i];
    }
    int ans=0;
    string s;
    cin>>s;
    map<int,int>mp;
    int i=0,j=n-1;
    while(i<j)
    {
        if(s[i]!='L')
        {
            i++;
            continue;
        }
        if(s[j]!='R')
        {
            j--;
            continue;
        }
        ans+=(i!=0)?b[j]-b[i-1]:b[j];
        mp[i]=j;
        s[i]=s[j]='.';
        i++,j--;
    }
    cout<<ans<<endl;
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