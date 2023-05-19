#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt[100001];
    memset(cnt,0,sizeof(cnt));

    int n,m;
    cin>>n>>m;

    int used=0;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        cnt[x]++;

        if(cnt[x]==1)
        {
            used++;
        }
        if(used==n)
        {
            used=0;
            for(int j=1;j<=n;++j)
            {
                cnt[j]--;

                if(cnt[j])
                {
                    used++;
                }
            }
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
}