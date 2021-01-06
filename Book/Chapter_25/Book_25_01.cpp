Message* get_input(Device&);

while (/* ... */)
{
	Message* p = get_input(dev);
	// ...
	Node* n1 = new Node(arg1, arg2);
	// ...
	delete p;
	Node* n2 = new Node(arg3, arg4);
	// ...
}

while(/* ... */)
{
	Node* n1 = new Node(arg1, arg2);
	Node* n2 = new Node(arg3, arg4);
	Message* p = get_input(dev);
	// ...
	delete p;
	// ...
}