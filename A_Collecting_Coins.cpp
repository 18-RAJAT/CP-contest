#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int x=4;
    int a,b,c,n;
    vector<int>array(x);
    
    array.resize(x-1);
    scanf("%d%d%d%d",&a,&b,&c,&n);
    array[0]=a;
    array[1]=b;
    array[2]=c;
    sort(array.begin(),array.end());
    a=array[0];
    b=array[1];
    c=array[2];
    int op=2*c;
    int ans=n-op+a+b;

    cout<<((ans%3==0 and ans>=0)?"YES\n":"NO\n");
}


int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc-->0)
    {
        sol();
    } 
    return 0;
}