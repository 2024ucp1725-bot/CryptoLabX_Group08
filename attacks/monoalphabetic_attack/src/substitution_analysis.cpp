#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Required function: apply_substitution()
string apply_substitution(const string& ciphertext,
                          const string& mapping) {

    string result = ciphertext;

    for (int i = 0; i < (int)ciphertext.length(); i++) {

        char ch = ciphertext[i];

        if (ch >= 'a' && ch <= 'z') {

            char replacement = mapping[ch - 'a'];

            if (replacement != '?')
                result[i] = replacement;
        }
        else if (ch >= 'A' && ch <= 'Z') {

            char lower = tolower(ch);
            char replacement = mapping[lower - 'a'];

            if (replacement != '?')
                result[i] = toupper(replacement);
        }
    }

    return result;
}


// Required function: display_partial_plaintext()
void display_partial_plaintext(const string& ciphertext,
                               const string& mapping) {

    string partial =
        apply_substitution(ciphertext, mapping);

    cout << "\n===== PARTIAL PLAINTEXT =====\n";
    cout << partial << endl;
}


// Display current substitution guesses
void display_mapping(const string& mapping) {

    cout << "\n===== CURRENT SUBSTITUTION =====\n";

    for (int i = 0; i < 26; i++) {

        if (mapping[i] != '?') {
            cout << char('a' + i)
                 << " -> "
                 << mapping[i]
                 << endl;
        }
    }
}


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

    // '?' means substitution is not known yet
    string mapping(26, '?');

    cout << "===== SUBSTITUTION ANALYSIS =====\n";

    cout << "\nCiphertext loaded successfully.\n";

    /*
       Example guesses only.

       These can be changed later after
       frequency and pattern analysis.
    */

    cout << "\nTesting sample substitutions...\n";

    // Example:
    // q -> e
    mapping['q' - 'a'] = 'e';

    // w -> t
    mapping['w' - 'a'] = 't';

    // e -> a
    mapping['e' - 'a'] = 'a';

    display_mapping(mapping);

    display_partial_plaintext(ciphertext, mapping);

    cout << "\nUnknown letters are shown unchanged.\n";

    return 0;
}
