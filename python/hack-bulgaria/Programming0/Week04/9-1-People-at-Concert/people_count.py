def get_people_count(activity):
    all_people = []
    for act in activity:
        if act not in all_people:
            all_people += [act]
    return len(all_people)

activity = ["Rado", "Ivo", "Maria", "Anneta", "Rado", "Rado", "Anneta", "Ivo", "Maria", "Rado"]

print(get_people_count(activity))
