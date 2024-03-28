#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    tuple<string,int>ans={s,1};
    for(int k=2;k<n;++k)
    {
        string str1=s.substr(k-1,n-(k-1));
        string str2=s.substr(0,k-1);
        if(n&1)
        {
            if(k&1)
            {
                reverse(str2.begin(),str2.end());
            }
        }
        else
        {
            if(~k&1)
            {
                reverse(str2.begin(),str2.end());
            }
        }
        str1+=str2;
        if(make_tuple(str1,k)<ans)
        {
            ans=make_tuple(str1,k);
        }
    }
    string str1=s;
    reverse(str1.begin(),str1.end());
    cout<<((make_tuple(str1,n)>ans)?get<0>(ans):str1)<<endl<<((make_tuple(str1,n)>ans)?get<1>(ans):n)<<endl;
}
signed main()
{
    int str1;
    cin>>str1;
    while(str1--)
    {
        sol();
    }
    return 0;
}