#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n),matching(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]--;
        c[a[i]]=i;
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        b[i]--;
    }
    for(int i=0;i<n;++i)
    {
        int x;
        if(c[b[i]]<i)
        {
            x=c[b[i]]+n-i;
        }
        else
        {
            x=c[b[i]]-i;
        }
        matching[x]++;
    }
    cout<<*max_element(matching.begin(),matching.end());
}