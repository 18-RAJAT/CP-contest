#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        int frequency[n+1]={0};
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            if(x<=n)
            {
                frequency[x]+=1;
            }
        }
        for(int i=n;i>=1;--i)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                frequency[j]+=frequency[i];
            }
        }
        cout<<*max_element(frequency,frequency+n+1)<<"\n";
    }       
}