#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>frequency1,frequency2;
    frequency1.assign(k+1,0);
    frequency2.assign(k+1,0);
    vector<int>Arr1(n),Arr2(m);
    for(int i=0;i<n;++i)
    {
        cin>>Arr1[i];
        if(Arr1[i]>=1 && Arr1[i]<=k)
        {
            frequency1[Arr1[i]]++;
        }
    }
    for(int i=0;i<m;++i)
    {
        cin>>Arr2[i];
        if(Arr2[i]>=1 && Arr2[i]<=k)
        {
            frequency2[Arr2[i]]++;
        }
    }
    int count=0,count1=0,count2=0;
    for(int i=1;i<=k;++i)
    {
        if(frequency1[i]==0 && frequency2[i]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
        else if(frequency1[i]==0)
        {
            count2++;
        }
        else if(frequency2[i]==0)
        {
            count1++;
        }
        else
        {
            count++;
        }
        if(count1>k/2 || count2>k/2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if((count1+count<k/2) || (count2+count<k/2))
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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