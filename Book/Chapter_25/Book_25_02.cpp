template<typename T, int N>
class Pool
{
public:
	Pool();
	T* get();
	void free(T*);
	int available() const;
0private:
	// ...
};

Pool<Small_buffer, 10> ab_pool;
Pool<Status_indicator, 200> indicator_pool;
Small_buffer* p = ab_pool.get();
// ...
ab_pool.free(p);