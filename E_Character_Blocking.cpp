#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t-->0)
    {
        vector<string>s(2);
        set<int>st;
        cin>>s[0]>>s[1];
        long long int n=s[0].size();
        int p,q;
        for(int i=0;i<n;++i)
        {
            if(s[0][i]==s[1][i])
            {
                continue;
            }
            st.insert(i);
        }
        map<int,vector<int>>mp;
        cin>>p>>q;
        for(int i=1;i<=q;++i)
        {
            for(auto& it:mp[i])
            {
                if(s[0][it]!=s[1][it])
                {
                    st.insert(it);
                }
            }
            int type;
            cin>>type;
            if(type==1)
            {
                int x;
                cin>>x;
                x--;

                if(s[0][x]!=s[1][x])
                {
                    st.erase(x);
                    mp[i+p].push_back(x);
                }
            }
            if(type==2)
            {
                int xx,xy,yx,yy;
                cin>>xx>>yx>>xy>>yy;
                xx--;xy--;yx--;yy--;

                if(s[0][yx]!=s[1][yx])
                {
                    st.erase(yx);
                }
                if(s[0][yy]!=s[1][yy])
                {
                    st.erase(yy);
                }
                swap(s[xx][yx],s[xy][yy]);
                if(s[0][yx]!=s[1][yx])
                {
                    st.insert(yx);
                }
                if(s[0][yy]!=s[1][yy])
                {
                    st.insert(yy);
                }
            }
            if(type==3)
            {
                cout<<((not st.size()?"YES":"NO"))<<"\n";
            }
        }
    }
    return(0-0);
}