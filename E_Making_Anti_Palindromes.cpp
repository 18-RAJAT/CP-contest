#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;
    string s;
    cin>>s;

    long long int palindromicCount1[26];
    memset(palindromicCount1,0,sizeof(palindromicCount1));

    long long int palindromicCount2[26];
    memset(palindromicCount2,0,sizeof(palindromicCount2));

    function<bool(char,char)>isSame=[&](char a,char b)->bool
    {
        return a==b;
    };
    function<int(char)>conversion=[&](char a)->int
    {
        return a-'a';
    };

    for(int i=0;i<n/2;++i)
    {
        if(isSame(s[i],s[n-i-1]))
        {
            palindromicCount1[conversion(s[i])]++;
        }
    }

    for(int i=0;i<n;++i)
    {
        palindromicCount2[conversion(s[i])]++;
    }

    long long int sum=0;
    long long int maxCount=0;
    long long int maxCount2=0;
    for(int i=0;i<26;++i)
    {
        sum+=palindromicCount1[i];
        // sum+=palindromicCount2[i];
        maxCount=max(maxCount,palindromicCount1[i]);
        maxCount2=max(maxCount2,palindromicCount2[i]);
    }
    auto check=[&](int n)->int
    {
        return n/2;//+sum;
    };

    check(n);
    //base1
    if(check(n)<maxCount2)
    {
        cout<<-1<<"\n";
        return;
    }
    //base2 odd
    if(n%2!=0)
    {
        cout<<-1<<"\n";
        return;
    }
    else
    {
        long long int notPalindromicCountWithOdd=sum&1;
        long long int notPalindromicCountWithEven=0;
        // for(int i=0;i<26;++i)
        // {
        //     notPalindromicCountWithEven+=(palindromicCount2[i]&1);
        // }
        // cout<<notPalindromicCountWithOdd<<" "<<notPalindromicCountWithEven<<"\n";
        cout<<((sum-maxCount<maxCount)?maxCount:check(sum)+(notPalindromicCountWithOdd))<<"\n";
    }
    /*
        sample cases
        abccba
        anti palindromic count=2
        because a and b are not palindromic

        cabbaccabaac=3
        because a and b are not palindromic and first c and last c are not palindromic
    */
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}
