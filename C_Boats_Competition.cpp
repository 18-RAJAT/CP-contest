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
        int a[51];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int ans(-1);
        for(int i=2;i<=1001;++i)
        {
            int count(0);
            int left(0),right(n-1);
            while(left<right)
            {
                if(a[left]+a[right]==i)
                {
                    left++;right--;count++;
                }
                else if(a[left]+a[right]<i)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            ans=max<int>(ans,count);
        }
        cout<<ans<<"\n";
    }
}