cout << "Size of int : " << sizeof(int) << '\n';

cout << "MAX int : " << INT_MAX << '\n';

cout << "MIN int : " << numeric_limits<int>::min() << '\n';

if (numeric_limits<char>::is_signed)
{
	cout << "char is signed\n";
}
else
{
	cout << "char is unsigned\n";
}

char ch = numeric_limits<char>::min();
cout << "MIN positive char: " << ch << '\n';
cout << "int for MIN positive char" << int(ch) << '\n';