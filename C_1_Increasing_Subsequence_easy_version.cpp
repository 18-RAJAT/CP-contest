#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    vector<int>ans;
    int left=0,right=n-1;
    int last=0;
    while(left<=right)
    {
        if(arr[left]>last && arr[right]>last)
        {
            if(arr[left]<arr[right])
            {
                last=arr[left];
                ans.push_back(1);
                left++;
            }
            else if(arr[right]<arr[left])
            {
                last=arr[right];
                ans.push_back(2);
                right--;
            }
            else
            {
                int l=left,r=right;
                while(l<=r && arr[l]==arr[r])
                {
                    l++;
                    r--;
                }
                // cout<<l<<" "<<r<<endl;
                (l>r || arr[l]<arr[r])?(last=arr[left],ans.push_back(1),left++):(last=arr[right],ans.push_back(2),right--);
            }
        }
        else if(arr[left]>last)
        {
            last=arr[left];
            ans.push_back(1);
            left++;
        }
        else if(arr[right]>last)
        {
            last=arr[right];
            ans.push_back(2);
            right--;
        }
        else
        {
            break;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<(string)(ans[i]==1?"L":"R");
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}