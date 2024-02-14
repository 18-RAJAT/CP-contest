#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>containers(n);
    for(int i=0;i<n;++i)
    {
        cin>>containers[i];
    }
    function<bool(vector<int>&)>canEqualizeWater=[&](vector<int>&containers)->bool
    {
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=containers[i];
        }
        if(sum%n!=0)
        {
            return false;
        }
        int target=sum/n;
        int excess=0;
        for(int i=0;i<n;++i)
        {
            excess+=containers[i]-target;
            if(excess<0)
            {
                return false;
            }
        }
        return true;
    };
    cout<<(canEqualizeWater(containers)?"YES":"NO")<<endl;
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