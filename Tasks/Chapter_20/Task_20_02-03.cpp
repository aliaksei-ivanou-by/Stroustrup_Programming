#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

double* high(double* first, double* last)
{
	double h = DBL_MIN;
	double* high = nullptr;
	for (double* p = first; p != last; ++p)
	{
		if (h < *p)
		{
			high = p;
			h = *p;
		}
	}
	return high;
}

double* high(double* myArray, size_t size)
{
	if (size == 0)
	{
		return nullptr;
	}
	double* high = &myArray[0];
	for (size_t i = 0; i < size; ++i)
	{
		if (myArray[i] > *high)
		{
			high = &myArray[i];
		}
	}
	return high;
}

double* high(std::vector<double>& myVector)
{
	if (myVector.size() == 0)
	{
		return nullptr;
	}
	double* high = &myVector[0];
	for (size_t i = 0; i < myVector.size(); ++i)
	{
		if (myVector[i] > *high)
		{
			high = &myVector[i];
		}
	}
	return high;
}

std::unique_ptr<double[]> get_from_jack(int* count)
{
	std::string fileName = "Task_20_02-03_jack.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	int size = 1;
	std::unique_ptr<double[]> oldVector = std::make_unique<double[]>(size);
	int i = 0;
	while (fileStream >> oldVector[i])
	{
		*count += 1;
		if (i + 1 == size)
		{
			std::unique_ptr<double[]> temp = std::make_unique<double[]>(size + 1);
			std::copy(oldVector.get(), oldVector.get() + size, temp.get());
			size += 1;
			oldVector = std::move(temp);
		}
		++i;
	}
	return oldVector;
}

std::unique_ptr<std::vector<double>> get_from_jill()
{
	std::string fileName = "Task_20_02-03_jill.txt";
	std::ifstream fileStream(fileName.c_str());
	if (!fileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	std::unique_ptr<std::vector<double>> newVector = std::make_unique<std::vector<double>>();
	double number;
	while (fileStream >> number)
	{
		(*newVector).push_back(number);
	}
	return newVector;
}

int main()
try
{
	// Jack Data
	int jack_count = 0;
	std::unique_ptr<double[]> jack_data = get_from_jack(&jack_count);

	double* jack_high_ptr = high(&jack_data[0], &jack_data[0] + jack_count);

	double* jack_high_arr = high(jack_data.get(), jack_count);

	std::vector<double> jack_vec;
	for (int i = 0; i < jack_count; ++i)
	{
		jack_vec.push_back(jack_data[i]);
	}
	double* jack_high_vec = high(jack_vec);

	// Jill Data
	std::unique_ptr<std::vector<double>> jill_data = get_from_jill();

	std::vector<double>& jill_vec = *jill_data;
	double* jill_high_ptr = high(&jill_vec[0], &jill_vec[0] + jill_vec.size());

	std::unique_ptr<double[]> jill_arr = std::make_unique<double[]>((*jill_data).size());
	for (int i = 0; i < (*jill_data).size(); ++i)
	{
		jill_arr[i] = (*jill_data)[i];
	}
	double* jill_high_arr = high(jill_arr.get(), (*jill_data).size());

	double* jill_high_vec = high(*jill_data);

	// Print
	std::cout << "Max Jill: " << *jill_high_ptr << "; Max Jack: " << *jack_high_ptr << '\n';
	std::cout << "Max Jill: " << *jill_high_arr << "; Max Jack: " << *jack_high_arr << '\n';
	std::cout << "Max Jill: " << *jill_high_vec << "; Max Jack: " << *jack_high_vec << '\n';
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