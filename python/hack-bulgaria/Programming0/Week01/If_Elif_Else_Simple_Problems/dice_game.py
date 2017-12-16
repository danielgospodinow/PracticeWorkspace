import random

dice_sides = input("Enter dice sides: ")
dice_sides = int(dice_sides)

player_one_name = input("Enter player 1's name: ")
player_two_name = input("Enter player 2's name: ")

player_one_score = random.randint(1,dice_sides)
player_two_score = random.randint(1,dice_sides)

print(player_one_name + " rolls: " + str(player_one_score))
print(player_two_name + " rolls: " + str(player_two_score))

if player_one_score > player_two_score:
    print(player_one_name + " wins!")
elif player_one_score == player_two_score:
    print("Tie!")
else:
    print(player_two_name + " wins!")
