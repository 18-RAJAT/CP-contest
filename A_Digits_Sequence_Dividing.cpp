#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        long long int n;
        cin>>n;
        string s;
        cin>>s;
        if(s.size()==2 and s[0]>=s[1])
        {
            cout<<"NO"<<"\n";
            continue;
        }
        cout<<"YES\n2\n";
        cout<<s.substr(0,1)<<" "<<s.substr(1)<<"\n";
	}
	return 0;
}