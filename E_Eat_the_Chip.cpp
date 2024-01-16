#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int h,w,xa,ya,xb,yb;
    cin>>h>>w>>xa>>ya>>xb>>yb;
    if(xa>xb)
    {
        cout<<"Draw"<<endl;
        return;
    }
    auto right=[&](int a,int w,int step)->int
    {
        return min(w,a+step);
    };
    auto left=[&](int a,int w,int step)->int
    {
        return max(1ll,a-step);
    };
    if((xb-xa)&1)
    {
        //alice win if she can go right and bob can't go right or alice can go left and bob can't go left
        int step=(xb-xa)/2;
        if(ya==yb)
        {
            cout<<"Alice"<<endl;
            return;
        }
        if(ya<yb)
        {
            //go right alice win if bob can't go right
            if(min(w,yb+step)==min(w,ya+step+1))
            {
                cout<<"Alice"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
        else if(ya>yb)
        {
            if(max(1ll,yb-step)==max(1ll,ya-step-1))
            {
                cout<<"Alice"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
        else
        {
            if(max(1ll,yb-step)==max(1ll,ya-step-1))
            {
                cout<<"Alice"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
    }
    else
    {
        int step=(xb-xa)/2;
        if(ya==yb)
        {
            cout<<"Bob"<<endl;
            return;
        }
        if(ya<yb)
        {
            //go right alice win if bob can't go right
            if(max(1ll,yb-step)==max(1ll,ya-step))
            {
                cout<<"Bob"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
        else if(ya>yb)
        {
            if(min(w,yb+step)==min(w,ya+step))
            {
                cout<<"Bob"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
        else
        {
            if(min(w,yb+step)==min(w,ya+step))
            {
                cout<<"Bob"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}