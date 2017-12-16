# Решение на условието, което аз разбрах

def max_score01(beers, fries):
    max_score_result = 0
    
    for i in range(len(beers)):
        for j in range(len(fries)):
            if beers[i] * fries[j] > max_score_result:
                max_score_result = beers[i]*fries[j]

    return max_score_result

print(max_score01([10, 11], [1, 5]))



# Решение на условието

def max_score02(beers, fries):
  beers = sorted(beers)
  fries = sorted(fries)

  result = 0

  for index in range(0, len(beers)):
    result += beers[index] * fries[index]

  return result

print(max_score02([10, 11], [1, 5]))
