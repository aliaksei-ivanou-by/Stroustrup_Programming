int do_loop(const vector<int>& v)
{
	int i;
	int sum;
	while (i <= vec.size())
	{
		sum += v[i];
	}
	return sum;
}

char bux[MAX];
char* read_line()
{
	int i = 0;
	char ch;
	while (cin.get(ch) && ch != '\n')
	{
		buf[i++] = ch;
	}
	buf[i + 1] = 0;
	return buf;
}
// gets(buf);
// scanf("%s", buf);