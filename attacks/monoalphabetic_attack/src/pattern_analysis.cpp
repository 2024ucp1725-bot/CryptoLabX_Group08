#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

// Generate pattern of a word
string getPattern(const string& word) {

    string pattern = "";
    map<char, int> mapping;
    int nextNumber = 0;

    for (char ch : word) {

        ch = tolower(ch);

        if (mapping.find(ch) == mapping.end()) {
            mapping[ch] = nextNumber++;
        }

        pattern += char('0' + mapping[ch]);
    }

    return pattern;
}

// Required function: pattern_analysis()
void pattern_analysis(const string& text) {

    map<string, int> patternFrequency;
    map<string, string> patternWords;

    string word = "";

    // Extract words manually
    for (int i = 0; i <= (int)text.length(); i++) {

        char ch = (i < (int)text.length()) ? text[i] : ' ';

        if (isalpha(ch)) {
            word += tolower(ch);
        }
        else {

            if (!word.empty()) {

                string pattern = getPattern(word);

                patternFrequency[pattern]++;
                patternWords[pattern] = word;

                word = "";
            }
        }
    }

    cout << "\n===== PATTERN ANALYSIS =====\n";

    cout << "\nWord -> Pattern\n";
    cout << "-------------------------\n";

    for (auto item : patternWords) {

        cout << item.second
             << " -> "
             << item.first
             << " ("
             << patternFrequency[item.first]
             << " occurrence(s))"
             << endl;
    }

    cout << "\n===== REPEATED PATTERNS =====\n";

    for (auto item : patternFrequency) {

        if (item.second > 1) {

            cout << "Pattern "
                 << item.first
                 << " occurs "
                 << item.second
                 << " times";

            cout << " | Example word: "
                 << patternWords[item.first]
                 << endl;
        }
    }
}


// Main function
int main() {

    ifstream file("../outputs/ciphertext.txt");

    if (!file) {
        cout << "Error: ciphertext.txt not found!" << endl;
        return 1;
    }

    string ciphertext;
    string line;

    while (getline(file, line)) {
        ciphertext += line;
        ciphertext += '\n';
    }

    file.close();

    cout << "===== CIPHERTEXT =====\n";
    cout << ciphertext << endl;

    pattern_analysis(ciphertext);

    return 0;
}
