#include <stdlib.h>

void print_char(char* p, int x)
{
	printf("p is \"%s\" and x is %d\n", p, x);
}

int main()
{
	// 1
	printf("Hello, World!\n");

	// 2
	char* word1 = "Hello,";
	char* word2 = "World!";
	int length = strlen(word1) + strlen(word2) + 2;
	char* full = (char*)malloc(sizeof(char) * length);
	strcpy(full, word1);
	strcat(full, " ");
	strcat(full, word2);
	printf("%s\n", full);

	// 3
	print_char("foo", 7);
	print_char("bar", 8);
	print_char("abcd", 10);
}