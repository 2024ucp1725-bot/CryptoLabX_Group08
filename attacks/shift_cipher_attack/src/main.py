from shift_cipher import encrypt
from brute_force_dictionary import load_dictionary, brute_force
from chi_square_attack import find_key


def main():
    plaintext = "this is a simple secret message"
    actual_key = 5

    ciphertext = encrypt(plaintext, actual_key)

    dictionary = load_dictionary(
        "attacks/shift_cipher_attack/dictionary/english_words.txt"
    )

    dictionary_results = brute_force(ciphertext, dictionary)
    chi_results = find_key(ciphertext)

    dictionary_key = dictionary_results[0][1]
    chi_key = chi_results[0][1]

    dictionary_plaintext = dictionary_results[0][2]
    chi_plaintext = chi_results[0][2]

    print("SHIFT CIPHER CRYPTANALYSIS COMPARISON")
    print("--------------------------------------")
    print("Plaintext       :", plaintext)
    print("Ciphertext      :", ciphertext)
    print("Actual Key      :", actual_key)

    print("\nDictionary Method")
    print("Predicted Key   :", dictionary_key)
    print("Predicted Text  :", dictionary_plaintext)
    print("Correct?        :", dictionary_key == actual_key)

    print("\nChi-Square Method")
    print("Predicted Key   :", chi_key)
    print("Predicted Text  :", chi_plaintext)
    print("Correct?        :", chi_key == actual_key)

    print("\nRESULT TABLE")
    print("Test Case | Actual | Dictionary | Chi-Square")
    print("----------|--------|------------|-----------")
    print(f"Test 1    | {actual_key:^6} | {dictionary_key:^10} | {chi_key:^10}")


if __name__ == "__main__":
    main()
