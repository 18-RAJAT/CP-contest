#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int i=0;
    while(i+2<n)
    {
        if(a[i]<0)
        {
            cout<<"NO"<<endl;
            return;
        }
        int tmp=a[i];
        a[i]-=tmp;
        a[i+1]-=2*tmp,a[i+2]-=tmp;
        i++;
    }
    int count_dif=count(a.begin(),a.end(),0);
    if(count_dif==n)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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