import re

file = open('input.txt', 'r')
lines = file.readlines()

letter_values = {'one':'1', 'two':'2', 'three':'3', 'four':'4', 'five':'5', 'six':'6', 'seven':'7', 'eight':'8', 'nine':'9'}

total = 0

# puzzle 1

pattern = r"\d"
for i in lines:
    res = re.findall(pattern, i)
    total += int(str(res[0] + res[-1]))

print(f'sum of all of the calibration values? : {total}')
total = 0
    
# puzzle 2

pattern = r'\d|one|two|three|four|five|six|seven|eight|nine'
for i in lines:
    res = re.findall(pattern, i)
    first, last = res[0], res[-1]
    if (not first.isnumeric()):
        first = letter_values[res[0]]
    if (not last.isnumeric()):
        last = letter_values[res[-1]]
    total += int(first + last)


print(f'sum of all of the calibration values? : {total}')   