#ifndef TASK_21_00_07_STDAFX
#include "Task_21_00_07_stdafx.h"
#include "Task_21_00_07_Item.h"
#endif

Item::Item() :
	name{},
	iid{},
	value{}
{}

Item::Item(const std::string& n, const int i, const double v) :
	name{ n },
	iid{ i },
	value{ v }
{}

std::istream& operator>>(std::istream& inputStream, Item& i)
{
	std::string name;
	int iid;
	double value;
	inputStream >> name >> iid >> value;
	i = Item(name, iid, value);
	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, const Item& i)
{
	return outputStream << std::setw(15) <<
		i.name << '\t' << i.iid << '\t' << i.value;
}

void get_map(std::map<std::string, int>& myMap)
{
	std::string myString;
	int myInt;
	std::cin >> myString >> myInt;
	if (!std::cin)
	{
		throw std::runtime_error("Cin Error");
	}
	myMap[myString] = myInt;
}

void part11()
{
	// 1
	std::vector<Item> vi;
	const std::string viFileName = "Task_21_00_07_1.txt";
	std::ifstream inputFileStream(viFileName.c_str());
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	Item i;
	int key = 0;
	while (inputFileStream >> i && key < 10)
	{
		vi.insert(vi.end(), i);
		++key;
	}
	std::cout << "Original vector:\n";
	print(vi.begin(), vi.end());

	// 2
	std::cout << "Sort by name:\n";
	std::sort(vi.begin(), vi.end(), [&](const Item& a, const Item& b) { return a.name < b.name; });
	print(vi.begin(), vi.end());

	// 3
	std::cout << "Sort by iid:\n";
	std::sort(vi.begin(), vi.end(), [&](const Item& a, const Item& b) { return a.iid < b.iid; });
	print(vi.begin(), vi.end());

	// 4
	std::cout << "Sort by value:\n";
	std::sort(vi.begin(), vi.end(), [&](const Item& a, const Item& b) { return a.value < b.value; });
	std::reverse(vi.begin(), vi.end());
	print(vi.begin(), vi.end());

	// 5
	vi.insert(vi.end(), Item("Horse shoe", 99, 12.34));
	vi.insert(vi.end(), Item("Canon S400", 9988, 499.95));
	std::cout << "Original vector (+ new 2 items):\n";
	print(vi.begin(), vi.end());

	// 6
	auto viIterator1 = find_if(vi.begin(), vi.end(), [&](const Item& a) { return a.name == "Canon S400"; });
	vi.erase(viIterator1);
	auto viIterator2 = find_if(vi.begin(), vi.end(), [&](const Item& a) { return a.name == "Table"; });
	vi.erase(viIterator2);
	std::cout << "Original vector (- remove 2 items by name):\n";
	print(vi.begin(), vi.end());

	// 7
	auto viIterator3 = find_if(vi.begin(), vi.end(), [&](const Item& a) { return a.iid == 323; });
	vi.erase(viIterator3);
	auto viIterator4 = find_if(vi.begin(), vi.end(), [&](const Item& a) { return a.iid == 1212; });
	vi.erase(viIterator4);
	std::cout << "Original vector (- remove 2 items by iid):\n";
	print(vi.begin(), vi.end());
}

void part12()
{
	// 1
	std::list<Item> li;
	const std::string liFileName = "Task_21_00_07_1.txt";
	std::ifstream inputFileStream(liFileName.c_str());
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	Item i;
	int key = 0;
	while (inputFileStream >> i && key < 10)
	{
		li.insert(li.end(), i);
		++key;
	}
	std::cout << "Original list:\n";
	print(li.begin(), li.end());

	// 2
	std::cout << "Sort by name:\n";
	li.sort([&](const Item& a, const Item& b) { return a.name < b.name; });
	print(li.begin(), li.end());

	// 3
	std::cout << "Sort by iid:\n";
	li.sort([&](const Item& a, const Item& b) { return a.iid < b.iid; });
	print(li.begin(), li.end());

	// 4
	std::cout << "Sort by value:\n";
	li.sort([&](const Item& a, const Item& b) { return a.value < b.value; });
	std::reverse(li.begin(), li.end());
	print(li.begin(), li.end());

	// 5
	li.insert(li.end(), Item("Horse shoe", 99, 12.34));
	li.insert(li.end(), Item("Canon S400", 9988, 499.95));
	std::cout << "Original list (+ new 2 items):\n";
	print(li.begin(), li.end());

	// 6
	auto liIterator1 = find_if(li.begin(), li.end(), [&](const Item& a) { return a.name == "Canon S400"; });
	li.erase(liIterator1);
	auto liIterator2 = find_if(li.begin(), li.end(), [&](const Item& a) { return a.name == "Table"; });
	li.erase(liIterator2);
	std::cout << "Original list (- remove 2 items by name (Canon S400, Table)):\n";
	print(li.begin(), li.end());

	// 7
	auto liIterator3 = find_if(li.begin(), li.end(), [&](const Item& a) { return a.iid == 323; });
	li.erase(liIterator3);
	auto liIterator4 = find_if(li.begin(), li.end(), [&](const Item& a) { return a.iid == 1212; });
	li.erase(liIterator4);
	std::cout << "Original list (- remove 2 items by iid (323, 1212)):\n";
	print(li.begin(), li.end());
}

