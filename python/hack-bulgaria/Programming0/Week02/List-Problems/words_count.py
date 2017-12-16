search_word = input("Enter word: ")
n = input("Enter count of words: ")
n = int(n)

input_count = 1
words = []

while input_count <= n:
    word = input("Enter word: ")
    words += [word]
    input_count += 1

word_count = 0

for word in words:
    if search_word.lower() == word.lower():
        word_count += 1

print(search_word + " is found: " + str(word_count) + " times")
