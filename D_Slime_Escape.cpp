#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>array;
    array.resize(vector<int>::size_type(n+1));
    for(int i=1;i<=n;++i)
    {
        cin>>array[i];
    }
    int i=k-1;
    int j=k+1;
    int sum=array[k];
    while(true)
    {
        int temp1=sum,take1=i,max1=sum,pre_1=i;
        while(take1>=1 && temp1+array[take1]>=0)
        {
            temp1+=array[take1];
            take1--;
            if(temp1>max1)
            {
                max1=temp1;
                pre_1=take1;
            }
        }
        if(take1<=0)
        {
            cout<<"YES"<<endl;
            return;
        }
        int temp2=sum,take2=j,max2=sum,pre_2=j;
        while(take2<=n && temp2+array[take2]>=0)
        {
            temp2+=array[take2];
            take2++;
            if(temp2>max2)
            {
                max2=temp2;
                pre_2=take2;
            }
        }
        if(take2>n)
        {
            cout<<"YES"<<endl;
            return;
        }
        if(max1==sum && max2==sum)
        {
            cout<<"NO"<<endl;
            return;
        }
        (max1>max2)?(i=pre_1,sum=max1):(j=pre_2,sum=max2);
    }
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