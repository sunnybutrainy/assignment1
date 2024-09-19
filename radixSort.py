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