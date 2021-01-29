#include <stdlib.h>

size_t my_strlen(const char* ch)
{
	size_t size = 0;
	while (*ch++)
	{
		++size;
	}
	return size;
}

int my_strcmp(const char* leftCh, const char* rightCh)
{
	const char* leftChar = leftCh;
	const char* rightChar = rightCh;
	while (*leftChar && *rightChar && *leftChar == *rightChar)
	{
		++leftChar;
		++rightChar;
	}
	if (*leftChar > *rightChar)
	{
		return 1;
	}
	else
	{
		if (*leftChar < *rightChar)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

char* my_strcpy(char* outCh, const char* inCh)
{
	char* result = outCh;
	while (*outCh++ = *inCh++);
	return result;
}

int main()
{
	char* ch1 = "abc";
	printf("length of \"%s\" is %d\n", ch1, my_strlen(ch1));

	char* ch2 = "xyz";
	int res = strcmp(ch1, ch2);
	if (res == 0)
	{
		printf("'%s' and '%s' are equal\n", ch1, ch2);
	}
	else
	{
		if (res < 0)
		{
			printf("'%s' is before '%s'\n", ch1, ch2);
		}
		else /* res > 0 */
		{
			printf("'%s' is after '%s'\n", ch1, ch2);
		}
	}

	char* ch3 = (char*)malloc(sizeof(char) * my_strlen(ch1));
	my_strcpy(ch3, ch1);
	printf("ch3 is \"%s\"\n", ch3);
}