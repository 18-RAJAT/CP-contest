#include<bits/stdc++.h>
using namespace std;
#define int long long
int binary_search(int value,int n,int height[])
{
    int start=0,end=2e18;
    int ans=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int odd=(mid+1)/2;//one step ahead of mid
        int even=mid/2;//accurate mid

        bool ok=true;
        //binary search on answer space
        for(int i=0;i<n;++i)
        {
            int rem=0;
            if(even>=(value-height[i])/2)
            {
                even-=(value-height[i])/2;//if even is enough then we will use even
                rem=value-height[i]-2*((value-height[i])/2);//if even is enough then we will use even
            }
            else
            {
                rem=value-height[i]-2*even;//if even is not enough then we will use odd
                even=0;
            }
            odd-=rem;//using odd and checking if odd is enough or not
            if(odd<0)
            {
                ok=false;
            }
        }
        if(ok)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    int height[n];
    for(int i=0;i<n;++i)
    {
        cin>>height[i];
    }
    auto cmp=[](int a,int b)
    {
        return a>b;
    };
    sort(height,height+n,cmp);
    //using = (mid+1)/2 + mid/2 = mid+1 = (mid+1)/2 + (mid+1)/2 = odd + even = mid+1 = mid/2 + (mid+1)/2 = even + odd = mid+1 ......
    int binary_search_ans1=binary_search(height[0],n,height);
    int binary_search_ans2=binary_search(height[0]+1,n,height); 
    int binary_search_ans3=binary_search(height[0]+2,n,height);
    cout<<min({binary_search_ans1,binary_search_ans2,binary_search_ans3})<<"\n";
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