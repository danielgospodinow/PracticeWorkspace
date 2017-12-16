n = input("Enter a number: ")
n = int(n)

divisors = []

for x in range (1, n-1):
    if n % x == 0:
        divisors += [x]

for divisor in divisors:
    print(divisor)
