#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c[4][4];
    int cnt=0;
    for(int i=0;i<4;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<4;++j)
        {
            c[i][j]=s[j];
        }
    }
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            int cnt=0;
            if(c[i][j]=='#')
            {
                cnt++;
            }
            if(c[i+1][j]=='#')
            {
                cnt++;
            }
            if(c[i][j+1]=='#')
            {
                cnt++;
            }
            if(c[i+1][j+1]=='#')
            {
                cnt++;
            }
            if(cnt!=2)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}