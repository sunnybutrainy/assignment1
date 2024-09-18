#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMCOUNT 10

struct node
{
	int data;
	struct node *link;
};

struct node *first[10];
struct node *last[10];

//randomly creates from 0 to 999
void RandomInt(int num[])
{
	srand(time(NULL));
	for (int i = 0; i < NUMCOUNT; i++)
	{
		int temp = rand() % 1000; // Limit to numbers between 0 and 999

		for (int j = 0; j < i; j++)
		{
			if (num[j] == temp)
			{
				i--;
				continue;
			}
		}
		num[i] = temp;
	}
	printf("Arr = ");
	for (int i = 0; i < NUMCOUNT; i++)
	{
		printf("%7d", num[i]);
	}
}

//resets first and last
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
		newNode->link = NULL;

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
			last[idx]->link = newNode;
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
			if (first[i]->link == NULL)
			{
				break;
			}
			else
				first[i] = first[i]->link;
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
	RandomInt(num);

	Recursive_BucketSort(num, MaxCipher(num), 1, 1);

	printf("\n\nSortArr = ");
	for (int i = 0; i < NUMCOUNT; i++)
	{
		printf("%7d", num[i]);
	}
	printf("\n\n");

	system("pause");
}