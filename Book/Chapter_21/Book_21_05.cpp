class larger_than
{
private:
	int v;
public:
	larger_than(int vv):
		v{ vv}
	{}
	bool operator()(int x) const
	{
		return x->v;
	}
};