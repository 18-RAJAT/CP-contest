#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int N,T;
    int sigma;
    cin>>N>>T>>sigma;
    vector<pair<int,int>> rectangles(N);
    for(int i=0;i<N;++i)
    {
        cin>>rectangles[i].first>>rectangles[i].second;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,1);
    uniform_int_distribution<> dist_nw(0,1);
    for(int tu=0;tu<T;++tu)
    {
        vector<tuple<int,int,char,int>> placements;
        int current_x=0;
        int current_y=0;
        for(int i=0;i<N;++i)
        {
            int w=rectangles[i].first;
            int h=rectangles[i].second;
            int rotate=dis(gen);
            if(rotate)
            {
                swap(w,h);
            }
            char direction=dist_nw(gen)==0?'U':'L';
            int id=-1;
            if(direction=='U')
            {
                id=i>0?i-1:-1;
                current_y+=h;
            }
            else
            {
                id=i>0?i-1:-1;
                current_x+=w;
            }
            placements.emplace_back(i,rotate,direction,id);
        }

        cout<<placements.size()<<endl;
        for(const auto&placement:placements)
        {
            cout<<get<0>(placement)<<" "
                <<get<1>(placement)<<" "
                <<get<2>(placement)<<" "
                <<get<3>(placement)<<endl;
        }
        int W,H;
        cin>>W>>H;
    }
}
signed main()
{
    sol();
    return 0;
}