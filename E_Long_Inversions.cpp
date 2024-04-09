#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int n,string s)
{
    int ans=1;
    for(int k=1;k<=n;++k)
    {
        string temp=s;
        for(int i=0;i<=n-k;++i)
        {
            if(temp[i]=='0')
            {
                temp[i]='1';
                if(i+k<n)
                {
                    temp[i+k]=(temp[i+k]=='0')?'1':'0';
                }
            }
        }
        if(count(temp.begin(),temp.end(),'1')==n)
        {
            ans=k;
            break;
        }
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<recur(n,s)<<endl;
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