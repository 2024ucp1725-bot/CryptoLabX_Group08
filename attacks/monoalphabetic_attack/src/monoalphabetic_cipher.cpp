#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Encrypt plaintext using monoalphabetic substitution key
string encryptText(const string& text, const string& key) {
    string result = text;

    for (int i = 0; i < (int)text.length(); i++) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            result[i] = key[ch - 'a'];
        }
        else if (ch >= 'A' && ch <= 'Z') {
            result[i] = toupper(key[ch - 'A']);
        }
    }

    return result;
}

// Decrypt ciphertext using substitution key
string decryptText(const string& text, const string& key) {
    string result = text;

    for (int i = 0; i < (int)text.length(); i++) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            for (int j = 0; j < 26; j++) {
                if (key[j] == ch) {
                    result[i] = 'a' + j;
                    break;
                }
            }
        }
        else if (ch >= 'A' && ch <= 'Z') {
            char lower = tolower(ch);

            for (int j = 0; j < 26; j++) {
                if (key[j] == lower) {
                    result[i] = toupper('a' + j);
                    break;
                }
            }
        }
    }

    return result;
}

int main() {

    // Plain alphabet
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // Fixed substitution key
    // Plain:  abcdefghijklmnopqrstuvwxyz
    // Cipher: qwertyuiopasdfghjklzxcvbnm
    string key = "qwertyuiopasdfghjklzxcvbnm";

    ifstream file("../testcases/plaintext.txt");

    if (!file) {
        cout << "Error: plaintext.txt not found!" << endl;
        return 1;
    }

    string plaintext;
    string line;

    while (getline(file, line)) {
        plaintext += line;
        plaintext += '\n';
    }

    file.close();

    string ciphertext = encryptText(plaintext, key);
    string decrypted = decryptText(ciphertext, key);

    cout << "===== MONOALPHABETIC SUBSTITUTION CIPHER =====\n\n";

    cout << "Plain Alphabet : " << alphabet << endl;
    cout << "Cipher Key     : " << key << endl;

    cout << "\n----- PLAINTEXT -----\n";
    cout << plaintext << endl;

    cout << "\n----- CIPHERTEXT -----\n";
    cout << ciphertext << endl;

    cout << "\n----- DECRYPTED TEXT -----\n";
    cout << decrypted << endl;

    // Save ciphertext
    ofstream output("../outputs/ciphertext.txt");

    if (output) {
        output << ciphertext;
        output.close();
        cout << "\nCiphertext saved successfully.\n";
    }

    return 0;
}
