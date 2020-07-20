struct X // struct X
{
	void f(int x) // function f() of struct X
	{
		struct Y // struct Y
		{
			int f() // // function f() of struct Y
			{
				return 1;
			}
			int m; // member m of struct Y
		};
		int m; // variable within f()
		m=x; // set m to argument of f()
		Y m2;  // declare variable of type Y
		return f(m2.f()); // f returns the result of f called with m2.f(), which is 1.
	}
	int m; // member m of struct X
	void g(int m) // function g() of struct X
	{
		if (m) // if argument of g() is not zero
			f(m+2); // X.f() with argument m+2
		else // if argument of g() is zero
		{
			g(m+2); // g() with argument m+2, which is 2
		}
	}
	X() {}// default constructor for struct X
	void m3() // function m3() of struct X
	{
		// ...
	}
	void main() // function main() of struct X
	{
		X a; // declare variable of type X, uses default constructor, int m not initialised
		a.f(2);  // X.f() with argument 2
	}
};
