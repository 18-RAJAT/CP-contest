#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        string s;
        for(int i=0;i<8;i+=1)
        {
            for(int j=0;j<8;j+=1)
            {
                char c;
                cin>>c;
                if(c!='.')
                {
                    s+=c;
                }
            }
        }
        cout<<s<<"\n";
    }
}