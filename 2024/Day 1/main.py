first_column = []
second_column = []

# Read input 
file = open("2024\Day 1\input", "r")

for line in file:
    first_column.append(int(line.strip().split("  ")[0]))
    second_column.append(int(line.strip().split("  ")[1]))
   
    
# sort the columns
first_column.sort()
second_column.sort()

total_distance = 0

for i in range(len(first_column)):
    total_distance += abs(first_column[i] - second_column[i])
    
print(f"Total distance : {total_distance}")

total_similarity = 0
for i in range(len(first_column)):
    similarity = 0
    value = first_column[i]
    for j in range(len(second_column)):
        if first_column[i] == second_column[j]:
            similarity += 1
    total_similarity += (value * similarity)
    
print(f"Total similarity : {total_similarity}")  