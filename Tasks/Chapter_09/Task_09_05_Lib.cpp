#include "Task_09_05_Lib.h"

namespace Lib
{
	ISBN::ISBN(int x1, int x2, int x3, char x4)
		:x1(x1), x2(x2), x3(x3), x4(x4)
	{
		if (!is_isbn(x1, x2, x3, x4))
			throw "Invalid ISBN number";
	}

	const ISBN& default_isbn()
	{
		static const ISBN isbn_num(0, 0, 0, '0');
		return isbn_num;
	}

	ISBN::ISBN()
		:x1(default_isbn().x1),
		 x2(default_isbn().x2),
		 x3(default_isbn().x3),
		 x4(default_isbn().x4) {}

	bool is_isbn(int, int, int, char x4)
	{
		return (isalpha(x4) || isdigit(x4));
	}

	Book::Book(ISBN isbn_num, std::string title, std::string author, int cop_date, bool check_out)
		:i_n(isbn_num), t(title), a(author), c_d(cop_date), ch_out(check_out) {}

	const Book& default_book()
	{
		static const Book b(ISBN(), "", "", 0, false);
		return b;
	}

	Book::Book()
		:i_n(default_book().isbn()),
		 t(default_book().title()),
		 a(default_book().author()),
		 c_d(default_book().cop_date()),
		 ch_out(default_book().check_out()) {}

	void Book::check_out_out()
	{
		if (check_out())
			throw "already checked out";
		ch_out=true;
	}

	void Book::check_out_in()
	{
		if (!check_out())
			throw "already checked in";
		ch_out=false;
	}
}
