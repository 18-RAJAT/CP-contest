#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    scanf("%d",&n);
    auto print=[&](int x)->void
    {
        for(int i=1;i<=x;++i)
        {
            printf("(");
        }
        for(int i=1;i<=x;++i)
        {
            printf(")");
        }
    };
    for(int i=1;i<=n;++i)
    {
        print(i);
        for(int j=1;j<=n-i;++j)
        {
            printf("()");
        }
        printf("\n");
    }
}

int main()
{
    int testCases;
    scanf("%d",&testCases);
    while(testCases--)
    {
        sol();
    }
    return 0;
}