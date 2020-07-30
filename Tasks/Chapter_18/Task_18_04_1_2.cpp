#include <iostream>

char* my_strdup(const char* input, int input_max = 128)
{
	int length = 0;
	const char* input_ptr = input;
	while (*input_ptr++)
	{
		++length;
	}
	if (length > input_max)
	{
		length = input_max;
	}
	char* output = new char[length + 1]();
	char* output_ptr = output;
	int key = 0;
	while (*input && key < input_max)
	{
		*output_ptr++ = *input++;
		++key;
	}
	*output_ptr = '\0';
	return output;
}

void print_char(const char* ch, int ch_max = 128)
{
	if (!*ch)
	{
		std::cout << "Null pointer\n";
		return;
	}
	int key = 0;
	while (*ch && key < ch_max)
	{
		std::cout << *ch++;
		key++;
	}
	std::cout << '\n';
	return;
}

int main()
try
{
	char ch1_1[] = { 'a', 'b', 'c', 'd' };
	char* ch2_1 = my_strdup(ch1_1, 4);
	print_char(ch2_1, 4);
	std::cout << '\n';
	delete ch2_1;

	char ch1_2[] = "abcd";
	const char* ch2_2 = my_strdup(ch1_2);
	print_char(ch2_2);
	std::cout << '\n';
	delete ch2_2;
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}