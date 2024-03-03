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
    set<int>st;
    for(int i=0;i<n;++i)
    {
        if(arr[i]!=0)
        {
            st.insert(arr[i]);
        }
    }
    vector<int>check;
    for(int i=0;i<n;++i)
    {
        if(arr[i]==0 && st.find(i+1)==st.end())
        {
            check.push_back(i+1);
        }
    }
    if(check.size()==1)
    {
        for(int i=0;i<n;++i)
        {
            if(arr[i]==0 && check[0]!=i+1)
            {
                arr[i]=check[0];
                st.insert(arr[i]);
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<check.size();++i)
        {
            int ind=check[i];
            int nxtInd=check[(i+1)%check.size()];
            arr[ind-1]=nxtInd;
            st.insert(arr[ind-1]);
        }
    }
    for(int i=0,num=1;i<n;++i)
    {
        if(arr[i]==0)
        {
            while(st.find(num)!=st.end())
            {
                num++;
            }
            arr[i]=num;
            st.insert(num);
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}