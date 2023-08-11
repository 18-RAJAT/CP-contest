#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k,m;
    cin>>n>>k>>m;
    long double sum(0);
    vector<long long int>array;
    for(int i=0;i<n;++i)
    {
        long long int x;
        cin>>x;
        array.push_back(-x);
    }
    sort(array.begin(),array.end());
    while(array.size()>1 && m>0)
    {
        m--;
        array.pop_back();
    }
    for(auto&it:array)
    {
        it*=-1;
    }
    if(m==0)
    {
        for(auto&it:array)
        {
            sum+=it;
        }
    }
    else
    {
        for(auto&it:array)
        {
            it+=min<long long int>(k,m/array.size());
            
        }
        m%=array.size();
        if(m/array.size()<k)
        {
            for(auto&it:array)
            {
                if(m==0)
                {
                    break;
                }
                it++;
                m--;
            }
            m%=array.size();
        }
        for(auto&it:array)
        {
            sum+=it;
        }
    }
    cout<<fixed<<setprecision(20)<<(long long)1.*sum/array.size();
}