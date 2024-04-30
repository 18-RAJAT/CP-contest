#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int ans=0;
    tuple<int,int>shift={0,0};
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='1')
        {
            get<0>(shift)++;
        }
        else
        {
            if(get<0>(shift))
            {
                get<1>(shift)+=1+get<0>(shift);
            }
        }
    }
    cout<<get<1>(shift)<<endl;
}
signed main()
{
    int shift;
    cin>>shift;
    while(shift--)
    {
        sol();
    }
    return 0;
}