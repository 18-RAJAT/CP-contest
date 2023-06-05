#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    std::set<int>st;
    long long int product=1;
    
    function<int(int,int)>GCD=[&](int a,int b)->int
    {
        return b==0?a:GCD(b,a%b);
    };

    for(int i=1;i<n;++i)
    {
        if(GCD(i,n)==1)
        {
            st.insert(i);
            product*=i;
            product%=n;
        }
    }
    // cout<<product-1<<"\n";
    if(product!=1)
    {
        st.erase(st.find(product));
    }
    cout<<st.size()<<"\n";
    for(auto& vals:st)
    {
        cout<<vals<<" ";
    }
}