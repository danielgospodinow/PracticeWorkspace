def travel_cost(travel):
    line_card = 0
    cost = 0
    for i in range(len(travel)):
        if travel[i] > 23:
            line_card += 1
            cost += 23
        elif travel[i] == 23:
            cost += 23
        else:
            cost += travel[i]
    if line_card > 2:
        return 50
    else:
        return cost

    
travels_01 = [12, 28]
travels_02 = [50]
travels_03 = [30,28,55]
travels_04 = [22]

print(str(travel_cost(travels_04)) + " lv")
