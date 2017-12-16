def calculate_coins(summ):
    summ *= 100
    coins = [100,50,20,10,5,2,1]
    result = {"100": 0, "50": 0, "20": 0, "10": 0, "5": 0, "2": 0, "1": 0}

    for i in range(len(coins)):
        while summ >= coins[i]:
            summ -= coins[i]
            result[str(coins[i])] += 1
    
    return result

print(calculate_coins(8.94))
print(calculate_coins(4.50))
print(calculate_coins(2.83))
