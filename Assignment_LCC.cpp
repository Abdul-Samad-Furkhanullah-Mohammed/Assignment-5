#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to print DP table
void printTable(const string &s_1, const string &s_2, const vector<vector<int>> &d_p) {
    int n = s_1.length(), var_m = s_2.length();

    // Print column header
    cout << "        ";
    for (char var_c : s_1) cout << var_c << "   ";
    cout << endl;

    // Print DP table
    for (int itr_i = 0; itr_i <= var_m; itr_i++) {
        if (itr_i > 0) cout << s_2[itr_i - 1] << "  ";
        else cout << "   ";

        for (int itr_j = 0; itr_j <= n; itr_j++) {
            cout << setw(2) << d_p[itr_i][itr_j] << "  ";
        }
        cout << endl;
    }
}

// Function for LCS using DP
string longest_Common_Substring(const string &s_1, const string &s_2) {
    int var_n = s_1.length(), var_m = s_2.length();

    vector<vector<int>> d_p(var_m + 1, vector<int>(var_n + 1, 0));

    int max_Len = 0, end_Idx = 0; // track maximum length and its position

    // Filling the DP table
    for (int itr_i = 1; itr_i <= var_m; itr_i++) {
        for (int itr_j = 1; itr_j <= var_n; itr_j++) {
            if (s_2[itr_i - 1] == s_1[itr_j - 1]) {
                d_p[itr_i][itr_j] = d_p[itr_i - 1][itr_j - 1] + 1;

                // If a longer substring is found
                if (d_p[itr_i][itr_j] > max_Len) {
                	max_Len = d_p[itr_i][itr_j];
                	end_Idx = itr_j - 1;
                }
            }
        }
    }

    // DP table for understanding
    printTable(s_1, s_2, d_p);

    // Extract the longest common substring
    return s_1.substr(end_Idx - max_Len + 1, max_Len);
}

int main() {
    string s_1, s_2;

    // Input from user
    cout << "First string: ";
    cin >> s_1;
    cout << "Second string: ";
    cin >> s_2;

    // Call function
    string res_lt = longest_Common_Substring(s_1, s_2);

    // Output the result
    cout << "\nLongest Common Substring: " << res_lt << endl;
    cout << "Length: " << res_lt.length() << endl;

    return 0;
}
