#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    vector<int>a(8);//fixed
    for(auto&it:a)
    {
        cin>>it;
        it=n/it;
    }
    int mx=0,value=0;
    // int mx=max_element(a.begin(),a.end())-a.begin()+1;
    // int value=*max_element(a.begin(),a.end());
    for(int i=0;i<8;++i)
    {
        if(value<=a[i])// || (value==a[i] && mx>i+1))
        {
            value=a[i];
            mx=i+1;
        }
    }
    if(value==0)
    {
        cout<<"-1";
    }
    while(value--)
    {
        cout<<mx;
    }
}