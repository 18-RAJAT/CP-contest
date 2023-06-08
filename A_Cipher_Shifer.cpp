#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        int n;cin>>n;
        string s;cin>>s;
        char ch='#';
        string ans="";
        for(auto it:s)
        {
            if(ch=='#')
            {
                ch=it;
            }
            else if(it==ch)
            {
                ans+=ch;ch='#'; 
            }
        }
        cout<<ans<<"\n";
	}
	return (0-0);
}