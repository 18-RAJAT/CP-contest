// class Solution {
// public:
//     vector<int> beautifulIndices(string s, string a, string b, int k) {
//         int n = s.length();

//     vector<int> a_indices;
//     for (int i = 0; i + a.length() <= n; ++i) {
//         if (s.substr(i, a.length()) == a) {
//             a_indices.push_back(i);
//         }
//     }

//     vector<int> b_indices;
//     for (int j = 0; j + b.length() <= n; ++j) {
//         if (s.substr(j, b.length()) == b) {
//             b_indices.push_back(j);
//         }
//     }

//     set<int> beautiful;
//     for (int i : a_indices) {
//         auto it = lower_bound(b_indices.begin(), b_indices.end(), i);

//         if (it != b_indices.begin() && abs(*prev(it) - i) <= k) {
//             beautiful.insert(i);
//         }
//         if (it != b_indices.end() && abs(*it - i) <= k) {
//             beautiful.insert(i);
//         }
//     }

//     // Return sorted beautiful indices
//     return vector<int>(beautiful.begin(), beautiful.end());
//     }
// };



class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n=s.size();
        vector<int>ai;
        for(int i=0;i+a.size()<=n;++i)
        {
            if(s.substr(i,a.size())==a)
            {
                ai.push_back(i);
            }
        }
        vector<int>bi;
        for(int i=0;i+b.size()<=n;++i)
        {
            if(s.substr(i,b.size())==b)
            {
                bi.push_back(i);
            }
        }
        set<int>ans;
        for(auto& it:ai)
        {
            auto it2=lower_bound(bi.begin(),bi.end(),it);
            if(it2!=bi.begin()&&abs(*prev(it2)-it)<=k)
            {
                ans.insert(it);
            }
            if(it2!=bi.end()&&abs(*it2-it)<=k)
            {
                ans.insert(it);
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};