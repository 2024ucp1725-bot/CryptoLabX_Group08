#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

// Required function: word_frequency_analysis()
void word_frequency_analysis(const string& text) {

    map<string, int> frequency;
    string word = "";

    // Extract words manually
    for (int i = 0; i <= (int)text.length(); i++) {

        char ch = (i < (int)text.length()) ? text[i] : ' ';

        if (isalpha(ch)) {
            word += tolower(ch);
        }
        else {
            if (!word.empty()) {
                frequency[word]++;
                word = "";
            }
        }
    }

    cout << "\n===== WORD FREQUENCY ANALYSIS =====\n";

    cout << "\n--- One-letter words ---\n";
    for (auto item : frequency) {
        if (item.first.length() == 1) {
            cout << item.first << " : "
                 << item.second << endl;
        }
    }

    cout << "\n--- Two-letter words ---\n";
    for (auto item : frequency) {
        if (item.first.length() == 2) {
            cout << item.first << " : "
                 << item.second << endl;
        }
    }

    cout << "\n--- Three-letter words ---\n";
    for (auto item : frequency) {
        if (item.first.length() == 3) {
            cout << item.first << " : "
                 << item.second << endl;
        }
    }

    cout << "\n--- Repeated words ---\n";
    for (auto item : frequency) {
        if (item.second > 1) {
            cout << item.first << " : "
                 << item.second << " times" << endl;
        }
    }

    cout << "\nTotal unique words: "
         << frequency.size() << endl;
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

    cout << "===== CIPHERTEXT WORD ANALYSIS =====\n";
    cout << ciphertext << endl;

    word_frequency_analysis(ciphertext);

    return 0;
}
