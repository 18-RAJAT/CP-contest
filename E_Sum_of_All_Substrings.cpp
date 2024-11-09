// #include <bits/stdc++.h>
// using namespace std;

// typedef string bigint;

// // Function to add two reversed big integers
// bigint add_reversed(const bigint &a, const bigint &b) {
//     bigint sum;
//     int carry = 0;
//     int n = a.size();
//     int m = b.size();
//     int i = 0;
//     while(i < n || i < m || carry){
//         int digit_a = (i < n) ? a[i] - '0' : 0;
//         int digit_b = (i < m) ? b[i] - '0' : 0;
//         int s = digit_a + digit_b + carry;
//         carry = s / 10;
//         sum += (s % 10) + '0';
//         i++;
//     }
//     return sum;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int N;
//     string S;
//     cin >> N >> S;
    
//     bigint sum = "0";
//     bigint prev = "0";
    
//     for(int i = 0; i < N; i++){
//         int digit = S[i] - '0';
        
//         // Multiply prev by 10 (shift left by one digit)
//         bigint new_prev = "0" + prev;
        
//         // Calculate digit * (i + 1)
//         long long tmp = (long long)digit * (i + 1);
//         string tmp_str = to_string(tmp);
//         // Reverse tmp_str for addition
//         reverse(tmp_str.begin(), tmp_str.end());
        
//         // Add tmp_str to new_prev
//         prev = add_reversed(new_prev, tmp_str);
        
//         // Add prev to sum
//         sum = add_reversed(sum, prev);
//     }
    
//     // Reverse the sum to get the correct order
//     string final_sum = sum;
//     reverse(final_sum.begin(), final_sum.end());
    
//     // Remove leading zeros
//     size_t start = final_sum.find_first_not_of('0');
//     if(start == string::npos){
//         cout << '0';
//     }
//     else{
//         cout << final_sum.substr(start);
//     }
//     cout << '\n';
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=1e9+7;
string add(string a,string b,int Mod)
{
    string ans;
    int sum=0,n=a.size(),m=b.size(),i=0;
    while(i<n || i<m || sum)
    {
        int digit_a=(i<n)?a[i]-'0':0;
        int digit_b=(i<m)?b[i]-'0':0;
        int s=digit_a+digit_b+sum;
        sum=s/Mod;
        ans+=to_string(s%Mod);
        i++;
    }
    return ans;
}
void sol()
{
    int n;
    string s;
    cin>>n>>s;
    string sum="0",prev="0";
    for(int i=0;i<n;++i)
    {
        int digit=s[i]-'0';
        string new_prev="0"+prev;
        long long tmp=digit*(i+1);
        string tmp_str=to_string(tmp);
        reverse(tmp_str.begin(),tmp_str.end());
        prev=add(new_prev,tmp_str,Mod);
        sum=add(sum,prev,Mod);
    }
    string ans=sum;
    reverse(ans.begin(),ans.end());
    size_t start=ans.find_first_not_of('0');
    if(start==string::npos)cout<<0;
    else cout<<ans.substr(start);
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}