#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,m;cin>>n>>m;
    string s;cin>>s;
    bool ok(true);
    while(m--&&ok)
    {
        ok=false;
        vector<int>a;
        if(s[0]=='0' && s[1]=='1')
        {
            a.push_back(0);
        }
        if(s[n-1]=='0' && s[n-2]=='1')
        {
            a.push_back(n-1);
        }
        for(int i=1;i<n-1;++i)
        {
            if(s[i]=='0' && s[i+1]-'0'+s[i-1]-'0'==1)
            {
                a.push_back(i);
            }
        }
        for(auto&it:a)
        {
            s[it]='1';
        }
        if(a.size())
        {
            ok=true;
        }
    }
    cout<<s<<"\n";
}
int main()
{
	long long t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}