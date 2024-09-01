#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int black=0,white=0;
    array<int,26>arr;
    arr.fill(0);
    arr['Q'-'A']=9;
    arr['R'-'A']=5;
    arr['B'-'A']=3;
    arr['N'-'A']=3;
    arr['P'-'A']=1;
    for(int i=0;i<8*8;++i)
    {
        char ch;
        cin>>ch;
        if(ch>='a' && ch<='z')
        {
            black+=arr[ch-'a'];
        }
        else if(ch>='A' && ch<='Z')
        {
            white+=arr[ch-'A'];
        }
    }
    if(black<white)cout<<"White";
    else if(black>white)cout<<"Black";
    else cout<<"Draw";
}
signed main()
{
    sol();
    return 0;
}