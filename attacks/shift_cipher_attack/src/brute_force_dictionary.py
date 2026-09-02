from shift_cipher import decrypt


def load_dictionary(filename):
    with open(filename, "r") as file:
        return set(word.strip().lower() for word in file)


def score_text(text, dictionary):
    words = text.lower().split()
    return sum(word.strip(".,!?") in dictionary for word in words)


def brute_force(ciphertext, dictionary):
    results = []

    for key in range(26):
        plaintext = decrypt(ciphertext, key)
        score = score_text(plaintext, dictionary)
        results.append((score, key, plaintext))

    results.sort(reverse=True)
    return results


if __name__ == "__main__":
    ciphertext = "ym nx f xnruqj xjhwjy rjxxflj"

    dictionary = load_dictionary(
        "attacks/shift_cipher_attack/dictionary/english_words.txt"
    )

    results = brute_force(ciphertext, dictionary)

    print("Brute Force + Dictionary Scoring")
    print("--------------------------------")

    for score, key, plaintext in results:
        print(f"Key: {key:2} | Score: {score:2} | {plaintext}")

    best_score, best_key, best_plaintext = results[0]

    print("\nBest Prediction")
    print("Key       :", best_key)
    print("Score     :", best_score)
    print("Plaintext :", best_plaintext)
