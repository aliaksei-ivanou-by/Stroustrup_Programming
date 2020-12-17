template<typename Elem>
struct Link
{
	Link* prev;
	Link* succ;
	Elem val;
};

template<typename Elem>
struct list
{
	Link<Elem>* first;
	Link<Elem>* last;
};