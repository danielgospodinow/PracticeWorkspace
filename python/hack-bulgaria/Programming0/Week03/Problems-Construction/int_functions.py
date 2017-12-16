def reverse_int(n):
    result = ""
    n = str(n)
    for i in range(len(n)-1, -1, -1):
        result += n[i]
    return int(result)

# print(reverse_int(1254))

def sum_digits(n):
    all_digits = []
    result = 0
    n = str(n)
    for i in range(len(n)):
        all_digits += [n[i]]
    for i in range(len(all_digits)):
        result += int(all_digits[i])
    return result

# print(sum_digits(1234))

def product_digits(n):
    all_digits = []
    result = 1
    n = str(n)
    for i in range(len(n)):
        all_digits += [n[i]]
    for i in range(len(all_digits)):
        result *= int(all_digits[i])
    return result

# print(product_digits(3124))
