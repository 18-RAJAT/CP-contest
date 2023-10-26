#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int q;
    cin>>q;
    int l=1,r=INT64_MAX ;
    function<int(int,int,int)>days=[&](int a,int b,int h)->int
    {
        if(h<=a)
        {
            return 1;
        }
        int day=(h-b-1)/(a-b);
        return 1+day;
    };
    for(int i=1;i<=q;++i)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int a,b,n;
            cin>>a>>b>>n;
            int low=0,high=INT64_MAX ;
            while(high!=low)
            {
                int mid=(low+high)/2;
                if(days(a,b,mid)<n)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid;
                }
            }
            int L=low;
            low=0,high=INT64_MAX ;
            while(high!=low)
            {
                int mid=(low+high+1)/2;
                if(days(a,b,mid)>n)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid;
                }
            }
            int R=low;
            if(R<l || L>r)
            {
                cout<<0<<" ";
            }
            else
            {
                cout<<1<<" ";
                r=min(R,r);
                l=max(L,l);
            }
        }
        else
        {
            int a,b;
            cin>>a>>b;
            int day1=days(a,b,l);
            int day2=days(a,b,r);
            if(day1==day2)
            {
                cout<<day1<<" ";
            }
            else
            {
                cout<<-1<<" ";
            }
        }
    }
    cout<<"\n";
}
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
    sol();
  }
  return 0;
}