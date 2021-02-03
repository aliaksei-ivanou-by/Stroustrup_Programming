#include <iostream>

int main()
try
{
	std::cout << "Memory management\n";
	std::cout << "\tIntrusive - External\n";
	std::cout << "\tNon-intrusive - Internal through allocator\n";

	std::cout << "Insertion/Erasure time\n";
	std::cout << "\tIntrusive - Faster\n";
	std::cout << "\tNon-intrusive - Slower\n";

	std::cout << "Memory locality\n";
	std::cout << "\tIntrusive - Better\n";
	std::cout << "\tNon-intrusive - Worse\n";

	std::cout << "Can hold non-copyable and non-movable objects by value\n";
	std::cout << "\tIntrusive - Yes\n";
	std::cout << "\tNon-intrusive - No\n";

	std::cout << "Exception guarantees\n";
	std::cout << "\tIntrusive - Better\n";
	std::cout << "\tNon-intrusive - Worse\n";

	std::cout << "Computation of iterator from value\n";
	std::cout << "\tIntrusive - Constant\n";
	std::cout << "\tNon-intrusive - Non-constant\n";

	std::cout << "Insertion/erasure predictability\n";
	std::cout << "\tIntrusive - High\n";
	std::cout << "\tNon-intrusive - Low\n";

	std::cout << "Memory use\n";
	std::cout << "\tIntrusive - Minimal\n";
	std::cout << "\tNon-intrusive - More than minimal\n";

	std::cout << "Insert objects by value retaining polymorphic behavior\n";
	std::cout << "\tIntrusive - Yes\n";
	std::cout << "\tNon-intrusive - No (slicing)\n";

	std::cout << "User must modify the definition of the values to insert\n";
	std::cout << "\tIntrusive - Yes\n";
	std::cout << "\tNon-intrusive - No\n";

	std::cout << "Containers are copyable\n";
	std::cout << "\tIntrusive - No\n";
	std::cout << "\tNon-intrusive - Yes\n";

	std::cout << "Inserted object's lifetime managed by\n";
	std::cout << "\tIntrusive - User (more complex)\n";
	std::cout << "\tNon-intrusive - Container(less complex)\n";

	std::cout << "Container invariants can be broken without using the container\n";
	std::cout << "\tIntrusive - Easier\n";
	std::cout << "\tNon-intrusive - Harder (only with containers of pointers)\n";

	std::cout << "Thread-safety analysis\n";
	std::cout << "\tIntrusive - Harder\n";
	std::cout << "\tNon-intrusive - Easier\n";
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
