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
        int right=-1;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            if(a[i]==n)
            {
                right=i;
            }
        }
        if(n==1)
        {
            cout<<"1"<<"\n";
            // delete[] a;            
            // return 0;
            continue;
        }
        if(right==0)
        {
            for(int i=0;i<n;++i)
            {
                if(a[i]==n-1)
                {
                    right=i;
                }
            }
        }
        vector<int>ans(n);
        // for(int i=0;i<n;++i)
        // {
        //     ans[i]=1;
        // }
        if(right==n-1)
        {
            ans[0]=a[n-1];
            for(int i=1;i<n;++i)
            {
                ans[i]=a[i-1];
            }
        }
        for(int left=0;left<right;left++)
        {
            vector<int>curr(n);
            int cnt=0;
            for(int j=right;j<n;j++)
            {
                curr[cnt++]=a[j];
            }
            for(int j=right-1;j>=left;j--)
            {
                curr[cnt++]=a[j];
            }
            for(int j=0;j<left;j++)
            {
                curr[cnt++]=a[j];
            }
            // if(memcmp(curr,ans,n*sizeof(int))>0)
            // {
            //     swap(ans,curr);
            // }
            bool currGreater=false;
            for(int i=0;i<n;++i)
            {
                if(ans[i]<curr[i])
                {
                    currGreater=true;
                    break;
                }
                else if(ans[i]>curr[i])
                {
                    break;
                }
            }
            if(currGreater)
            {
                swap(ans,curr);
            }
            // if(ans<curr)
            // {
            //     swap(ans,curr);
            // }
            // delete[] curr;
        }
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
        // delete[] ans;
        // delete[] a;
    }
}