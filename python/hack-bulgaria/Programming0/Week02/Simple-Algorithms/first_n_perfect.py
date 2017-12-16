n = input("Enter n: ")
n = int(n)

start = 6

while True:

    divisors_sum = 0
    divisor = 1

    while divisor < start:
        if start % divisor == 0:
            divisors_sum += divisor
        divisor += 1

    if divisors_sum == start:
        print(start)
        n = n - 1
    
    if n == 0:
        break

    start += 1
