#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(auto&it:a)
        {
            cin>>it;
        }
        sort(a.begin(),a.end());
        int left=0,right=1e9;
        int temp=right;

        while(left<=right)
        {
            int mid=(left+right)>>1;
            int last=0;
            int partition=0;
            for(int i=0;i<=n-1;i+=1)
            {
                if(a[i]-a[last]>2*mid)
                {
                    last=i;partition++;
                }
            }
            if(partition<=2)
            {
                temp=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        cout<<temp<<"\n";
    }
}