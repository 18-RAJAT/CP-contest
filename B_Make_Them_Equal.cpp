#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    set<int>s;
    for(auto&it:v)
    {
        cin>>it;
        s.insert(it);
    }
    vector<int>a;
    for(auto&it:s)
    {
        a.push_back(it);
    }
    if(s.size()==1)
    {
        cout<<0<<"\n";
    }
    else if(s.size()==2)
    {
        if((a[1]-a[0])%2==0)
        {
            cout<<(a[1]-a[0])/2<<"\n";
        }
        else
        {
            cout<<a[1]-a[0]<<"\n";
        }
    }
    else if(s.size()==3)
    {
        if(a[2]-a[1]==a[1]-a[0])
        {
            cout<<a[1]-a[0]<<"\n";
        }
        else
        {
            cout<<-1<<"\n";
        }
    }
    else
    {
        cout<<-1<<"\n";
    }
}