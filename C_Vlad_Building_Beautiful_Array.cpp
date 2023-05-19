#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        long long int n;
        cin>>n;
        // long long int odd,even;
        vector<long long int>odd,even;
        // odd=even=0;

        // long long int vis=0;

        vector<long long int>a(n);
        for(int i=0;i<n;++i)
        {
            //possible
            cin>>a[i];
            // if(a[i]==1)
            // {
            //     vis=1;
            // }
            // if(a[i]%2==0)
            // {
            //     even++;
            // }
            // else
            // // if(a[i]%2==1)
            // {
                // odd++;
                // mn=min<long long int>(mn,a[i]);
            // }
            if(a[i]%2)
            {
                odd.push_back(a[i]);
            }
            else
            {
                even.push_back(a[i]);
            }
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());


        // if(vis or even or odd)
        // {
        //     cout<<"YES"<<"\n";
        //     // return 0;
        //     continue;
        // }
        // cout<<"NO"<<"\n";
        // if(odd.size()==0 or even.size()==0)
        // {
        //     cout<<"NO"<<"\n";
        // }
        // else
        // {
        //     if(abs(odd[0]-even[0])>0)
        //     {
        //         cout<<"YES"<<"\n";
        //     }
        // }

        int ok=(odd.empty() or even.empty() or (even[0]-odd[0]>0))?false:true;

        cout<<((not ok)?"YES":"NO")<<"\n";
    }
}