# Test Cases – Shift Cipher Cryptanalysis

| Test Case | Plaintext | Actual Key | Purpose |
|-----------|-----------|------------|---------|
| Test 1 | this is a simple secret message | 5 | Basic test |
| Test 2 | hello world | 3 | Short message |
| Test 3 | cryptography is interesting | 7 | Medium message |

## Expected Result

The brute-force dictionary scoring method should identify the key by selecting the plaintext containing the highest number of dictionary words.

The Chi-Square method should identify the key whose decrypted text has letter frequencies closest to normal English.

## Observation

Dictionary scoring works well when the plaintext contains common dictionary words.

Chi-Square analysis works better on longer English text because frequency analysis becomes more reliable with more letters.
