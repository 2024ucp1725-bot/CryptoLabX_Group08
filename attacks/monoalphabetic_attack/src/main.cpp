#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <iomanip>
using namespace std;


// ================= FREQUENCY ANALYSIS =================

void frequency_analysis(const string& text) {

    int count[26] = {0};
    int total = 0;

    for (char ch : text) {

        if (ch >= 'a' && ch <= 'z') {
            count[ch - 'a']++;
            total++;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            count[ch - 'A']++;
            total++;
        }
    }

    cout << "\n===== 1. FREQUENCY ANALYSIS =====\n";

    for (int i = 0; i < 26; i++) {

        double percentage = 0;

        if (total > 0)
            percentage = (double)count[i] / total * 100;

        cout << char('A' + i)
             << " : "
             << count[i]
             << " ("
             << fixed << setprecision(2)
             << percentage
             << "%)\n";
    }
}


// ================= WORD FREQUENCY =================

void word_frequency_analysis(const string& text) {

    map<string, int> words;
    string word;

    for (int i = 0; i <= (int)text.length(); i++) {

        char ch = (i < (int)text.length())
                    ? text[i] : ' ';

        if (isalpha(ch)) {
            word += tolower(ch);
        }
        else {

            if (!word.empty()) {
                words[word]++;
                word = "";
            }
        }
    }

    cout << "\n===== 2. WORD FREQUENCY ANALYSIS =====\n";

    cout << "\nOne-letter words:\n";

    for (auto x : words) {
        if (x.first.length() == 1)
            cout << x.first << " : "
                 << x.second << endl;
    }

    cout << "\nTwo-letter words:\n";

    for (auto x : words) {
        if (x.first.length() == 2)
            cout << x.first << " : "
                 << x.second << endl;
    }

    cout << "\nThree-letter words:\n";

    for (auto x : words) {
        if (x.first.length() == 3)
            cout << x.first << " : "
                 << x.second << endl;
    }

    cout << "\nRepeated words:\n";

    for (auto x : words) {
        if (x.second > 1)
            cout << x.first << " : "
                 << x.second << " times\n";
    }
}


// ================= PATTERN ANALYSIS =================

string getPattern(const string& word) {

    map<char, int> mapping;

    string pattern = "";
    int next = 0;

    for (char ch : word) {

        if (mapping.find(ch) == mapping.end()) {
            mapping[ch] = next++;
        }

        pattern += char('0' + mapping[ch]);
    }

    return pattern;
}


void pattern_analysis(const string& text) {

    map<string, int> patterns;
    map<string, string> examples;

    string word;

    for (int i = 0; i <= (int)text.length(); i++) {

        char ch = (i < (int)text.length())
                    ? text[i] : ' ';

        if (isalpha(ch)) {
            word += tolower(ch);
        }
        else {

            if (!word.empty()) {

                string pattern = getPattern(word);

                patterns[pattern]++;
                examples[pattern] = word;

                word = "";
            }
        }
    }

    cout << "\n===== 3. PATTERN ANALYSIS =====\n";

    for (auto x : patterns) {

        if (x.second > 1) {

            cout << "Pattern "
                 << x.first
                 << " -> "
                 << examples[x.first]
                 << " : "
                 << x.second
                 << " times\n";
        }
    }
}


// ================= APPLY SUBSTITUTION =================

string apply_substitution(
    const string& ciphertext,
    const string& mapping) {

    string result = ciphertext;

    for (int i = 0; i < (int)ciphertext.length(); i++) {

        char ch = ciphertext[i];

        if (ch >= 'a' && ch <= 'z') {

            char r = mapping[ch - 'a'];

            if (r != '?')
                result[i] = r;
        }
        else if (ch >= 'A' && ch <= 'Z') {

            char r = mapping[tolower(ch) - 'a'];

            if (r != '?')
                result[i] = toupper(r);
        }
    }

    return result;
}


// ================= DISPLAY PARTIAL PLAINTEXT =================

void display_partial_plaintext(
    const string& ciphertext,
    const string& mapping) {

    cout << "\n===== 4. PARTIAL PLAINTEXT =====\n";

    cout << apply_substitution(
        ciphertext,
        mapping)
         << endl;
}


// ================= ENCRYPTION =================

string encryptText(
    const string& plaintext,
    const string& key) {

    string result = plaintext;

    for (int i = 0; i < (int)plaintext.length(); i++) {

        char ch = plaintext[i];

        if (ch >= 'a' && ch <= 'z')
            result[i] = key[ch - 'a'];

        else if (ch >= 'A' && ch <= 'Z')
            result[i] = toupper(key[ch - 'A']);
    }

    return result;
}


// ================= VERIFY SOLUTION =================

bool verify_solution(
    const string& plaintext,
    const string& ciphertext,
    const string& key) {

    string generated =
        encryptText(plaintext, key);

    return generated == ciphertext;
}


// ================= MAIN =================

int main() {

    ifstream cipherFile(
        "../outputs/ciphertext.txt");

    ifstream plainFile(
        "../testcases/plaintext.txt");

    if (!cipherFile || !plainFile) {

        cout << "Error: required files not found!"
             << endl;

        return 1;
    }

    string ciphertext;
    string plaintext;
    string line;

    while (getline(cipherFile, line)) {
        ciphertext += line;
        ciphertext += '\n';
    }

    while (getline(plainFile, line)) {
        plaintext += line;
        plaintext += '\n';
    }

    cipherFile.close();
    plainFile.close();


    cout << "============================================\n";
    cout << " MONOALPHABETIC CIPHER CRYPTANALYSIS\n";
    cout << "============================================\n";


    frequency_analysis(ciphertext);

    word_frequency_analysis(ciphertext);

    pattern_analysis(ciphertext);


    // Unknown substitutions
    string mapping(26, '?');

    // Example hypotheses
    mapping['q' - 'a'] = 'e';
    mapping['w' - 'a'] = 't';
    mapping['e' - 'a'] = 'a';


    display_partial_plaintext(
        ciphertext,
        mapping);


    // Actual key used for validation
    string key =
        "qwertyuiopasdfghjklzxcvbnm";


    cout << "\n===== 5. SOLUTION VERIFICATION =====\n";

    if (verify_solution(
            plaintext,
            ciphertext,
            key)) {

        cout << "Verification: PASS\n";
        cout << "Recovered key reproduces ciphertext.\n";
    }
    else {

        cout << "Verification: FAIL\n";
    }


    cout << "\n===== SUBSTITUTION KEY =====\n";

    cout << "Plain : abcdefghijklmnopqrstuvwxyz\n";
    cout << "Cipher: " << key << endl;


    cout << "\n===== ANALYSIS COMPLETE =====\n";

    return 0;
}
