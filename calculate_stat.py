py_results = []
with open('py_results.txt', 'r') as file:
    for line in file:
        py_results.append(int(line.strip()))

c_results = []
with open('c_results.txt', 'r') as file:
    for line in file:
        c_results.append(int(line.strip()))

java_results = []
with open('java_results.txt', 'r') as file:
    for line in file:
        java_results.append(int(line.strip()))

# Can compare stats here like averages n stuff