#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b-a) 
    {
        cout << (b-a)-a%(b-a) << endl;
    } 
    else if(b%a==0) 
    {
        cout << 0 << endl;
    }
    else 
    {
        cout<<b-2*a<<"\n";
    }
    return 0;
}

}
