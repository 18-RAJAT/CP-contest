#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    function<int(vector<int>)> find_xor=[&](vector<int>arr)->int
    {
        int result=0;
        for(int i=0;i<arr.size();++i)
        {
            result^=arr[i];
        }
        return result;
    };
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int res=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            for(int k=j;k<n;++k)
            {
                int x=find_xor(vector<int>(a.begin()+i,a.begin()+j+1));
                int y=find_xor(vector<int>(a.begin()+j,a.begin()+k+1));
                int z=find_xor(vector<int>(a.begin()+i,a.begin()+k+1));
                if((x^y)>z)
                {
                    res++;
                }
            }
        }
    }
    cout<<res<<endl;
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