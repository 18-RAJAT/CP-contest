#include<bits/stdc++.h>
using namespace std;
#define int long long
bool leap(int Y)
{
    return (Y%4==0 && Y%100!=0) || (Y%400==0);
}
int getDayOfYear(int D,int M,int Y)
{
    int DaysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap(Y))DaysInMonth[2]=29;
    int DYear=D;
    for(int i=1;i<M;++i)
    {
        DYear+=DaysInMonth[i];
    }
    return DYear;
}
void sol()
{
    int D,M,Y;
    cin>>D>>M>>Y;
    int DYear=getDayOfYear(D,M,Y);
    if(DYear%2==0)
    {
        cout<<"Nadman"<<endl;
    }
    else
    {
        cout<<"Tahmid"<<endl;
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