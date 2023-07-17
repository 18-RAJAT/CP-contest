#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        int n;cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        int cnt[3]={};
        for(int i=0;i<n;++i)
        {
            if(a[i]==0 && b[i]==0)
            {
                continue;
            }
            if(a[i]==0)
            {
                cnt[1]++;
                cnt[2]++;
                continue;
            }
            if(b[i]==0)
            {
                cnt[0]++;
                cnt[2]++;
                continue;
            }
            int tmp=1;
            while(b[i]!=0)
            {
                if(b[i]<a[i])
                {
                    a[i]%=(2*b[i]);
                }
                int get=abs<int>(a[i]-b[i]);
                a[i]=b[i];
                b[i]=get;

                tmp++;tmp%=3;
            }
            for(int i=0;i<3;i+=1)
            {
                if(i!=tmp)
                {
                    cnt[i]++;
                }
            }
        }
        cout<<(!(cnt[0] && cnt[1] && cnt[2])?"YES":"NO")<<"\n";
	}
	return 0;
}