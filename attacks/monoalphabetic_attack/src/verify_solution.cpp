#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


// Encrypt using substitution key
string encryptText(const string& plaintext, const string& key) {

    string result = plaintext;

    for (int i = 0; i < (int)plaintext.length(); i++) {

        char ch = plaintext[i];

        if (ch >= 'a' && ch <= 'z') {
            result[i] = key[ch - 'a'];
        }
        else if (ch >= 'A' && ch <= 'Z') {
            result[i] = toupper(key[ch - 'A']);
        }
    }

    return result;
}


// Required function: verify_solution()
bool verify_solution(const string& plaintext,
                     const string& ciphertext,
                     const string& key) {

    string generatedCiphertext =
        encryptText(plaintext, key);

    return generatedCiphertext == ciphertext;
}


int main() {

    ifstream plainFile("../testcases/plaintext.txt");
    ifstream cipherFile("../outputs/ciphertext.txt");

    if (!plainFile) {
        cout << "Error: plaintext.txt not found!" << endl;
        return 1;
    }

    if (!cipherFile) {
        cout << "Error: ciphertext.txt not found!" << endl;
        return 1;
    }

    string plaintext;
    string ciphertext;
    string line;

    while (getline(plainFile, line)) {
        plaintext += line;
        plaintext += '\n';
    }

    while (getline(cipherFile, line)) {
        ciphertext += line;
        ciphertext += '\n';
    }

    plainFile.close();
    cipherFile.close();


    // Same substitution key used during encryption
    string key = "qwertyuiopasdfghjklzxcvbnm";


    cout << "===== SOLUTION VERIFICATION =====\n";

    cout << "\nPlaintext loaded: YES";
    cout << "\nCiphertext loaded: YES";

    cout << "\n\nSubstitution Key:\n";
    cout << key << endl;


    bool verified =
        verify_solution(plaintext, ciphertext, key);


    cout << "\nVerification Result: ";

    if (verified) {
        cout << "PASS";
        cout << "\nRecovered key correctly reproduces ciphertext."
             << endl;
    }
    else {
        cout << "FAIL";
        cout << "\nRecovered key does not match ciphertext."
             << endl;
    }

    return 0;
}
