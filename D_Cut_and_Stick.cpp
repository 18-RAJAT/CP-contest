#include<bits/stdc++.h>
using namespace std;

int n,q;
int a[300005];
vector<int>sub[300005];

int main()
{
    int n,q;
    // sub[0].push_back(0);
    for(int i=0;i<300005;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<300005;i++)
    {
        sub[a[i]].push_back(i);
    }
    int ans=0;
    while(q-->0)
    {
        int left,right;
        cin>>left>>right;
        left--,right--;
        int subsLen=right-left+1;
        for(int i=0;i<subsLen;i++)
        {
            ans=max<int>(ans,upper_bound(sub[a[left+i]].begin(),sub[a[left+i]].end(),right)-lower_bound(sub[a[left+i]].begin(),sub[a[left+i]].end(),left));
        }
        cout<<ans<<"\n";
    }
}