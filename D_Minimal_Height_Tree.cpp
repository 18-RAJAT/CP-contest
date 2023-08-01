#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>depth(n);
        int x;
        cin>>x;
        --x;
        int ans=0;
        deque<int>q;
        for(int i=1;i<n;++i)
        {
            int y;
            cin>>y;
            --y;
            if(y<ans)
            {
                x=q[0];
                q.pop_front();
            }
            depth[y]=depth[x]+1;
            q.push_back(y);
            ans=y;
        }
        cout<<*max_element(depth.begin(),depth.end())<<"\n";
    }
}