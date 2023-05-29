#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        // sort(a.begin(),a.end());
        // sort(b.begin(),b.end());

        vector<int>hash1(2*n+1,0),hash2(2*n+1,0);

        int tmp=a[0];

        int curr=1;

        for(int i=1;i<n;++i)
        {
            if(a[i]==a[i-1])
            {
                curr+=1;
            }
            else
            {
                hash1[tmp]=max<int>(hash1[tmp],curr);
                curr=1;
                tmp=a[i];
            }
        }
        hash1[tmp]=max<int>(hash1[tmp],curr);

        tmp=b[0];
        curr=1;
        for(int i=1;i<n;++i)
        {
            if(b[i]==b[i-1])
            {
                curr+=1;
            }
            else
            {
                hash2[tmp]=max<int>(hash2[tmp],curr);
                curr=1;
                tmp=b[i];
            }
        }
        hash2[tmp]=max<int>(hash2[tmp],curr);

        int res=0;
        for(int i=1;i<=2*n;++i)
        {
            int tot=hash1[i]+hash2[i];
            res=max<int>(tot,res);
        }
        cout<<res<<"\n";
    }
    return 0;
}