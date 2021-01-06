template<typename T, int N>
class Stack
{
	// ...
};

template<int N>
class Stack
{
public:
	Stack();
	void* get(int n);
	void free();
	int available() const;
private:
	// ...
};

Stack<50 * 1024> my_free_store;
void* pv1 = my_free_store.get(1024);
int* buffer = static_cast<int*>(pv1);
void* pv2 = my_free_store.get(sizeof(Connection));
Connection* pconn = new(pv2) Connection(incoming, outgoing, buffer);