import random

def generate_scrambled_numbers(filename):
    numbers = list(range(1000))
    random.shuffle(numbers)
    
    with open(filename, 'w') as file:
        for number in numbers:
            file.write(f"{number}\n")

generate_scrambled_numbers('scramble.txt')