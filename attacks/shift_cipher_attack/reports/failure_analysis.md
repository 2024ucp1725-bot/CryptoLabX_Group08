# Failure Analysis

## Dictionary Scoring

Dictionary scoring may fail when the decrypted plaintext contains uncommon words,
short words, spelling variations, or text that is too short.

The method depends on the quality and size of the English dictionary.

## Chi-Square Analysis

Chi-Square analysis may fail for very short ciphertexts because there are not
enough letters to accurately represent normal English letter frequencies.

It becomes more reliable when the ciphertext is longer.

## Improvement

The dictionary can be expanded with more English words.

For Chi-Square analysis, longer ciphertexts should be used.

Using both methods together provides better confidence than relying on only one
method.
