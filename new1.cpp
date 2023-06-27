#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int count[1001][5];
    while(n--)
    {
        string s;
        cin>>s;
        for(int i=0;i<m;++i)
        {
            count[i][s[i]-'A']++;
        }
    }
    int ans=0;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        ans+=(x*(*max_element(count[i],count[i]+5)))
    }
    cout<<ans;
}