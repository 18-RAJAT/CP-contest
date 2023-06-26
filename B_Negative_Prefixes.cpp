#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(101),b(101),takes;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;++i)
        {
            if(not b[i])
            {
                takes.push_back(a[i]);
            }
        }
        sort(takes.rbegin(),takes.rend());
        int j=0;
        for(int i=0;i<n;++i)
        {
            if(b[i])
            {
                cout<<a[i]<<" ";
            }
            else
            {
                cout<<takes[j]<<" ";
                j++;
            }
        }
        cout<<"\n";
    }
}