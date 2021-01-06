bitset<4> flags;
bitset<128> dword_bits;
bitset<12345> lots;

bitset<4> flags = 0xb;
bitset<128> dword_bits(string("1010101010101010"));
bitset<12345> lots;

string s;
cin >> s;
bitset<12345> my_bits(s); // can be error std::invalid_argument

b1 = b2&b3;
b1 = b2|b3;
b1 = b2^b3;
b1 = ~b2;
b1 = b2 << 2;
b1 = b2 >> 3;

cin >> b;
cout << bitset<8>('c');

int main()
{
	constexpr int max = 10;
	bitset<max> b;
	for (bitset<max> b; cin >> b; )
	{
		cout << b << '\n';
		for (int i = 0; i < max; ++i)
		{
			cout << b[i];
		}
		cout << '\n';
	}
}