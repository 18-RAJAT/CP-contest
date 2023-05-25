#include<bits/stdc++.h>
using namespace std;

vector<int>a[17];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<pow(2,n);++i)
    {
        int p;
        cin>>p;
        a[0].push_back(p);
    }

    int index=1;
    int q=n;
    while(q-->0)
    {
        if(index%2)
        {
            for(int i=0;i<a[index-1].size();i+=2)
            {
                a[index].push_back(a[index-1][i] | a[index-1][i+1]);
            }
        }
        else
        {
            for(int i=0;i<a[index-1].size();i+=2)
            {
                a[index].push_back(a[index-1][i] ^ a[index-1][i+1]);
            }
        }
        index++;
    }
    while(m-->0)
    {
        int x,y;
        cin>>x>>y;
        x--;
        int ert=n;
        while(ert-->0)
        {
            a[index-1][x]=y;
            if(x%2==0)
            {
                if(index%2)
                {
                    // x+=2;
                    y|=a[index-1][x+1];
                }
                else
                {
                    // x+=1;
                    y^=a[index-1][x+1];
                }
                x/=2;
            }
            else
            {
                if(index%2)
                {
                    y|=a[index-1][x-1];
                }
                else
                {
                    y^=a[index-1][x-1];
                }
                x/=2;
            }
            if(ert==0)
            {
                cout<<a[index-1][x]<<"\n";
            }
            index++;
        }
    }
    return 0;
}