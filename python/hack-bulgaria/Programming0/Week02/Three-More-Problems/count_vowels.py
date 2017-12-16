counter = 0
vowels = "aeiouyAEIOUY"

string = input("Enter string: ")

for ch in string:
    if ch in vowels:
        counter += 1

print(counter)
