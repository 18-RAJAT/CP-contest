#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    int once=0,twos=0;
    set<int>st;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            once++;
            st.insert(i);
        }
        else
        {
            twos++;
        }
        // st.insert(a[i]);
    }
    for(int i=0;i<q;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x==1)
        {
            int value_of_o=1*once;//for getting the value of o
            int value_of_t=2*twos;//for getting the value of t
            int tot=value_of_o+value_of_t;
            // cout<<"PRINT: "<<tot<<" "<<y<<endl;
            if(tot<y)
            {
                cout<<"NO"<<endl;
            }
            // else
            // {
            //     cout<<"YES"<<endl;
            // }
            else if((y&1) && once==0)
            {
                cout<<"NO"<<endl;
            }
            //
            
            // else if((y&1) && once>0)
            // {
            //     cout<<"YES"<<endl;
            // }
            else if(once==0)
            {
                cout<<"YES"<<endl;
            }
            //

            // else if((y&1)==0 && twos==0)
            // {
            //     cout<<"NO"<<endl;
            // }

            //

            // else if((y&1)==0 && twos>=1)
            // {
            //     cout<<"YES"<<endl;
            // }
            else
            {
                auto it=st.begin();
                auto it1=prev(st.end());//for getting the last element of set
                int ans=max(tot-((*it)*2+1),tot-((n-*it1)*2-1));

                if(1+ans<y)
                {
                    if((once%2)==(y%2))
                    {
                        cout<<"YES"<<endl;
                    }
                    else
                    {
                        cout<<"NO"<<endl;
                    }
                }
                else
                {
                    cout<<"YES"<<endl;
                }
            }
        }
        else
        {
            y--;
            int query;
            // if(a[y]==1)
            // {
            //     query=1;
            //     once--;
            //     st.erase(y);
            // }
            // else
            // {
            //     query=2;
            //     twos--;
            // }
            cin>>query;
            if(a[y]==query)
            {
                continue;
            }
            else
            {
                if(a[y]==1)
                {
                    once--;
                    twos++;
                    st.erase(st.find(y));
                    a[y]=2;//for erasing a particular element from set
                    // cout<<"PRINT: "<<*st.begin()<<" "<<*prev(st.end())<<endl;
                }
                else
                {
                    //vice versa
                    once++;
                    twos--;
                    st.insert(y);
                    a[y]=1;
                }
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