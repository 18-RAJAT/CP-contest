#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        long long int n;
        cin>>n;
        vector<long long int>*arr=new vector<long long int>(3);
        long long int count=0;

        int S=sqrt(n);
        for(int i=2;i<2+S;++i)
        {
            if(n%i==0)
            {
                (*arr)[count]=i;
                count++;
            }
            if(count==3)
            {
                break;
            }
        }
        cout<<(count==3?"YES\n"+to_string((*arr)[0])+" "+to_string((*arr)[1])+" "+to_string(n/((*arr)[0]*(*arr)[1]))+"\n":"NO\n");
        
        delete arr;
    }
    return 0;
}