#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template
int cmp(int x){return x*(x+1)/2;}
int Interval(vector<int>& v,int n)
{
    if(v.empty())return 0;
    int tot=cmp(n),res=0,prev=0;
    for(int i=0;i<v.size();++i)
    {
        int s=prev+1,e=v[i]-1;
        if(s<=e)
        {
            int x=e-s+1;
            res+=cmp(x);
        }
        prev=v[i];
    }
    int s=prev+1,e=n;
    if(s<=e)
    {
        int x=e-s+1;
        res+=cmp(x);
    }
    return tot-res;
}
//Template modified(Merge=3)
void Merge(vector<int>& v1,vector<int>& v2,vector<int>& v3)
{
    v3.clear(),v3.reserve(v1.size()+v2.size());
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            if(v3.empty() || v3.back()<v1[i])v3.push_back(v1[i]);
            i++;
        }
        else if(v1[i]>v2[j])
        {
            if(v3.empty() || v3.back()<v2[j])v3.push_back(v2[j]);
            j++;
        }
        else
        {
            if(v3.empty() || v3.back()<v1[i])v3.push_back(v1[i]);
            i++,j++;
        }
    }
    while(i<v1.size())
    {
        if(v3.empty() || v3.back()<v1[i])v3.push_back(v1[i]);
        i++;
    }
    while(j<v2.size())
    {
        if(v3.empty() || v3.back()<v2[j])v3.push_back(v2[j]);
        j++;
    }
    // while(!v3.empty() && v3.back())v3.pop_back();
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    vector<vector<int>>pos(n+1);
    for(int i=0;i<n;++i)pos[a[i]].push_back(i+1);
    vector<int>cnt(n+1,0);
    for(int i=1;i<=n;++i)
    {
        if(!pos[i].empty())cnt[i]=Interval(pos[i],n);
    }
    int s=0;
    for(int i=1;i<=n;++i)s+=cnt[i];
    int e=0;
    vector<int>temp;
    temp.reserve(100);
    for(int i=1;i<=n-1;++i)
    {
        if(pos[i].empty() || pos[i+1].empty())continue;
        Merge(pos[i],pos[i+1],temp);
        int take=Interval(temp,n),res=cnt[i]+cnt[i+1]-take;
        e+=res;
    }
    cout<<s-e<<endl;
}
signed main()
{
    sol();
    return 0;
}