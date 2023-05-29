#include<bits/stdc++.h>
using namespace std;
int main()
{
    function<int(vector<int>&,vector<int>&)>freq=[&](vector<int>&fz1,vector<int>&fz2)->auto
    {
        map<int,int>fz;
        int cnt=0;
        for(int i=0;i<fz1.size();++i)
        {
            fz[fz1[i]]++;
        }

        for(int i=0;i<fz2.size();++i)
        {
            for(int j=i+1;j<fz2.size();++j)
            {
                int tmp=fz2[i]*fz2[j];
                if(tmp==fz1[i]+fz1[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    };
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        cout<<freq(a,b)<<endl;
    }
}