def count_vowels_consonants(word):
    result = {}
    result["vowels"] = 0
    result["consonants"] = 0
    vowels = "aeiouyAEIOUY"
    consonants = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ"
    for i in range(len(word)):
        for v in range(len(vowels)):
            if word[i] == vowels[v]:
                result["vowels"] += 1
        for c in range(len(consonants)):
            if word[i] == consonants[c]:
                result["consonants"] += 1
    return result

print(count_vowels_consonants("aaaAcccD"))
