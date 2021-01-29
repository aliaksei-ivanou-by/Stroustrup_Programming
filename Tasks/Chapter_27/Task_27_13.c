#include <stdlib.h>
#include <stdio.h>

char* get_chars()
{
	int size = 0;
	int i = 0;
	int letter = 0;
	char* ch = (char*)malloc(sizeof(char) * size);
	while ((letter = getchar()) != EOF && letter != '\n')
	{
		if (i >= size)
		{
			++size;
			char* temp = (char*)realloc(ch, sizeof(char) * size);
			ch = temp;
		}
		ch[i] = letter;
		++i;
	}
	ch[i] = 0;
	return ch;
}

int main()
{
	char* exit = "exit";
	printf("Enter '%s' for exit\n", exit);
	while (1)
	{
		char* ch = get_chars();
		if (!strcmp(ch, exit))
		{
			break;
		}
		printf("%s\n\n", ch);
	}
}