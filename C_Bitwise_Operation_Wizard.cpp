#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n;
    cin>>n;
    int index=0;
    int increment=1;
    for(int i=0;i<n-1;++i)
    {
        cout<<"? "<<index<<" "<<index<<" "<<increment<<" "<<increment<<endl;
        cout.flush();
        char ch;
        cin>>ch;
        if(ch=='<')
        {
            index=increment;
        }
        else if(ch=='=')
        {
            index=increment;
        }
        increment++;
    }
    increment=0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(index==increment)
        {
            increment++;
        }
        if(ans==increment)
        {
            ans++;
        }
        if(ans==index)
        {
            ans++;
        }
        if(ans==increment)
        {
            ans++;
        }
        if(n<=ans)
        {
            break;
        }
        cout<<"? "<<index<<" "<<increment<<" "<<index<<" "<<ans<<endl;
        cout.flush();
        char ch;
        cin>>ch;
        if(ch=='<')
        {
            increment=ans;
        }
        else if(ch=='=')
        {
            cout<<"? "<<increment<<" "<<increment<<" "<<ans<<" "<<ans<<endl;
            cout.flush();
            char ch;
            cin>>ch;
            if(ch=='>')
            {
                increment=ans;
            }
        }
        ans++;
    }
    cout<<"! "<<index<<" "<<increment<<endl;
    cout.flush();
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