#include "iostream"

namespace Lib
{
	struct ISBN
	{
		int x1;
		int x2;
		int x3;
		char x4;
		ISBN(int x1, int x2, int x3, char x4);
		ISBN();
	};

	bool is_isbn(int, int, int, char x);

	class Book
	{
	private:
		ISBN i_n; // ISBN number
		std::string t; // title
		std::string a; // author
		int c_d; // copyright date
		bool ch_out; // is book checked out?
	public:
		Book(ISBN isbn_num, std::string title, std::string author, int c_d, bool ch_out);
		Book();
		ISBN isbn() const
		{
			return i_n;
		}
		std::string title() const
		{
			return t;
		}
		std::string author() const
		{
			return a;
		}
		int cop_date() const
		{
			return c_d;
		}
		bool check_out() const
		{
			return ch_out;
		}
		void check_out_in();
		void check_out_out();
	};
}
