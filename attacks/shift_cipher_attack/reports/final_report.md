# Cryptography Lab – Assignment 4

## Title
Shift Cipher Cryptanalysis using Brute Force, Dictionary Scoring and Chi-Square Analysis

## Group
Group 08

## Aim
To implement a Shift Cipher and analyze its security using brute-force,
dictionary scoring and Chi-Square frequency analysis.

## Objectives

1. Implement Shift Cipher encryption and decryption.
2. Try all possible keys using brute force.
3. Rank decrypted texts using dictionary scoring.
4. Recover the key using Chi-Square analysis.
5. Compare the effectiveness of the two approaches.
6. Analyze situations where the methods fail.

## Theory

A Shift Cipher replaces each alphabetic character with another character
shifted by a fixed key.

For encryption:

C = (P + K) mod 26

For decryption:

P = (C - K) mod 26

There are only 26 possible keys, therefore a Shift Cipher can be attacked
by trying every possible key.

## Method 1 – Brute Force and Dictionary Scoring

The program tests all 26 possible keys. Each decrypted plaintext is scored
according to the number of words that occur in an English dictionary.

The plaintext with the highest score is selected as the best prediction.

## Method 2 – Chi-Square Analysis

Chi-Square analysis compares the frequency of letters in each candidate
plaintext with expected English letter frequencies.

The candidate with the smallest Chi-Square value is selected as the best
prediction.

## Comparison

| Feature | Dictionary Scoring | Chi-Square |
|---|---|---|
| Basic idea | Matches dictionary words | Matches letter frequencies |
| Best for | Text containing common words | Longer English ciphertext |
| Main dependency | Dictionary quality | Amount of ciphertext |
| Weakness | May fail on uncommon words | May fail on short text |
| Key search | 26 keys | 26 keys |

## Test Cases

Three test cases were prepared using different plaintexts and keys.

| Test Case | Plaintext | Key | Purpose |
|---|---|---:|---|
| 1 | this is a simple secret message | 5 | Basic test |
| 2 | hello world | 3 | Short message |
| 3 | cryptography is interesting | 7 | Medium message |

## Failure Analysis

Dictionary scoring may fail when the plaintext contains uncommon words,
words not present in the dictionary, or very short text.

Chi-Square analysis may fail when the ciphertext is very short because the
observed letter frequencies may not accurately represent English.

Longer ciphertexts generally provide better frequency information.

## Results

The Shift Cipher encryption and decryption worked successfully.

The brute-force method examined all 26 possible keys.

Dictionary scoring ranked the candidate plaintexts based on English words.

Chi-Square analysis ranked candidates according to English letter-frequency
similarity.

The experiment demonstrated that combining multiple cryptanalysis techniques
can provide better confidence than relying on a single method.

## Conclusion

The Shift Cipher was successfully implemented and analyzed using brute force,
dictionary scoring and Chi-Square frequency analysis.

The experiment demonstrates that a Shift Cipher has a very small key space and
can therefore be broken efficiently using classical cryptanalysis techniques.
