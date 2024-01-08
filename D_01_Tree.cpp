#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int hit=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            hit++;
        }
    }
    if(hit!=1)
    {
        cout<<"NO"<<endl;
        return;
    }
    stack<int>st1,st2;
    st1.push(0);
    st2.push(n-1);
    vector<int>right(n),left(n);
    
    right.assign(n,0);
    left.assign(n,0);
    for(int i=0;i<n;++i)
    {
        while(!st1.empty() && a[i]<a[st1.top()])
        {
            right[st1.top()]=a[i];
            // cout<<st1.top()<<" "<<a[i]<<endl;
            st1.pop();
        }
        st1.push(i);
    }
    for(int i=n-1;~i;--i)
    {
        while(!st2.empty() && a[i]<a[st2.top()])
        {
            left[st2.top()]=a[i];
            // cout<<st2.top()<<" "<<a[i]<<endl;
            st2.pop();
        }
        st2.push(i);
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]!=0)
        {
            if(left[i]!=a[i]-1 && right[i]!=a[i]-1)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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