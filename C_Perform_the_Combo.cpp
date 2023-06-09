#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int c[200001];
    memset(c,0,sizeof(c));
    for(int i=0;i<m;++i)
    {
        c[i]=0;
    }
    int x;
    for(int i=0;i<m;++i)
    {
        cin>>x;
        c[x-1]+=1;
    }
    int arr[26];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;++i)
    {
        arr[s[i]-'a']+=(m+1);
        m-=c[i];
    }
    for(int i=0;i<26;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
    return (0-0);
}