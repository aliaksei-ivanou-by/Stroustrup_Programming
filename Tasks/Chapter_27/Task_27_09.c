#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_OF_WORD 1000
#define MAX_NUMBER_OF_WORDS 1000
const char* quit = "quit";

void print(char* chars[])
{
	while (*chars)
	{
		printf("%s\n", *chars);
		++chars;
	}
}

int cmp(const void* a, const void* b)
{
	return strcmp(*(const char**)a, *(const char**)b);
}

int main()
{
	printf("Enter words. For exit - enter 'exit'\n");
	char* words[MAX_NUMBER_OF_WORDS] = { 0 };
	char* word = NULL;
	int size = 0;
	while (1)
	{
		word = (char*)malloc(MAX_SIZE_OF_WORD);
		char* temp = word;
		int ch;
		while ((ch = getchar()) != EOF)
		{
			if (ch == '\n')
			{
				*temp = 0;
				break;
			}
			*temp = ch;
			++temp;
		}
		if (!strcmp(word, quit))
		{
			break;
		}
		words[size++] = word;
	}

	printf("\nOriginal list of words:\n");
	print(words);

	qsort(words, size, sizeof(char*), cmp);

	printf("\nSequence after sorting:\n");
	print(words);
}