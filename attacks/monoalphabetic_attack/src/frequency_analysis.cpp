#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Required function: frequency_analysis()
void frequency_analysis(const string& text) {

    int count[26] = {0};
    int totalLetters = 0;

    // Count each alphabet letter
    for (int i = 0; i < (int)text.length(); i++) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            count[ch - 'a']++;
            totalLetters++;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            count[ch - 'A']++;
            totalLetters++;
        }
    }

    cout << "\n===== LETTER FREQUENCY ANALYSIS =====\n";

    cout << left
         << setw(10) << "Letter"
         << setw(10) << "Count"
         << "Percentage" << endl;

    cout << "-----------------------------\n";

    // Display frequency in descending order
    for (int position = 0; position < 26; position++) {

        int maxIndex = -1;
        int maxCount = -1;

        for (int j = 0; j < 26; j++) {

            bool alreadyPrinted = false;

            for (int k = 0; k < position; k++) {
                // We use negative marking below
            }

            if (count[j] > maxCount) {
                maxCount = count[j];
                maxIndex = j;
            }
        }

        if (maxIndex == -1)
            break;

        double percentage = 0.0;

        if (totalLetters > 0) {
            percentage =
                (double)maxCount / totalLetters * 100.0;
        }

        cout << left
             << setw(10) << char('A' + maxIndex)
             << setw(10) << maxCount
             << fixed << setprecision(2)
             << percentage << "%" << endl;

        // Mark this letter as printed
        count[maxIndex] = -1;
    }

    cout << "\nMost frequent ciphertext letters are shown at the top.\n";
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

    frequency_analysis(ciphertext);

    return 0;
}
