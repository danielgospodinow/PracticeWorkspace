num_of_buildings = input("Enter the number of buildings: ")
num_of_buildings = int(num_of_buildings)

lyulin_buildings_list = []

for i in range(num_of_buildings):
    temp = input("Enter building " + str(i+1) + "'s height: ")
    temp = int(temp)
    lyulin_buildings_list += [temp]   

seen_buildings = 0
max_height = 0

for i in range(len(lyulin_buildings_list)):
    if lyulin_buildings_list[i] > max_height:
        seen_buildings += 1
        max_height = lyulin_buildings_list[i]

print("Ivancho will see " + str(seen_buildings) + " buildings!")
