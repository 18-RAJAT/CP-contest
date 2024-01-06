#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    n*=2;
    multiset<int,greater<int>>st;
    st.clear();
    vector<int>arr(n,0);
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        maxi=max<int>(maxi,arr[i]);
        st.insert(arr[i]);
    }
    if(n==2)
    {
       cout<<"YES"<<endl;
       int sum=(arr[0]+arr[1]);
       cout<<sum<<endl;
       cout<<arr[0]<<" "<<arr[1]<<endl;
       return;
    }
    vector<pair<int,int>>ans;
    bool flag1=true;
    int sum=maxi;
    st.erase(st.find(maxi));
    bool flag2=false;
    pair<int,int>p1;
    multiset<int,greater<int>>st1=st,st2=st;
    // st1.clear();
    // st2.clear();
    // st1.erase(st1.find(arr[0]));
    // st2.erase(st2.find(arr[1]));
    for(auto& it:st2)
    {
        st1=st;
        st1.erase(st1.find(it));
        p1.first=maxi;
        p1.second=it;
        flag2=1;
        flag1=1;
        ans.clear();
        sum=maxi;
        while(!st1.empty())
        {
            int x=sum;
            int y=*st1.begin();
            int diff=x-y;
            st1.erase(st1.find(y));
            // for(auto& it1:ans)
            // {
            //     if(it1.first==y || it1.second==y)
            //     {
            //         flag1=0;
            //         break;
            //     }
            // }
            if(st1.count(diff)>0)
            {
                sum=y;
                st1.erase(st1.find(diff));
                ans.emplace_back(y,diff);
            }
            else
            {
                flag1=0;
                break;
            }
            // for(int i=0;i<ans.size();++i)
            // {
            //     st1.erase(st1.find(ans[i].first));
            //     st1.erase(st1.find(ans[i].second));
            // }
        }
        if(flag1)
        {
            break;
        }
    }
    if(flag1)
    {
        cout<<"YES"<<endl;
        if(flag2)
        {
            cout<<(p1.first+p1.second)<<endl;
            cout<<p1.first<<" "<<p1.second<<endl;
        }
        else
        {
            int value=*st.begin();
            cout<<(value+arr[0])<<endl;
            cout<<value<<" "<<arr[0]<<endl;
        }
        for(auto& x:ans)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
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