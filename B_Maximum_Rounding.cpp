#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    reverse(s.begin(),s.end());
    s+='0';
    int j=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]>'4')
        {
            s[i+1]++;
            //rev
            for(int k=i;k>=j;--k)
            {
                s[k]='0';
            }
            j=i;
        }
    }
    reverse(s.begin(),s.end());
    int x=0;
    if(s[0]=='0')
    {
        x++;
    }
    for(x;x<s.size();++x)
    {
        cout<<s[x];
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}