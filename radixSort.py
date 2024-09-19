import time
def countSort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10

    for i in range(0, n):
        idx = (arr[i] // exp) % 10
        count[idx] += 1

    for i in range(1, 10):
        count[i] += count[i-1]
    
    for i in range(n-1, -1, -1):
        idx = (arr[i] // exp) % 10
        output[count[idx] - 1] = arr[i]
        count[idx] -= 1

    for i in range(0, n):
        arr[i] = output[i]

def radixSort(arr, exp=1):
    if exp > max(arr):
        return
    
    countSort(arr, exp)
    radixSort(arr, exp * 10)

def recordResults(runtime):
    with open('py_results.txt', 'a') as file:
        file.write(f"{runtime}\n")

test_arr = []
with open('scramble.txt', 'r') as file:
    for line in file:
        test_arr.append(int(line.strip()))


start_time = time.time()
radixSort(test_arr)
end_time = time.time()
runtime = round(end_time - start_time, 6) # 6 decimal places to match C
recordResults(runtime)