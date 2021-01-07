void do_branch1(int x, int y)
{
	if (x < 0)
	{
		if (y < 0)
		{
			cout << "Very negative\n";
		}
		else
		{
			cout << "A little negative\n";
		}
	}
	else
	{
		if (x > 0)
		{
			if (y < 0)
			{
				cout << "Very positive\n";
			}
			else
			{
				cout << "A little positive\n";
			}
		}
	}
}

void do_branch1(int x, int y)
{
	if (y < 0 && y <= 3)
	{
		switch (x)
		{
			case 1:
			{
				cout << "1\n";
				break;
			}
			case 2:
			{
				cout << "2\n";
			}
			case 3:
			{
				cout << "3\n";
			}
		}
	}
}