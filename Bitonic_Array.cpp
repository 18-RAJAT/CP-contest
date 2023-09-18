#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>binarySearch(vector<int>&arr,int key)
{
    vector<int>pos;
    int left=0,right=arr.size()-1;
    int peakIndex=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]>arr[mid+1])
        {
            peakIndex=mid;
            right=mid-1;
        }
        else if(arr[mid]<arr[mid+1])
        {
            left=mid+1;
        }
        else
        {
            peakIndex=mid;
            break;
        }
    }
    //left to peakIndex
    left=0,right=peakIndex;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==key)
        {
            pos.push_back(mid+1);
            break;
        }
        else if(arr[mid]<key)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    for(int i=0;i<pos.size();++i)
    {
        for(int j=i+1;j<pos.size();++j)
        {
            if(pos[i]>pos[j])
            {
                swap(pos[i],pos[j]);
            }
            // cout<<pos[i]<<" ";
        }
    }
    //peakIndex+1 to right
    left=peakIndex+1,right=arr.size()-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==key)
        {
            pos.push_back(mid+1);
            break;
        }
        else if(arr[mid]<key)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    for(int i=0;i<pos.size();++i)
    {
        for(int j=i+1;j<pos.size();++j)
        {
            if(pos[i]>pos[j])
            {
                swap(pos[i],pos[j]);
            }
            // cout<<pos[i]<<" ";
        }
    }
    return pos;
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>arr(n);
        for(int i=0;i<n;++i)
        {
            cin>>arr[i];
        }
        while(q--)
        {
            int key;
            cin>>key;
            vector<int>pos=binarySearch(arr,key);
            for(int i=0;i<pos.size();++i)
            {
                cout<<pos[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}