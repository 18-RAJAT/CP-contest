#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int R,C;
    cin>>R>>C;
    vector<string>grid(R+2,string(C+2,'.'));
    for(int r=1;r<=R;++r)
    {
        string row;
        cin>>row;
        for(int c=1;c<=C;++c)
        {
            grid[r][c]=row[c-1];
        }
    }
    int tot=0;
    for(int r=1;r<=R;++r)
    {
        for(int c=1;c<=C;++c)
        {
            if(grid[r][c]=='/' || grid[r][c]=='\\')
            {
                tot++;
            }
        }
    }
    vector<string>pos;
    int dr[4]={-1,0,1,0},dc[4]={0,1,0,-1};
    int Dx[4]={1,0,3,2},Dy[4]={3,2,1,0};
    for(int c=1;c<=C;++c)
    {
        int r=0,init=c,dir=2;
        set<tuple<int,int,int>>vis_state;
        unordered_set<int>image;
        r+=dr[dir];
        init+=dc[dir];
        bool F=false;
        while(true)
        {
            if(r<1 || r>R || init<1 || init>C) break;
            auto state=make_tuple(r,init,dir);
            if(vis_state.count(state))
            {
                F=true;
                break;
            }
            vis_state.insert(state);
            if(grid[r][init]=='/')
            {
                dir=Dx[dir];
                image.insert(r*(C+2)+init);
            }
            else if(grid[r][init]=='\\')
            {
                dir=Dy[dir];
                image.insert(r*(C+2)+init);
            }
            r+=dr[dir];
            init+=dc[dir];
        }
        if(!F && image.size()==tot)
        {
            pos.push_back("N"+to_string(c));
        }
    }
    for(int c=1;c<=C;++c)
    {
        int r=R+1,init=c,dir=0;
        set<tuple<int,int,int>>vis_state;
        unordered_set<int>image;
        r+=dr[dir];
        init+=dc[dir];
        bool F=false;
        while(true)
        {
            if(r<1 || r>R || init<1 || init>C) break;
            auto state=make_tuple(r,init,dir);
            if(vis_state.count(state))
            {
                F=true;
                break;
            }
            vis_state.insert(state);
            if(grid[r][init]=='/')
            {
                dir=Dx[dir];
                image.insert(r*(C+2)+init);
            }
            else if(grid[r][init]=='\\')
            {
                dir=Dy[dir];
                image.insert(r*(C+2)+init);
            }
            r+=dr[dir];
            init+=dc[dir];
        }
        if(!F && image.size()==tot)
        {
            pos.push_back("S"+to_string(c));
        }
    }
    for(int r=1;r<=R;++r)
    {
        int Sides=r,init=0,dir=1;
        set<tuple<int,int,int>>vis_state;
        unordered_set<int> image;
        Sides+=dr[dir];
        init+=dc[dir];
        bool F=false;
        while(true)
        {
            if(Sides<1 || Sides>R || init<1 || init>C) break;
            auto state=make_tuple(Sides,init,dir);
            if(vis_state.count(state))
            {
                F=true;
                break;
            }
            vis_state.insert(state);
            if(grid[Sides][init]=='/')
            {
                dir=Dx[dir];
                image.insert(Sides*(C+2)+init);
            }
            else if(grid[Sides][init]=='\\')
            {
                dir=Dy[dir];
                image.insert(Sides*(C+2)+init);
            }
            Sides+=dr[dir];
            init+=dc[dir];
        }
        if(!F && image.size()==tot)
        {
            pos.push_back("W"+to_string(r));
        }
    }
    for(int r=1;r<=R;++r)
    {
        int Sides=r,init=C+1,dir=3;
        set<tuple<int,int,int>>vis_state;
        unordered_set<int>image;
        Sides+=dr[dir];
        init+=dc[dir];
        bool F=false;
        while(true)
        {
            if(Sides<1 || Sides>R || init<1 || init>C) break;
            auto state=make_tuple(Sides,init,dir);
            if(vis_state.count(state))
            {
                F=true;
                break;
            }
            vis_state.insert(state);
            if(grid[Sides][init]=='/')
            {
                dir=Dx[dir];
                image.insert(Sides*(C+2)+init);
            }
            else if(grid[Sides][init]=='\\')
            {
                dir=Dy[dir];
                image.insert(Sides*(C+2)+init);
            }
            Sides+=dr[dir];
            init+=dc[dir];
        }
        if(!F && image.size()==tot)
        {
            pos.push_back("E"+to_string(r));
        }
    }
    cout<<pos.size()<<endl;
    if(!pos.empty())
    {
        for(int i=0;i<pos.size();++i)
        {
            cout<<pos[i];
            if(i+1<pos.size())
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}