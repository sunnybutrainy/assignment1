def generateStats():
    py_results = []
    with open('py_results.txt', 'r') as file:
        for line in file:
            py_results.append(float(line.strip()))

    c_results = []
    with open('c_results.txt', 'r') as file:
        for line in file:
            c_results.append(float(line.strip()))

    java_results = []
    with open('java_results.txt', 'r') as file:
        for line in file:
            java_results.append(float(line.strip()))


    java_total = sum(java_results) 
    c_total = sum(c_results)
    py_total = sum(py_results)

    average_java = round(java_total / len(java_results), 6)
    average_c = round(c_total / len(c_results), 6)
    average_py = round(py_total / len(py_results), 6)
    print(f"Java Average: {average_java}")
    print(f"C Average: {average_c}")
    print(f"Python Average: {average_c}")
