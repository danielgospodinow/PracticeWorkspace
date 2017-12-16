n_str = input("Enter n: ")

n_digits = []

for x in range(len(n_str)):
    n_digits += [n_str[x]]

digit_num = 1
for digit in n_digits:
    print("Digit " + str(digit_num) +": " +digit)
    digit_num += 1

n_number = ""

for x in range(len(n_digits)):
    n_number += n_digits[x]

n_number = int(n_number)

print("As a number: " + str(n_number))









