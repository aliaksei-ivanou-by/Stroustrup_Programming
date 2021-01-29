#include <stdlib.h>

char* my_strcpy(char* p, const char* q)
{
	char* temp = p;
	while (*p++ = *q++);
	return temp;
}

int main()
{
	char* ch1 = "abcdef";
	char* ch2 = 0;
	ch2 = (char*)malloc(sizeof(char) * (strlen(ch1) + 1));
	if (!ch2)
	{
		perror("Can't allocate memory");
	}
	ch2 = my_strcpy(ch2, ch1);
	printf("ch1: %s, ch2: %s", ch1, ch2);
}