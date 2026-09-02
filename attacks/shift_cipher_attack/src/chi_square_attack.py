from collections import Counter
from shift_cipher import decrypt

ENGLISH_FREQ = {
    'a': 8.167, 'b': 1.492, 'c': 2.782, 'd': 4.253,
    'e': 12.702, 'f': 2.228, 'g': 2.015, 'h': 6.094,
    'i': 6.966, 'j': 0.153, 'k': 0.772, 'l': 4.025,
    'm': 2.406, 'n': 6.749, 'o': 7.507, 'p': 1.929,
    'q': 0.095, 'r': 5.987, 's': 6.327, 't': 9.056,
    'u': 2.758, 'v': 0.978, 'w': 2.360, 'x': 0.150,
    'y': 1.974, 'z': 0.074
}


def chi_square_score(text):
    letters = [c.lower() for c in text if c.isalpha()]
    total = len(letters)

    if total == 0:
        return float("inf")

    counts = Counter(letters)
    score = 0

    for letter in "abcdefghijklmnopqrstuvwxyz":
        observed = counts.get(letter, 0)
        expected = ENGLISH_FREQ[letter] * total / 100

        if expected > 0:
            score += (observed - expected) ** 2 / expected

    return score


def find_key(ciphertext):
    results = []

    for key in range(26):
        plaintext = decrypt(ciphertext, key)
        score = chi_square_score(plaintext)
        results.append((score, key, plaintext))

    results.sort()

    return results


if __name__ == "__main__":
    ciphertext = "ym nx f xnruqj xjhwjy rjxxflj"

    results = find_key(ciphertext)

    print("Chi-Square Cryptanalysis")
    print("------------------------")

    for score, key, plaintext in results:
        print(f"Key: {key:2} | Chi-Square: {score:.2f} | {plaintext}")

    best_score, best_key, best_plaintext = results[0]

    print("\nBest Prediction")
    print("Key       :", best_key)
    print("Score     :", round(best_score, 2))
    print("Plaintext :", best_plaintext)
