import re

file = open('Day 1\input.txt', 'r')
lines = file.readlines()

letter_values = {'1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}

total = 0

def replace_numbers(text):
    replacements = {
        'one': 'o1e',
        'two': 't2o',
        'three': 't3ree',
        'four': 'f4ur',
        'five': 'f5ve',
        'six': 's6x',
        'seven': 's7ven',
        'eight': 'e8ght',
        'nine': 'n9ne'
    }
    for word, replacement in replacements.items():
        text = text.replace(word, replacement)
    return text

pattern = r"\d"
# puzzle 1
for i in lines:
    res = re.findall(pattern, i)
    total += int(res[0])*10 + int(res[-1])

print(f'sum of all of the calibration values? : {total}')
total = 0
    
# puzzle 2
for i in lines:
    i = replace_numbers(i)
    res = re.findall(pattern, i)
    first, last = letter_values[res[0]], letter_values[res[-1]]
    total += (first * 10) + last

print(f'sum of all of the calibration values? : {total}')   