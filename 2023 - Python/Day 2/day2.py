import re

def parse_line(line):
    parsed = re.split(r'\:|;|,', line)
    game_id = re.findall(r'\d+', parsed[0])
    parsed.pop(0)
    return parsed, int(game_id[0])

def valid_cubes(parsed):
    bag = {'red':12, 'green':13, 'blue':14}
    for i in range(0, len(parsed)):
        value = re.findall(r'\d+|red|green|blue', parsed[i])
        if (int(value[0]) > bag[value[1]]):
            return False
        else:
            continue
    return True

def min_cubes_needed(parsed):
    bag = {'red':0, 'green':0, 'blue':0}
    for i in range(0, len(parsed)):
        value = re.findall(r'\d+|red|green|blue', parsed[i])
        if (int(value[0]) > bag[value[1]]):
            bag[value[1]] = int(value[0])
        else: 
            continue
    return bag

def part1(lines):
    total = 0
    for i in lines:
        parsed, id = parse_line(i)
        if(valid_cubes(parsed)):
            total += id
        else:
            continue
    return total  

def part2(lines):
    total = 0
    for i in lines:
        parsed, id = parse_line(i)
        power = min_cubes_needed(parsed)
        total += power['red']*power['green']*power['blue']
    return total
    

if __name__ == '__main__':
    file = open('Day 2\input.txt', 'r')
    lines = file.readlines()
    print("total number of ids: ", part1(lines))
    print("sum of power of these sets: ", part2(lines))