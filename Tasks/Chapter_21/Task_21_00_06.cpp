#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

int main()
try
{
	std::string fileNameInput = "Task_21_00_06.txt";
	std::string fileNameOutput = "Task_21_00_06_out.txt";

	std::ifstream inputFileStream(fileNameInput);
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open the file " + fileNameInput);
	}
	std::ofstream outputFileStream(fileNameOutput);

	std::istream_iterator<std::string> inputStringStream(inputFileStream);
	std::istream_iterator<std::string> inputStringStreamLimiter;
	std::ostream_iterator<std::string> outputStringStream(outputFileStream, "\n");

	std::vector<std::string> b(inputStringStream, inputStringStreamLimiter);
	std::sort(b.begin(), b.end());
	copy(b.begin(), b.end(), outputStringStream);

	inputFileStream.close();
	outputFileStream.close();
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