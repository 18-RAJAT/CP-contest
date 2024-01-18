// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     for (int i = 0; i < t; ++i) {
//         vector<int> output_answer;
//         int intended_number;
//         cin >> intended_number;
//         intended_number -= 1;

//         int increasing_subsequence_number = 1;
//         int index = 0;

//         while (intended_number >= increasing_subsequence_number) {
//             intended_number -= increasing_subsequence_number;
//             increasing_subsequence_number *= 2;
//             output_answer.push_back(index);
//             index += 1;
//         }

//         index = 10000;

//         while (intended_number != 0) {
//             if (intended_number >= (1 << index)) {
//                 output_answer.push_back(index);
//                 intended_number -= 1 << index;
//             }
//             index -= 1;
//         }

//         cout << output_answer.size() << endl;
//         for (int j = 0; j < output_answer.size(); ++j) {
//             cout << output_answer[j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    
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