n = input("Enter a number: ")
n = int(n)

start = 1
product = 1

while start <= n:
    product = product * start
    start = start + 1

print(product)
