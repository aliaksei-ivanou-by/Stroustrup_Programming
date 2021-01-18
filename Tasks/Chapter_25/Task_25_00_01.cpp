#include <iostream>

struct Node
{
	Node* next;
	Node* prev;
	Node(Node* n, Node* p):
		next{ n },
		prev{ p }
	{}
	Node():
		next{ nullptr },
		prev{ nullptr }
	{}
};

struct Device
{
	std::string nameDevice;
	Device(const std::string& n):
		nameDevice{ n }
	{}
};

struct Message
{
	std::string deviceMessage;
};

Message* get_input(Device& device)
{
	Message* message = new Message;
	message->deviceMessage = device.nameDevice;
	return message;
}

int main()
try
{
	Device device("DeviceName");
	Message* get_input(Device&);
	constexpr int count = 10;
	int counter = count;
	int counterMax = counter;
	while (counter)
	{
		std::cout << "Iteration " << counterMax - counter + 1 << '\n';
		Node* n1 = new Node;
		std::cout << "n1 address =\t" << n1 << "\t\tsizeof(n1) =\t" << sizeof(n1) << '\n';
		Node* n2 = new Node;
		std::cout << "n2 address =\t" << n2 << "\t\tsizeof(n2) =\t" << sizeof(n2) << '\n';
		Message* p = get_input(device);
		std::cout << "p address =\t" << p << "\t\tsizeof(p) =\t" << sizeof(p) << '\n';
		std::cout << "\n\n";
		delete p;
		--counter;
	}

	counter = count;
	counterMax = counter;
	while (counter)
	{
		std::cout << "Iteration " << counterMax - counter + 1 << '\n';
		Node* n1 = new Node;
		std::cout << "n1 address =\t" << n1 << "\t\tsizeof(n1) =\t" << sizeof(n1) << '\n';
		Node* n2 = new Node;
		std::cout << "n2 address =\t" << n2 << "\t\tsizeof(n2) =\t" << sizeof(n2) << '\n';
		delete n2;
		Message* p = get_input(device);
		std::cout << "p address =\t" << p << "\t\tsizeof(p) =\t" << sizeof(p) << '\n';
		std::cout << "\n\n";
		--counter;
	}
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