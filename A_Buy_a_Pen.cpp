#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int r,g,b;
    cin>>r>>g>>b;
    string c;
    cin>>c;
    multiset<int>st={r,g,b};
    if(c=="Blue")st.erase(st.find(b));
    if(c=="Green")st.erase(st.find(g));
    if(c=="Red")st.erase(st.find(r));
    cout<<*st.begin();
}
signed main()
{
    sol();
    return 0;
}



class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for (int a = 0; a < s.size(); a++) {
            if (isdigit(s[a])) {
                s1 += s[a];
            } else if (isalpha(s[a])) {
                s1 += tolower(s[a]);
            }
        }
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if (s1 == s2)
            return true;
        return false;
    }
};