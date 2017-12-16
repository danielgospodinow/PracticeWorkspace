def divisors(n):
    result = []
    for i in range(1, n):
        if n % i == 0:
            result += [i]
    return result

# print(divisors(6))

def sum_ints(numbers):
    result = 0
    for number in numbers:
        result += number
    return result

# print(sum_ints(divisors(4)))

def is_perfect(n):
    divs = divisors(n)
    sum_of_divisors = sum_ints(divs)
    if n == sum_of_divisors:
        return True
    return False

# print(is_perfect(496))

def to_digits(n):
    digits = []
    n = str(n)
    for x in range(len(n)):
        digits += [int(n[x])]
    return digits

# print(to_digits(12345))

def is_prime(n):
    n = int(n)
    for x in range(2,n-1):
        if n % x == 0:
            return False
    return True

# print(is_prime(6))

def has_prime_digit(n):
    digits = to_digits(n)
    for digit in digits:
        if is_prime(digit) == True:
            return True
    return False

# print(has_prime_digit(44698))

def twin_prime(p):
    if is_prime(p):
        if is_prime(p-2):
            print(str(p-2) + ", " + str(p))
        if is_prime(p+2):
            print(str(p) + ", " + str(p+2))
        if is_prime(p+2) is False and is_prime(p-2) is False:
            print("The number does not have any twin primes!")
    
    else:
        print("The number is not prime!")
        
# twin_prime(23)






    
