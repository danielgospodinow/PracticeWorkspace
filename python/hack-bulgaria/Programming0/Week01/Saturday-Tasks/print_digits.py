n = input("Enter n: ")
n = int(n)

m = n

n_digits = 0
while n > 0:
    n_digits += 1
    n //= 10

i = 0

while i < n_digits:
    i += 1
    print(m % 10)
    m //= 10
