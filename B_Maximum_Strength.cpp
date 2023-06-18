#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        string s,t;
        cin>>s>>t;

        if(t.size()<s.size())
        {
            swap(s,t);
        }
        if(s.size()<t.size())
        {
            int n=s.size();
            int m=t.size();
            for(int i=n;i<m;++i)
            {
                s='0'+s;
            }
        }
        int pref=0,count=0;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(pref==0)
            {
                count+=abs(s[i]-t[i]);
                if(s[i]!=t[i])
                {
                    pref=1;
                }
                // cout<<pref<<"\n";
            }
            else
            {
                count+=9;
            }
        }
        cout<<count<<"\n";
    }
	return 0;
}