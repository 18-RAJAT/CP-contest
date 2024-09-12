#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    pair<int,int>scores[10005];
    for(int i=0;i<n;++i)
    {
        cin>>scores[i].first>>scores[i].second;
    }
    int player1=0,player2=0,lead=0,winner=0;
    for(int i=0;i<n;++i)
    {
        player1+=scores[i].first;
        player2+=scores[i].second;
        int current_lead=abs(player1-player2);
        if(lead<current_lead)
        {
            lead=current_lead;
            winner=player2<player1?1:2;
        }
    }
    cout<<winner<<" "<<lead<<endl;
}
signed main()
{
    sol();
    return 0;
}