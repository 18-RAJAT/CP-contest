#include<bits/stdc++.h>
using namespace std;
#define int long long
bool vowel(char c)
{
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')?true:false;
}
void sol()
{
    string s;
    cin>>s;
    int tmp=0;
    /*
        Approach:
        We need to print the string in such a way that there are no consecutive consonants.
        So, we need to check if the current character is a vowel or not.
        If it is a vowel, then we need to print it.
        If it is a consonant, then we need to check if the previous character is a vowel or not.
        If it is a vowel, then we need to print it.
        If it is a consonant, then we need to print a space and then print the current character.
    */
    for(int i=0;i<s.size();++i)
    {
        if(vowel(s[i]) || i-tmp<=1 || s[i]==s[i-1] && s[i-1]==s[i-2] || vowel(s[i-1]) || vowel(s[i-2]))
        {
            cout<<s[i];
            tmp=0;
        }
        else
        {
            cout<<" ";
            tmp=i;
            cout<<s[i];
        } 
    }
}
signed main()
{
    sol();   
    return 0;
}