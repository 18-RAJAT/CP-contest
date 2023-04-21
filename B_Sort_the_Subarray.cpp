#include<bits/stdc++.h>
using namespace std;

const int N=200005;
void sol()
{

    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    int array1[n];
    for(int i=0;i<n;++i)
    {
        cin>>array1[i];
    }
    int l=-1,r=-1;
    int mn=INT_MAX;
    int mx=-1;
    for(int i=0;i<n;++i)
    {
        if(array[i]!=array1[i])
        {
            l=i;
            break;
        }
    }
    for(int i=n-1;i>=0;--i)
    {
        if(array[i]!=array1[i])
        {
            r=i;
            break;
        }
    }
    for(int i=l;i<=r;++i)
    {
        mn=min(mn,array1[i]);
        mx=max(mx,array1[i]);
    }
    if(l>0)
    {
        for(int i=l-1;i>=0;--i)
        {
            if(array[i]<=mn)
            {
                l--;
                mn=array[i];
            }
            else
            {
                break;
            }
        }
    }

    if(r<n-1)
    {
        for(int i=r+1;i<n;++i)
        {
            if(array[i]>=mx)
            {
                r++;
                mx=array[i];
            }
            else
            {
                break;
            }
        }
    }
    // int a=l;
    // for(int i=l;i>=1;--i)
    // {
    //     if(array1[i]>=array1[i-1])
    //     {
    //         a--;
    //     }
    // }
    // int b=r;
    // for(int i=r;i<n-1;++i)
    // {
    //     if(array1[i]<=array1[i+1])
    //     {
    //         b++;
    //     }
    // }
    cout<<l+1<<" "<<r+1<<"\n";
}
int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        sol();
    }
    return 0;
}