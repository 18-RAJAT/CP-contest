#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+1];memset(a,0,sizeof(a));
    vector<int>increasing,decreasing;

    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;++i)
    {
        if(a[i]==a[i+1])
        {
            increasing.push_back(a[i]);
        }
        if(a[i]!=a[i+1])
        {
            decreasing.insert(decreasing.begin(),a[i]);
        }
        if(a[i]==a[i+1] and a[i+1]==a[i+2])
        {
            cout<<"NO"<<"\n";
            return 0;
        }
    }

    cout<<"YES"<<"\n";
    
    cout<<increasing.size()<<"\n";
    for(int i=0;i<increasing.size();++i)
    {
        cout<<increasing[i]<<" ";
    }
    cout<<"\n";

    cout<<decreasing.size()<<"\n";
    for(int i=0;i<decreasing.size();++i)
    {
        cout<<decreasing[i]<<" ";
    }
    cout<<"\n";
}