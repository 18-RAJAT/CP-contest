#include<bits/stdc++.h>
using namespace std;
#define int long long
void ForX(vector<int>&a,vector<int>&move,int x,string&add)
{
    a[x]--,move[x]--,add="x-";
}
void ForY(vector<int>&a,vector<int>&move,int y,string&add)
{
    a[y]--,move[y]--,add="y-";
}
signed main()
{
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>>query(q);
    for(auto&it:query)
    {
        cin>>it.first>>it.second;
    }
    vector<int>fz(n+1,0);
    for(auto&it:query)
    {
        int x=it.first;
        int y=it.second;
        fz[x]++;
        fz[y]++;
    }
    vector<int>Fix(n+1,0),move_p(n+1,0);
    for(int p=1;p<=n;++p)
    {
        Fix[p]=fz[p]/2;
        move_p[p]=Fix[p];
    }
    vector<int>a(n+1,0);
    vector<string>ans(q,"");
    for(int i=0;i<q;++i)
    {
        int x=query[i].first;
        int y=query[i].second;
        string add="";
        bool X_Dsc=(a[x]>0&&move_p[x]>0);
        bool Y_Dsc=(a[y]>0&&move_p[y]>0);
        if(X_Dsc || Y_Dsc)
        {
            if(X_Dsc && Y_Dsc)
            {
                (move_p[x]>move_p[y])?ForX(a,move_p,x,add):ForY(a,move_p,y,add);
            }
            else if(X_Dsc)
            {
                ForX(a,move_p,x,add);
            }
            else
            {
                ForY(a,move_p,y,add);
            }
        }
        else
        {
            if(move_p[x]>move_p[y])
            {
                a[x]++;
                add="x+";
            }
            else
            {
                a[y]++;
                add="y+";
            }
        }
        ans[i]=add;
        fz[x]--,fz[y]--;
    }
    for(int i=0;i<q;++i)
    {
        cout<<ans[i]<<"\n";
    }
}