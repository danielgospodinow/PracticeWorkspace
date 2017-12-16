n = input("Enter n: ")
n = int(n)

summ = 0

while n > 0:
    digit = n % 10
    summ += digit
    n //= 10

print("Sum of digits: " + str(summ))
