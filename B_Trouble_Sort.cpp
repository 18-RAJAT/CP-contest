#include<bits/stdc++.h>
using namespace std;


void sol()
{
    int n;
    cin>>n;

    int frequency0=0;
    int frequency1=0;
    int count=0;

    int y;
    cin>>y;
    for(int i=1;i<n;++i)
    {
        int x;
        cin>>x;
        if(x<y)
        {
            count++;
        }
        y=x;
    }
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x==0)
        {
            frequency0++;
        }
        else
        {
            frequency1++;
        }
    }
    if(count==0)
    {
        cout<<"Yes\n";
        return;
    }
    if(frequency0>0 and frequency1>0)
    {
        cout<<"Yes\n";
        return;
    }
    else
    {
        cout<<"No\n";
        return;
    }
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}