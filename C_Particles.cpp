#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;cin>>t;
	while(t--)
	{
        long long int n;
        cin>>n;
        long long int a[n];
        for(long long int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        long long int b[3]={0,0,*max_element(a,a+n)};
        if(b[2]<0)
        {
            cout<<b[2]<<"\n";
        }
        else
        {
            for(long long int i=0;i<n;++i)
            {
                if(a[i]>0)
                {
                    b[i%2]+=a[i];
                }
            }
            cout<<max<long long int>(b[0],b[1])<<"\n";
        }
	}
	return 0;
}