#include<bits/stdc++.h>
using namespace std;
#define int long long

struct st{int x,y,id;};
void sol()
{
    int n,m,sx,sy;
    cin>>n>>m>>sx>>sy;
    vector<st>h(n);
    for(int i=0;i<n;++i)
    {
        cin>>h[i].x>>h[i].y;
        h[i].id=i;
    }
    vector<st>tmp=h;
    sort(tmp.begin(),tmp.end(),[&](const st&a,const st&b)->bool
    {
        if(a.y!=b.y)return a.y<b.y;
        return a.x<b.x;
    });
    vector<st>xs=h;
    sort(xs.begin(),xs.end(),[&](const st&a,const st&b)->bool
    {
        if(a.x!=b.x)return a.x<b.x;
        return a.y<b.y;
    });
    vector<int>X,Y;
    vector<vector<pair<int,int>>>Dm,Cm;
    if(n>=1)
    {
        X.push_back(tmp[0].y);
        Dm.emplace_back();
    }
    for(auto& it:tmp)
    {
        if(it.y!=X.back())
        {
            X.push_back(it.y);
            Dm.emplace_back();
        }
        Dm.back().emplace_back(it.x,it.id);
    }
    if(n>=1)
    {
        Y.push_back(xs[0].x);
        Cm.emplace_back();
    }
    for(auto& it:xs)
    {
        if(it.x!=Y.back())
        {
            Y.push_back(it.x);
            Cm.emplace_back();
        }
        Cm.back().emplace_back(it.y,it.id);
    }
    vector<char>ch(n,0);
    int cx=sx,cy=sy,cnt=0;
    for(int i=0;i<m;++i)
    {
        char d;
        int c;
        cin>>d>>c;
        int nx=cx,ny=cy;
        if(d=='U')ny+=c;
        else if(d=='D')ny-=c;
        else if(d=='L')nx-=c;
        else if(d=='R')nx+=c;
        //First Direction range[nx,ny]
        if(d=='U' || d=='D')
        {
            int res=cx,tmp1=cy,tmp2=ny;
            if(tmp1>tmp2)swap(tmp1,tmp2);
            // cout<<res<<" "<<tmp1<<" "<<tmp2<<endl;
            int xi=lower_bound(Y.begin(),Y.end(),res)-Y.begin();
            if(xi<Y.size() && Y[xi]==res)
            {
                auto& ert=Cm[xi];
                //Rajat joshi template
                int LB=lower_bound(ert.begin(),ert.end(),make_pair(tmp1,-1LL),[&](const pair<int,int>&a,const pair<int,int>&b)->bool
                {
                    return a.first<b.first;
                })-ert.begin();
                int UB=upper_bound(ert.begin(),ert.end(),make_pair(tmp2,(int)1e9),[&](const pair<int,int>&a,const pair<int,int>&b)->bool
                {
                    return a.first<b.first;
                })-ert.begin();
                for(int j=LB;j<UB;++j)
                {
                    int hi=ert[j].second;
                    if(!ch[hi])ch[hi]=1,cnt++;
                }
            }
        }
        //Second Direction range[cx,cy]
        else
        {
            int res=cy,tmp1=cx,tmp2=nx;
            if(tmp1>tmp2)swap(tmp1,tmp2);
            // cout<<res<<" "<<tmp1<<" "<<tmp2<<endl;
            int xi=lower_bound(X.begin(),X.end(),res)-X.begin();
            if(xi<X.size() && X[xi]==res)
            {
                auto& ert=Dm[xi];
                //Rajat joshi template
                int LB=lower_bound(ert.begin(),ert.end(),make_pair(tmp1,-1LL),[&](const pair<int,int>&a,const pair<int,int>&b)->bool
                {
                    return a.first<b.first;
                })-ert.begin();
                int UB=upper_bound(ert.begin(),ert.end(),make_pair(tmp2,(int)1e9),[&](const pair<int,int>&a,const pair<int,int>&b)->bool
                {
                    return a.first<b.first;
                })-ert.begin();
                for(int j=LB;j<UB;++j)
                {
                    int hi=ert[j].second;
                    if(!ch[hi])ch[hi]=1,cnt++;
                }
            }
        }
        cx=nx;
        cy=ny;
    }
    cout<<cx<<" "<<cy<<" "<<cnt<<endl;
}
signed main()
{
    sol();
    return 0;
}