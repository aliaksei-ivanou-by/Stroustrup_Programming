#ifndef TASK_27_00_04_STDAFX_HPP
#include "Task_27_00_04_stdafx.hpp"
#endif

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