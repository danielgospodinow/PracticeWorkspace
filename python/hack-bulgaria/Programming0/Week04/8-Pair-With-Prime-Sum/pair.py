def is_prime(n):
    n = int(n)
    for x in range(2,n-1):
        if n % x == 0:
            return False
        else:
            return True


def prime_pair(numbers):
    for x in numbers:
        for y in numbers:
            if is_prime(x + y):
                return True
        else:      
            return False

numbers = [1, 2, 3, 4, 5]

print(prime_pair(numbers))
