#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>array(n);
    set<int>st;
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    int ct1=count(array.begin(),array.end(),-1);
    int ct2=count(array.begin(),array.end(),-2);

    for(auto& it:array)
    {
        if(it>0)
        {
            st.insert(it);
        }
    }
    array=vector<int>(st.begin(),st.end());


    n=array.size();
    int ert=max<int>(ct1,ct2)+n;
    // int totalScore=0;
    for(int i=0;i<n;++i)
    {
        int op=n-i-1+ct2;
        ert=max(ert,min(array[i]-1,i+ct1)+min(m-array[i],op)+1);
    }
    cout<<min(ert,m)<<"\n";
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}