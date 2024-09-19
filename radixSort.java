import java.util.Arrays;

public class radixSort {

    // Counting sort based on the digits represented by exponent
    public static void countSort(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10];

        // Count the occurances of each digit
        for (int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            count[index]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
		
        for (int i = n - 1; i >= 0; i--) {
            int index = (arr[i] / exp) % 10;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }

        // reformatting the output array
        System.arraycopy(output, 0, arr, 0, n);
    }

    // Radix sort function
    public static void radixSort(int[] arr, int exp) {
        // Base case: if exp is greater than 1000, return
        if (exp > 1000) {
            return;
        }

        countSort(arr, exp);

        // Recursively call the sort function for the next digit
        radixSort(arr, exp * 10);
    }

    // returning time in nanoseconds 
    private static long timeCalc(int[] arr) {
        long startTime = System.nanoTime();
        long endTime = System.nanoTime();
        return endTime - startTime; 
    }
    
    //test function
    public static void main(String[] args) {
    	
        int[] numbers = {85, 03, 55, 34, 67, 21, 93, 899};
        radixSort(numbers, 3);
        long duration = timeCalc(numbers);
        System.out.println("Sorted array: " + Arrays.toString(numbers));
        System.out.println("Sorting took: " + duration + " nanoseconds");

    }
}
