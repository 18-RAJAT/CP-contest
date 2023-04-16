#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<7*n<<"\n";
        for(int i=0;i<(7*n);)
        {
            cout<<i<<" "<<"0\n";
            cout<<i<<" "<<"1\n";
            cout<<i+1<<" "<<"0\n";
            cout<<i+1<<" "<<"1\n";
            cout<<i+1<<" "<<"2\n";
            cout<<i+2<<" "<<"1\n";
            cout<<i+2<<" "<<"2\n";
            i+=4;
        }
        return;
    }
    int count=10;
    count+=(5*n);
    if(n%2)
    {
        count+=7;
    }
    cout<<count<<"\n";
    cout<<"2 0"<<"\n";
    cout<<"3 0"<<"\n";
    cout<<"4 0"<<"\n";
    cout<<"5 0"<<"\n";
    cout<<"2 1"<<"\n";

    int index=2;
    for(int i=0;i<n/2;i++)
    {
        cout<<"2 "<<" "<<index<<"\n";
        cout<<"1 "<<" "<<index<<"\n";
        cout<<"3 "<<" "<<index<<"\n";
        index++;
        cout<<"2 "<<" "<<index<<"\n";
        cout<<"1 "<<" "<<index<<"\n";
        cout<<"3 "<<" "<<index<<"\n";
        index++;
        cout<<"2 "<<" "<<index<<"\n";
        index++;
    }
    cout<<"2 "<<" "<<index<<"\n";
    cout<<"3 "<<" "<<index<<"\n";
    cout<<"4 "<<" "<<index<<"\n";
    cout<<"5 "<<" "<<index<<"\n";
    for(int i=1;i<(index);i++)
    {
        cout<<"5 "<<" "<<i<<"\n";
    }
    if(n%2)
    {
        cout<<"0 "<<" "<<index<<"\n";
        cout<<"1 "<<" "<<index<<"\n";
        cout<<"0 "<<" "<<index+1<<"\n";
        cout<<"0 "<<" "<<index+2<<"\n";
        cout<<"1 "<<" "<<index+2<<"\n";
        cout<<"2 "<<" "<<index+2<<"\n";
        cout<<"2 "<<" "<<index+1<<"\n";
    }
}

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        sol();
    }
}