#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    queue<int>q;
    for(int i=0;i<n;++i)
    {
        q.push(array[i]);
    }
    if(n<k)
    {
        sort(array.begin(),array.end());
        cout<<array[n-1]<<endl;
    }
    else
    {
        int count=0;
        int player=q.front();
        q.pop();
        while(count<k)
        {
            int First=q.front();
            q.pop();
            (First<player)?(q.push(First),count++):(q.push(player),player=First,count=1);
        }
        cout<<player<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}