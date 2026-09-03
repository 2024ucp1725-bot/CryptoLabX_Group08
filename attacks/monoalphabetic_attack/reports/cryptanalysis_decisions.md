# Cryptanalysis Decision Table

## Monoalphabetic Substitution Cipher – Group 08

| Step | Observation | Possible Substitution | Substitution Tested | Result | Decision |
|------|-------------|-----------------------|----------------------|--------|----------|
| 1 | Most frequent ciphertext letter observed | Frequent letter → E | Tested E substitution | Partial plaintext improved | Retained |
| 2 | One-letter word observed | One-letter word → A/I | Tested A/I possibilities | One possibility produced meaningful text | Retained useful hypothesis |
| 3 | Common two-letter word observed | Possible THE/OF/TO/IN/IS | Tested candidate mappings | Some combinations produced meaningful fragments | Continued |
| 4 | Repeated ciphertext word observed | Same plaintext word should repeat | Tested same substitution pattern | Repeated pattern was preserved | Retained |
| 5 | Repeated-letter pattern observed | Candidate word with same repeated letters | Tested matching pattern | Pattern matched a possible English word | Retained |
| 6 | Partial plaintext examined | Several mappings combined | Applied substitutions together | Meaningful plaintext fragments appeared | Continued |
| 7 | Incorrect hypothesis produced unreadable text | Reverse suspected mapping | Tested alternative mapping | Partial plaintext became worse/better | Rejected incorrect mapping |
| 8 | Complete candidate plaintext obtained | Full substitution key | Applied complete key | Meaningful plaintext obtained | Accepted |
| 9 | Re-encryption performed | Recovered key | Re-encrypted recovered plaintext | Ciphertext matched original ciphertext | Final key verified |

## Cryptanalytic Approach

1. Letter frequencies were counted first.
2. Ciphertext letters were arranged according to frequency.
3. One-letter and common short words were examined.
4. Repeated words and repeated-letter patterns were identified.
5. Candidate substitutions were tested iteratively.
6. Incorrect substitutions were rejected when they produced meaningless text.
7. Partial plaintext was examined after every useful substitution.
8. The final substitution key was verified by re-encrypting the recovered plaintext.

## Important Observation

Frequency analysis gives useful initial guesses, but frequency alone may not be sufficient.
Word frequency and repeated-letter patterns provide additional information for
recovering the substitution key.
