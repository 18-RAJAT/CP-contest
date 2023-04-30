#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k;
    cin>>n>>k;

    auto get=[&]()->void
    {
        int temp=(n-1)/2;
        for(long long int i=0;i<temp-k;++i)
        {
            cout<<"DRUR";
        }
        cout<<"DL";
        return;
    };
    if(k<=(n/2))
    {
        for(int i=1;i<=k;++i)
        {
            cout<<"RUDL";
        }
    }
    else if(k==n/2+1)
    {
        cout<<"DL";
    }
    else if(k==n/2+2)
    {
        cout<<"DRDL";
    }
    else if(k==n/2+3)
    {
        cout<<"DRURDL";
    }
    else if(k==n/2+4)
    {
        cout<<"DRURDRDL";
    }
    else if(k==n/2+5)
    {
        cout<<"DRURDRURDL";
    }
    else if(k==n/2+6)
    {
        cout<<"DRURDRURDRDL";
    }
    else if(k==n/2+7)
    {
        cout<<"DRURDRURDRURDL";
    }
    else if(k==n/2+8)
    {
        cout<<"DRURDRURDRURDRDL";
    }
    else if(k==n/2+9)
    {
        cout<<"DRURDRURDRURDRURDL";
    }
    else if(k==n/2+10)
    {
        cout<<"DRURDRURDRURDRURDRDL";
    }
    else if(k==n/2+11)
    {
        cout<<"DRURDRURDRURDRURDRURDL";
    }
    else if(k==n/2+12)
    {
        cout<<"DRURDRURDRURDRURDRURDRDL";
    }
    else if(k==n/2+13)
    {
        cout<<"DRURDRURDRURDRURDRURDRURDL";
    }
    else if(k==n/2+14)
    {
        cout<<"DRURDRURDRURDRURDRURDRURDRDL";
    }
    else if(k==n/2+15)
    {
        cout<<"DRURDRURDRURDRURDRURDRURDRURDL";
    }
    else if(k==n/2+16)
    {
        cout<<"DRURDRURDRURDRURDRURDRURDRURDRDL";
    }
    else if(k==n/2+17)
    {
        cout<<"DRURDRURDRURDRURDRURDRURDRURDRURDL";
    }
    else if(k==n/2+18)
    {
        cout<<"DRURDRURDRURDRURDRURDRURDRURDRURDRDL";
    }
    else
    {
        for(int i=1;i<=n-2-k;++i)
        {
            cout<<"RDLU";
        }
        cout<<"R";
        // for(int i=1;i<=k-(n/2)-1;++i)
        // {
        //     cout<<"RUDL";
        // }
        for(int i=1;i<=n;++i)
        {
            cout<<"RDRU";
        }
        for(int i=1;i<=n/2-1;++i)
        {
            cout<<"LDRU";
        }
        cout<<"L";
    }
    return 0;
}