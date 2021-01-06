int main()
{
	for (int i; cin >> i; )
	{
		cout << dec << i << " = " 
			<< hex << "0x" << i << " = "
			<< bitset<8 * sizeof(int)>(i) << '\n';
	}
}