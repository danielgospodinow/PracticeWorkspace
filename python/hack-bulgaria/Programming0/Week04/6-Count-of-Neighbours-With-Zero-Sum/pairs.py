def count_zero_neughbours(numbers):
    result = 0
    for i in range(1, len(numbers)):
        if numbers[i-1] + numbers[i] == 0:
            result += 1
    return result

numbers = [1, 2, -2, 0, 0, 5, -5]

print(count_zero_neughbours(numbers))
