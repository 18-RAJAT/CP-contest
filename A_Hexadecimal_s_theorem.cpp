#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    if(n==0)
    {
        cout<<"0 0 0"<<"\n";
    }
    else if(n==1)
    {
        cout<<"1 0 0"<<"\n";
    }
    else if(n==2)
    {
        cout<<"1 1 0"<<"\n";
    }
    else if(n==3)
    {
        cout<<"1 1 1 "<<"\n";
    }
    else
    {
        vector<int>arr;
        arr.push_back(0);
        arr.push_back(1);

        int ctr=1;
        while(ctr<n)
        {
            ctr=arr[arr.size()-1]+arr[arr.size()-2];
            arr.push_back(ctr);
        }
        cout<<arr[arr.size()-2]<<" "<<arr[arr.size()-4]<<" "<<arr[arr.size()-5]<<"\n";
    }
}