void part2()
{
	// 1
	std::map<std::string, int> msi;

	// 2
	msi["lecture"] = 21;
	msi["lesson"] = 22;
	msi["student"] = 23;
	msi["school"] = 25;
	msi["teacher"] = 123;
	msi["table"] = 1;
	msi["pen"] = 4;
	msi["laptop"] = 40;
	msi["notebook"] = 32;
	msi["book"] = 12;

	// 3
	std::cout << "Original map:\n";
	print(msi.begin(), msi.end());

	// 4
	auto mapIterator1 = msi.begin();
	while (mapIterator1 != msi.end())
	{
		mapIterator1 = msi.erase(mapIterator1);
	}
	std::cout << "Original map (remove pairs):\n";
	std::cout << "Map size = " << msi.size() << '\n';

	// 5-6
	std::cout << "Enter 10 pairs for map:\n";
	for (int i = 0; i < 10; ++i)
	{
		get_map(msi);
	}

	// 7
	std::cout << "Original map (new):\n";
	print(msi.begin(), msi.end());

	// 8
	int mySum = 0;
	mySum = accumulate(msi.begin(), msi.end(), mySum, [&](int temp, const std::pair<std::string, int>& myMap) { return temp + myMap.second; });
	std::cout << "Sum of all ints in map: " << mySum << '\n';

	// 9
	std::map<int, std::string> mis;
	for (auto p = msi.begin(); p != msi.end(); ++p)
	{
		mis[p->second] = p->first;
	}
	std::cout << "Original map (mis):\n";
	print(mis.begin(), mis.end());
}


void part3()
{
	// 1
	std::vector<double> vd;
	const std::string myFileName = "Task_21_00_07_2.txt";
	std::ifstream inputFileStream(myFileName.c_str());
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	double d;
	while (inputFileStream >> d)
	{
		vd.push_back(d);
	}

	// 2
	std::cout << "Original vector:\n";
	print(vd.begin(), vd.end());

	// 3
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(), vd.end(), vi.begin());

	// 4
	std::cout << "Original vector (double) and vector (int) (pairs):\n";
	for (size_t i = 0; i < vd.size(); ++i)
	{
		std::cout << "{ " << vd[i] << "\t" << vi[i] << " }\n";
	}
	std::cout << '\n';

	// 5
	double mySumVD = 0;
	mySumVD = accumulate(vd.begin(), vd.end(), mySumVD);
	std::cout << "Sum of all doubles in vector: " << mySumVD << '\n';
	std::cout << '\n';

	// 6
	int mySumVI = 0;
	mySumVI = accumulate(vi.begin(), vi.end(), mySumVI);
	std::cout << "Difference of sum of all doubles in vector and sum of all ints in vector: "
		<< mySumVD - mySumVI << '\n';
	std::cout << '\n';

	// 7
	reverse(vd.begin(), vd.end());
	std::cout << "Reverse vector:\n";
	print(vd.begin(), vd.end());

	// 8
	double vdMean = mySumVD / vd.size();
	std::cout << "Mean value of double elements in vector: " << vdMean << '\n';
	std::cout << '\n';

	// 9
	std::vector<double> vd2(count_if(vd.begin(), vd.end(), [&](double& a) { return a < vdMean; }));
	std::copy_if(vd.begin(), vd.end(), vd2.begin(), [&](double& a) { return a < vdMean; });
	std::cout << "New vector (vd2):\n";
	print(vd2.begin(), vd2.end());
	std::cout << '\n';

	// 10
	std::sort(vd2.begin(), vd2.end());
	std::cout << "New vector (vd2) (sort):\n";
	print(vd2.begin(), vd2.end());
	std::cout << '\n';
}
