#include<bits/stdc++.h>
using namespace std;

void sol()
{
    string s;cin>>s;
    string code="codeforces";
    int ans=0;
    for(int i=0;i<10;++i)
    {
        if(s[i]!=code[i])
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}