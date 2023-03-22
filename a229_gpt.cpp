//first version that not working
// #include <iostream>
// #include <regex>
// #include <string>
// #include <vector>

// using namespace std;

// vector<size_t> find_parentheses_positions(string str) {
//     vector<size_t> positions;
//     // Find all occurrences of "()" that are not at the beginning or end of the string
//     regex pattern("\\([^\\(\\)]*\\)");
//     smatch match;
//     while (regex_search(str, match, pattern)) {
//         size_t pos = match.position();
//         if (pos != 0 && pos != str.length() - 2) {
//             positions.push_back(pos);
//         }
//         str = match.suffix().str();
//     }
//     return positions;
// }

// string replace_last_parentheses(string str, vector<size_t>& replaced_positions) {
//     // Find the position of the last "()" that has not already been replaced
//     size_t last_pos = string::npos;
//     for (int i = replaced_positions.size() - 1; i >= 0; i--) {
//         if (replaced_positions[i] != string::npos) {
//             last_pos = replaced_positions[i];
//             break;
//         }
//     }
//     if (last_pos == string::npos) {
//         // All occurrences of "()" have been replaced
//         // Check if all left parentheses are paired with right parentheses
//         int left_count = 0;
//         for (int i = 0; i < str.length(); i++) {
//             if (str[i] == '(') {
//                 left_count++;
//             } else if (str[i] == ')') {
//                 left_count--;
//                 if (left_count < 0) {
//                     // Unbalanced parentheses, recursion continues
//                     return str;
//                 }
//             }
//         }
//         if (left_count == 0) {
//             // All left parentheses are paired with right parentheses, recursion ends
//             return str;
//         } else {
//             // Unbalanced parentheses, recursion continues
//             return replace_last_parentheses(str, replaced_positions);
//         }
//     } else {
//         // Replace the last "()" with ")("
//         str.replace(last_pos, 2, ")(");
//         // Mark the position as replaced
//         replaced_positions[last_pos] = string::npos;
//         // Recurse to replace the next occurrence of "()"
//         return replace_last_parentheses(str, replaced_positions);
//     }
// }

// int main() {
//     while (true) {
//         // Get input n from user
//         int n;
//         cout << "Enter a positive integer n: ";
//         cin >> n;
//         if (n <= 0) {
//             // End program if n is not positive
//             break;
//         }
//         // Create a string with n left parentheses and n right parentheses
//         string str(n, '(');
//         str.append(n, ')');
//         // Start recursion to replace "()" with ")("
//         vector<size_t> replaced_positions(str.length(), string::npos);
//         str = replace_last_parentheses(str, replaced_positions);
//         // Print the result
//         cout << "Result: " << str << endl;
//     }
//     return 0;
// }

//second version that works but result is upside down from example in zerojudge
#include <iostream>
#include <vector>
using namespace std;

vector<string> generateParentheses(int n) {
    if (n == 0) {
        return {""};
    }
    vector<string> result;
    for (int i = 0; i < n; i++) {
        vector<string> left_parentheses = generateParentheses(i);
        vector<string> right_parentheses = generateParentheses(n - i - 1);
        for (const auto& left : left_parentheses) {
            for (const auto& right : right_parentheses) {
                result.push_back("(" + left + ")" + right);
            }
        }
    }
    return result;
}

int main() {
    int n;
    while(cin>>n){
    	vector<string> result = generateParentheses(n);
	    for (const auto& s : result) {
	        cout << s << endl;
	    }
	}
    return 0;
}
