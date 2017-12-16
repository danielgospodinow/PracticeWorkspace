def status_count(students):
    result = {"finalized": [], "not_finalized": []}
    
    for i in range(len(students)):
        if students[i]["status"] == "finalized":
            result["finalized"] += [students[i]["name"]]
        else:
            result["not_finalized"] += [students[i]["name"]]

    return result


students = [{
              "name": "RadoRado",
              "status": "not_finalized"
            }, {
              "name": "Ivo",
              "status": "finalized"
            }, {
              "name": "Genadi",
              "status": "finalized"
            }]

print(status_count(students))
