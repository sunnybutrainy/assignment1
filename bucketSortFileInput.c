#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMCOUNT 1000

struct node {
    int data;
    struct node *next;
};

struct node *first[10];
struct node *last[10];

// Reads input from scramble.txt file
void fileInput(int num[]){
    FILE *file;
    int numbers[NUMCOUNT];
    int i = 0;

    file = fopen("scramble.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE); // Exit if file cannot be opened
    }

    // Read each line as an integer and store it in the array
    while (fscanf(file, "%d", &numbers[i]) != EOF) {
        i++;
        if (i >= NUMCOUNT) {
            break;
        }
    }
    fclose(file);

    // Copy the read numbers to the provided array
    for (int j = 0; j < i; j++) {
        num[j] = numbers[j];
    }
}

void writeOutput(double time) {
    FILE *file = fopen("c_results.txt", "a");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE); // Exit if file cannot be opened
    }

    fprintf(file, "%f\n", time);
    fclose(file);
}

// Resets first and last
void InitArr()
{
    for (int i = 0; i < 10; i++)
    {
        first[i] = NULL;
        last[i] = NULL;
    }
}

//finds max digit place
int MaxCipher(int num[])
{
	int maxnum = 0;
	for (int i = 0; i < NUMCOUNT; i++)
	{
		if (maxnum < num[i])
			maxnum = num[i];
	}
	int MaxCipher = 1;
	for (; maxnum / MaxCipher != 0;)
	{
		MaxCipher *= 10;
	}
	return MaxCipher;
}

//Recursive_BucketSort
void Recursive_BucketSort(int num[], int MaxCipher, int cipher, int reCount)
{
	if (MaxCipher == cipher)
		return;
	InitArr();

	struct node *newNode;

	//radix sort
	for (int i = 0; i < NUMCOUNT; i++)
	{
		newNode = malloc(sizeof(struct node));
		newNode->data = num[i];
		newNode->next = NULL;

		int idx;
		if (cipher == 1)
			idx = num[i] % 10;
		else
		{
			idx = (num[i] / cipher) % 10;
		}
		// when there isnt a node
		if (first[idx] == NULL)
		{
			first[idx] = last[idx] = newNode;
		}
		// when theer is a node
		else
		{
			last[idx]->next = newNode;
			last[idx] = newNode;
		}
	}
	printf("\n<Sort_Complete>\n");

	int numIDX = 0;
	//insert into array
	for (int i = 0; i < 10; i++)
	{
		if (first[i] == NULL)
			continue;
		do
		{
			num[numIDX++] = first[i]->data;
			if (first[i]->next == NULL)
			{
				break;
			}
			else
				first[i] = first[i]->next;
		} while (1);
	}

	printf("\n\nreCount %d = ", reCount);
	for (int i = 0; i < NUMCOUNT; i++)
	{
		printf("%7d", num[i]);
	}
	printf("\n\n");

	cipher *= 10;
	Recursive_BucketSort(num, MaxCipher, cipher, ++reCount);
}

int main(void)
{
	
	int num[NUMCOUNT];
    fileInput(num);

    clock_t start_time = clock();
    Recursive_BucketSort(num, MaxCipher(num), 1, 1);
    clock_t end_time = clock(); 

    
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    writeOutput(elapsed_time);

    return 0;
}