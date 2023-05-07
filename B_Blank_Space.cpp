#include<bits/stdc++.h>
using namespace std;

void B()
{
    int n;
    std::cin>>n;
    int zero,ans;
    zero=ans=0;

    std::vector<int>ar(n,0);
    for(auto&it:ar)
    {
        std::cin>>it;
        if(it==0)
        {
            zero++;
        }
        else
        {
            zero=0;
        }
        ans=max<int>(ans,zero);
    }
    std::cout<<ans<<"\n";
}

int main()
{
    int tc;
    std::cin>>tc;
    while(tc--)
    {
        B();
    }
    return 0;
}