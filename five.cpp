#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string makeLargestSpecial(string s) {
    vector<string> substrings;
    int count = 0, start = 0;

    for (int i = 0; i < s.size(); ++i) {
        count += (s[i] == '1') ? 1 : -1;
        if (count == 0) {
            substrings.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
            start = i + 1;
        }
    }

    sort(substrings.rbegin(), substrings.rend());
    return accumulate(substrings.begin(), substrings.end(), string(""));
}

int main() {
    string s;
    cout << "Enter a special binary string: ";
    cin >> s;

    cout << "Lexicographically largest string: " << makeLargestSpecial(s) << endl;
    return 0;
}
