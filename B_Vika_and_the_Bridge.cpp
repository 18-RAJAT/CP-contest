#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,k,a[N],b[N];
void sol()
{
    int pos[N];
    function<bool(int,int)>recur=[&](int i,int d)->bool
    {
        bool ok=true;
        if(pos[i]-1>2*d+1)
        {
            return false;
        }
        if(pos[i]-1>d)
        {
            ok=false;
        }
        int tmp=pos[i];
        while(tmp<=n)
        {
            if(b[tmp]-tmp-1>2*d+1)
            {
                return false;
            }
            if(b[tmp]-tmp-1>d)
            {
                // ok=false;
                if(ok)
                {
                    ok=false;
                }
                else
                {
                    return false;
                }
            }
            tmp=b[tmp];
        }
        return true;
    };
    cin>>n>>k;
    for(int i=1;i<=n;i+=1)
    {
        cin>>a[i];
    }
    for(int i=1;i<=k;i+=1)
    {
        pos[i]=n+1;    
    }
    for(int i=n;i>=1;--i)
    {
        b[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    //binary search tech
    int left=0,right=n+1;
    while(left<right)
    {
        int mid=left+(right-left)/2;
        bool vis=false;
        for(int i=1;i<=k;i+=1)
        {
            vis|=recur(i,mid);
            // vis=recur(i,mid);
        }
        if(vis)
        {
            right=mid;
        }
        else
        {
            left=mid+1;
        }
        // cout<<left<<" "<<right<<"\n";
    }
    // cout<<(left>n?"-1":to_string(left))<<"\n";
    cout<<left<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}