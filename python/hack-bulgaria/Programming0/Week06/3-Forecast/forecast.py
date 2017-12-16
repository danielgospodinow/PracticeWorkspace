def forecast(days):
    sunshine_count = 0
    rain_count = 0
    snow_count = 0
    last_day = days[len(days)-1]

    for i in range(len(days)):
        if days[i] == "rain":
            rain_count += 1
        elif days[i] == "sunshine":
            sunshine_count += 1
        elif days[i] == "snow":
            snow_count += 1

    if sunshine_count == snow_count and sunshine_count == rain_count:
        return last_day
    elif sunshine_count > rain_count and sunshine_count > snow_count:
        return "sunshine"
    elif sunshine_count < rain_count and rain_count > snow_count:
        return "rain"
    elif snow_count > rain_count and sunshine_count < snow_count:
        return "snow"
    elif sunshine_count == snow_count:
        return "rain"
    elif sunshine_count == rain_count:
        return "snow"
    elif rain_count == snow_count:
        return "sunshine"

days01 = ["rain", "rain", "sunshine", "sunshine"]
days02 = ["rain", "rain", "snow", "snow", "sunshine", "sunshine"]
days03 = ["sunshine", "rain", "rain", "rain"]
days04 = ["rain", "sunshine", "rain", "sunshine"]
print(forecast(days04))

