#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int* a=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int* res=new int[n];
        int flip=0;
        int move=n+1;

        for(int i=0;i<n;++i)
        {
            if(a[i]==n)
            {
                res[flip]=a[i];
                flip++;
                move=i;
            }
            else if(move<i)
            {
                res[flip]=a[i];
                flip++;
            }
        }

        //pos and all
        //same as prev but revert
        if(move==n-1)
        {
            int revert=move-1;
            while(revert>0 and a[0]<a[revert])//=
            {
                res[flip]=a[revert];
                flip++;
                revert--;
            }
            for(int i=0;i<=revert;++i)
            {
                res[flip]=a[i];
                flip++;
            }
            for(int i=0;i<n;++i)
            {
                cout<<res[i]<<" ";
            }
            cout<<"\n";
        }
        else
        {
            res[flip]=a[flip-1];
            flip++;
            int revert1=move-1;

            while(revert1>0 and a[0]<a[revert1])//=
            {
                res[flip]=a[revert1];
                flip++;
                revert1--;
            }
            for(int i=0;i<=revert1;++i)
            {
                res[flip]=a[i];
                flip++;
            }
            for(int i=0;i<n;++i)
            {
                cout<<res[i]<<" ";
            }
            cout<<"\n";
        }
        delete[] a;
        delete[] res;
    }
}