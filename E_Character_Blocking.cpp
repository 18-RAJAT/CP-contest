#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t-->0)
    {
        vector<string>s(2);
        cin>>s[0]>>s[1];
        long long int n=s[0].size();
        set<long long int>st;

        auto check=[&](long long int i)->void
        {
            st.erase(i);
            if(s[0][i]!=s[1][i])
            {
                st.insert(i);
            }
        };
        for(long long int i=0;i<n;++i)
        {
            check(i);
        }

        long long int x,y;
        cin>>x>>y;
        vector<vector<long long int>>vec(y+1);

        for(long long int i=0;i<y;++i)
        {
            for(auto it:vec[i])
            {
                // vec[i].push_back(it-'0');
                check(it);
            }

            long long int follow;
            cin>>follow;

            if(follow==1)
            {
                long long int p;
                cin>>p;
                p--;
                st.erase(p);

                if(i+x<static_cast<long long int>(vec.size()))
                {
                    vec[i+x].push_back(p);
                }
            }
            else if(follow==2)
            {
                long long int xx,xy,yy,yx;
                cin>>xx>>xy>>yy>>yx;
                xx--;xy--;yy--;yx--;

                swap(s[xx][yy],s[xy][yx]);
                check(yy);
                check(yx);
            }
            else
            {
                cout<<(st.empty()?"YES":"NO")<<"\n";
            }
        }
    }
    return(0-0);
}