# Assignment 5 – Monoalphabetic Substitution Cipher

## Group
Group 08

## Aim
To implement a Monoalphabetic Substitution Cipher and perform its
cryptanalysis using frequency analysis, word frequency analysis and
pattern analysis.

## Objectives

1. Implement Monoalphabetic Substitution Cipher.
2. Generate ciphertext from plaintext.
3. Perform letter-frequency analysis.
4. Perform word-frequency analysis.
5. Analyse repeated-letter patterns.
6. Apply suspected substitutions iteratively.
7. Display partial plaintext during cryptanalysis.
8. Recover and verify the substitution key.

## Programming Language

C++

## Required Functions

The implementation includes:

- `frequency_analysis()`
- `word_frequency_analysis()`
- `pattern_analysis()`
- `apply_substitution()`
- `display_partial_plaintext()`
- `verify_solution()`

## Input

The plaintext is stored in:

`testcases/plaintext.txt`

For Group 08, the prescribed source is page 38 of the
course-specified edition of "Introduction to Modern Cryptography"
by Katz and Lindell.

## Output

The generated ciphertext is stored in:

`outputs/ciphertext.txt`

## Cryptanalysis

The following techniques are used:

### 1. Frequency Analysis
Counts the occurrence of each ciphertext letter and calculates
its percentage frequency.

### 2. Word Frequency Analysis
Identifies one-letter, two-letter and three-letter words and
repeated words.

### 3. Pattern Analysis
Identifies repeated-letter patterns in ciphertext words.

### 4. Iterative Substitution
Candidate mappings are tested and partial plaintext is examined.
Incorrect hypotheses are rejected and useful substitutions are retained.

### 5. Verification
The recovered plaintext is re-encrypted using the recovered key.
The generated ciphertext is compared with the original ciphertext.

## Directory Structure

```text
monoalphabetic_attack/
├── src/
│   ├── monoalphabetic_cipher.cpp
│   ├── frequency_analysis.cpp
│   ├── word_frequency_analysis.cpp
│   ├── pattern_analysis.cpp
│   ├── substitution_analysis.cpp
│   ├── verify_solution.cpp
│   └── main.cpp
│
├── testcases/
│   └── plaintext.txt
│
├── outputs/
│   └── ciphertext.txt
│
├── screenshots/
│
├── reports/
│   └── cryptanalysis_decisions.md
│
└── README.md
