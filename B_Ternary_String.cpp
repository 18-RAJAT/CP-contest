#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<vector<int>>give(3);
        int val=s.size();
        for(int i=0;i<val;++i)
        {
            give[s[i]-'1'].push_back(i);
        }
        if(give[0].empty() || give[1].empty() || give[2].empty())
        {
            cout<<"0\n";
        }
        else
        {
            int ans=val;
            for(int i=0;i<val;++i)
            {
                auto itr1=lower_bound(give[0].begin(),give[0].end(),i);
                auto itr2=lower_bound(give[1].begin(),give[1].end(),i);
                auto itr3=lower_bound(give[2].begin(),give[2].end(),i);

                if(itr1!=give[0].end() && itr2!=give[1].end() && itr3!=give[2].end())
                {
                    int chk=max(*itr1,max(*itr2,*itr3));
                    ans=min(ans,chk-i+1);
                }
            }
            cout<<ans<<"\n";
        }
    }
}