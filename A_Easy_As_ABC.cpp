#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    vector<string>puzzle(3);
    for(int i=0;i<3;++i)
    {
        cin>>puzzle[i];
    }
    std::vector<array<int,2>>check;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            check.push_back({i,j});
        }
    }
    string ans="XYZ";
    for(auto &dir1:check)
    {
        for(auto &dir2:check)
        {
            for(auto &dir3:check)
            {
                if(dir1!=dir2 && dir2!=dir3 && dir1!=dir3 && abs(dir1[0]-dir2[0])<2 && abs(dir1[1]-dir2[1])<2 && abs(dir2[0]-dir3[0])<2 && abs(dir2[1]-dir3[1])<2)
                {
                    string s="";
                    s+=puzzle[dir1[0]][dir1[1]];
                    s+=puzzle[dir2[0]][dir2[1]];
                    s+=puzzle[dir3[0]][dir3[1]];
                    ans=min(ans,s);
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}