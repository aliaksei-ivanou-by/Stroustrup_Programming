#ifndef TASK_19_00_04_STDAFX
#include "Task_19_00_04_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	// 3
	S<int> a_int(1);
	S<char> a_char('a');
	S<double> a_double(1.23);
	S<std::string> a_string("string");
	size_t a_n = 10;
	std::vector<int> a_vector_temp;
	for (size_t i = 0; i < a_n; ++i)
	{
		a_vector_temp.push_back(i);
	}
	S<std::vector<int>> a_vector(a_vector_temp);

	// 4
	//std::cout << "S<int>\t\t" << a_int.val << '\n';
	//std::cout << "S<char>\t\t" << a_char.val << '\n';
	//std::cout << "S<double>\t" << a_double.val << '\n';
	//std::cout << "S<string>\t" << a_string.val << '\n';
	//std::cout << "S<vector>\t";
	//std::cout << "[ ";
	//for (size_t i = 0; i < a_n; ++i)
	//{
	//	std::cout << a_vector.val[i] << ' ';
	//}
	//std::cout << "]\n";

	std::cout << "============================\n";

	// 8
	std::cout << "S<int>\t\t" << a_int.get() << '\n';
	std::cout << "S<char>\t\t" << a_char.get() << '\n';
	std::cout << "S<double>\t" << a_double.get() << '\n';
	std::cout << "S<string>\t" << a_string.get() << '\n';
	std::cout << "S<vector>\t";
	std::cout << "[ ";
	for (size_t i = 0; i < a_n; ++i)
	{
		std::cout << a_vector.get()[i] << ' ';
	}
	std::cout << "]\n";

	std::cout << "============================\n";

	// 9
	a_int.set(11);
	a_char.set('x');
	a_double.set(2.34);
	a_string.set("vector");
	for (size_t i = 0; i < a_n; ++i)
	{
		a_vector_temp[i] = i * i;
	}
	a_vector.set(a_vector_temp);
	std::cout << "S<int>\t\t" << a_int.get() << '\n';
	std::cout << "S<char>\t\t" << a_char.get() << '\n';
	std::cout << "S<double>\t" << a_double.get() << '\n';
	std::cout << "S<string>\t" << a_string.get() << '\n';
	std::cout << "S<vector>\t";
	std::cout << "[ ";
	for (size_t i = 0; i < a_n; ++i)
	{
		std::cout << a_vector.get()[i] << ' ';
	}
	std::cout << "]\n";

	std::cout << "============================\n";

	// 10
	a_int = 55;
	a_char = 'z';
	a_double = 3.14;
	a_string = "array";
	for (size_t i = 0; i < a_n; ++i)
	{
		a_vector_temp[i] = i + 5;
	}
	a_vector = a_vector_temp;
	std::cout << "S<int>\t\t" << a_int.get() << '\n';
	std::cout << "S<char>\t\t" << a_char.get() << '\n';
	std::cout << "S<double>\t" << a_double.get() << '\n';
	std::cout << "S<string>\t" << a_string.get() << '\n';
	std::cout << "S<vector>\t";
	std::cout << "[ ";
	for (size_t i = 0; i < a_n; ++i)
	{
		std::cout << a_vector.get()[i] << ' ';
	}
	std::cout << "]\n";

	std::cout << "============================\n";

	// 11
	const S<int> a_int_const(5);
	std::cout << "a_int_const: " << a_int_const.get() << "\n";

	std::cout << "============================\n";

	// 13
	std::cout << "a_int: ";
	readValue(a_int);
	std::cout << "a_char: ";
	readValue(a_char);
	std::cout << "a_double: ";
	readValue(a_double);
	std::cout << "a_string: ";
	readValue(a_string);
	std::cout << '\n';
	std::cout << "a_int: " << a_int.get() << '\n';
	std::cout << "a_char: " << a_char.get() << '\n';
	std::cout << "a_double: " << a_double.get() << '\n';
	std::cout << "a_string: " << a_string.get() << '\n';

	std::cout << "============================\n";

	// 14
	std::cout << '\n';
	std::cout << "a_vector: ";
	readValue(a_vector);
	std::cout << "a_vector: " << a_vector.get() << "\n";
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