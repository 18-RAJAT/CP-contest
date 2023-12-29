#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int a[3]={0,0,0};
    for(auto& it1:s1)
    {
        a[it1-'A']++;
    }
    for(auto& it2:s2)
    {
        a[it2-'A']++;
    }
    for(auto& it3:s3)
    {
        a[it3-'A']++;
    }
    for(int i=0;i<3;++i)
    {
        if(a[i]!=3)
        {
            cout<<char(i+'A')<<endl;
            return;
        }
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