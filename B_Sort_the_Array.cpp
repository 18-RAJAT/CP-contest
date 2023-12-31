#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n];
    vector<int>array,arr;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;++i)
    {
        if(a[i]!=b[i])
        {
            // array.push_back(b[i]);
            arr.push_back(i+1);
        }
    }
    if(arr.size()==0)
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1;
    }
    else
    {
        int f=arr[0],l=arr[arr.size()-1];
        for(int i=f-1;i<l;++i)
        {
            array.push_back(b[i]);
        }
        reverse(array.begin(),array.end());
        if(is_sorted(array.begin(),array.end()))
        {
            cout<<"yes"<<endl;
            cout<<arr[0]<<" "<<arr[arr.size()-1];
        }
        else
        {
            cout<<"no";
        }
    }
}
signed main()
{
    sol();
    return 0;
}