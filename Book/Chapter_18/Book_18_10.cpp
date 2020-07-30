class vector{
	// ...
	explicit vector(int);
	// ...
};

vector v = 10; // error: int to vector
v = 20; // error: int to vector
vector v0(10); // OK
void f(const vector&);
f(10); // error: int to vector
f(vector(10)); // OK