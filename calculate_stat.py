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


java_total = sum(java_results) 
c_total = sum(c_results)
py_total = sum(py_results)

if numbers:  
    average_java = java_total / len(java_results)
    average_c = c_total / len(c_results)
    average_py = py_total / len(py_results)
    print(f"The average time for Java is:" +  {average_java} + " The average time for C is:" + {average_c} + "The average time for Python is: " + {average_py})

else:
    print("The list is empty.")
