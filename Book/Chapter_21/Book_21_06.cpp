class F
{
private:
	S s;
public:
	F(const S& ss):
		s{ ss }
	{}
	T operator()(const S& ss) const
	{
		// ...
	}
	const S& state() const
	{
		return s;
	}
	void reset(const S& ss)
	{
		s = ss;
	}
};