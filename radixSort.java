import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class radixSort {

    // Counting sort based on the digits represented by exponent
    public static void countSort(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] count = new int[10];

        // Count the occurrences of each digit
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

        // Reformatting the output array
        System.arraycopy(output, 0, arr, 0, n);
    }

    // Radix sort function
    public static void radSort(int[] arr, int exp) {
        if (exp > 1000) {
            return;
        }
        countSort(arr, exp);
        radSort(arr, exp * 10);
    }

    // Time calculation function
    private static long timeCalc(int[] arr) {
        long startTime = System.nanoTime();
        radSort(arr, 1);
        long endTime = System.nanoTime();
        return endTime - startTime; 
    }

    // Read integers from a txt file. Path can be adjusted accordingly.
    
    private static int[] readInput(String filename) {
        String filePath = "./" + filename;
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            StringBuilder sb = new StringBuilder();

            while ((line = reader.readLine()) != null) {
                sb.append(line).append(" ");
            }

            String[] numbersStr = sb.toString().trim().split(" ");
            int[] numbers = new int[numbersStr.length];
            for (int i = 0; i < numbersStr.length; i++) {
                numbers[i] = Integer.parseInt(numbersStr[i]);
            }
            return numbers;
        } catch (IOException e) {
            System.err.println("error in reading numbers: " + e.getMessage());
            return new int[0];
        }
    }

    // writing input as a txt file. Path can be adjusted accordingly.
    public static void writeOutput(String filename, long duration) {
        String filePath = "./" + filename;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath, true))) {
            writer.append(duration + "\n");
            writer.close();

        } catch (IOException e) {
            System.err.println("error writing to the file " + e.getMessage());
        }
    }

    // Main function
    public static void main(String[] args) {
    	
       
        int[] numbers = readInput("scramble.txt");


        // calling the timeCalc process 
        long duration = timeCalc(numbers);

        // Output to a txt file "radJava.txt"
        writeOutput("java_output.txt", duration);
        

        // Can uncomment to show values in compiler
      //  System.out.println("Sorted array: " + Arrays.toString(numbers));
      //  System.out.println("Sorting took: " + duration + " nanoseconds");
    }
}
