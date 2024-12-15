#include <bits/stdc++.h>
using namespace std;

// Function to check if a number string is valid (no leading zeros unless it's "0")
bool is_valid_number(const string& num) {
    if (num.empty()) return false;
    if (num.size() > 1 && num[0] == '0') return false;
    return all_of(num.begin(), num.end(), ::isdigit);
}

// Function to parse and evaluate an expression
bool parse_expression(const string& expr, long long& value) {
    value = 0;
    int n = expr.size();
    int i = 0;
    char current_op = '+'; // Assume first number is added

    while (i < n) {
        // Extract the next number
        string num_str = "";
        // Handle sign for the first number
        if (i == 0 && (expr[i] == '+' || expr[i] == '-')) {
            current_op = expr[i];
            i++;
        }

        // Build the number string
        while (i < n && isdigit(expr[i])) {
            num_str += expr[i];
            i++;
        }

        if (num_str.empty()) {
            // No number found where expected
            return false;
        }

        // Check if the number is valid
        if (!is_valid_number(num_str)) return false;

        // Convert to number
        long long num = stoll(num_str);

        // Apply the operation
        if (current_op == '+') {
            value += num;
        }
        else if (current_op == '-') {
            value -= num;
        }
        else {
            // Invalid operator
            return false;
        }

        // If end of string, break
        if (i >= n) break;

        // Next character should be an operator
        if (expr[i] != '+' && expr[i] != '-') {
            return false;
        }

        // Update the current operator
        current_op = expr[i];
        i++;
    }

    return true;
}

// Function to validate the entire equality and evaluate both sides
bool validate_and_evaluate(const string& eq, long long& lhs_val, long long& rhs_val) {
    // Find the position of '='
    size_t eq_pos = eq.find('=');
    if (eq_pos == string::npos) return false; // No '=' found

    // Ensure there is only one '='
    if (eq.find('=', eq_pos + 1) != string::npos) return false;

    string lhs = eq.substr(0, eq_pos);
    string rhs = eq.substr(eq_pos + 1);

    // Both sides must be non-empty
    if (lhs.empty() || rhs.empty()) return false;

    // Parse and evaluate both expressions
    bool lhs_ok = parse_expression(lhs, lhs_val);
    bool rhs_ok = parse_expression(rhs, rhs_val);

    return lhs_ok && rhs_ok;
}

int main(){
    string s;
    getline(cin, s);

    // First, check if the original equality is correct
    long long lhs_val, rhs_val;
    if (validate_and_evaluate(s, lhs_val, rhs_val)) {
        if (lhs_val == rhs_val) {
            cout << "Correct";
            return 0;
        }
    }

    // Attempt to move each digit to every possible position
    int n = s.size();
    for(int i=0; i<n; i++) {
        if(!isdigit(s[i])) continue;
        char c = s[i];
        string s_removed = s.substr(0, i) + s.substr(i+1);
        int new_len = s_removed.size();
        for(int j=0; j<=new_len; j++) {
            // Skip inserting back to the original position
            if(j == i) continue;
            string temp = s_removed.substr(0, j) + string(1, c) + s_removed.substr(j);
            // Check if there's exactly one '='
            size_t eq_count = count(temp.begin(), temp.end(), '=');
            if(eq_count != 1) continue;
            // Validate and evaluate the new equality
            long long new_lhs, new_rhs;
            if(validate_and_evaluate(temp, new_lhs, new_rhs)) {
                if(new_lhs == new_rhs){
                    cout << temp;
                    return 0;
                }
            }
        }
    }

    // If no valid equality found
    cout << "Impossible";
}
