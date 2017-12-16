import random

def generate_random_list(n, start, end):
    result = []
    for i in range(n):
        random_number = random.randint(start, end)
        result += [random_number]
    return result

print(generate_random_list(5,1,3))
