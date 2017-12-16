import random

n = input("Enter N sides of dice: ")
n = int(n)

dice_throw = 3
current_throw = 0

dice_sum = 0

while current_throw < dice_throw:
    current_throw += 1
    current_dice = random.randint(1, n)
    print("Throw number " + str(current_throw) + ": " + str(current_dice))
    dice_sum += current_dice

print("The sum is: " + str(dice_sum))
