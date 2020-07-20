#include "iostream"
#include "vector"
#include "Task_09_09_Chrono.h"

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
	bool operator==(const ISBN& isbn_1, const ISBN& isbn_2);

	class Book
	{
	public:
		enum Genre
		{
			fiction, nonfiction, periodical, biography, children
		};
		Book(ISBN isbn_num, std::string title, std::string author, int c_d, Genre gen, bool ch_out);
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
		Genre genre() const
		{
			return g;
		}
		bool check_out() const
		{
			return ch_out;
		}
		void check_out_in();
		void check_out_out();
	private:
		ISBN i_n; // ISBN number
		std::string t; // title
		std::string a; // author
		int c_d; // copyright date
		Genre g; // genre
		bool ch_out; // is book checked out?
	};

	bool operator==(const Book& b1, const Book& b2);
	bool operator!=(const Book& b1, const Book& b2);
	std::ostream& operator<<(std::ostream& os, const Book& b);

	class Patron
	{
	public:
		Patron(int card_number, std::string name, double fees);
		Patron();
		int get_card_number() const
		{
			return card_number;
		}
		std::string get_name() const
		{
			return name;
		}
		double get_fees() const
		{
			return fees;
		}
		void set_fee(double f);
	private:
		int card_number;
		std::string name;
		double fees;
	};

	bool owes_fee(const Patron& p);
	bool operator==(const Patron& patron_1, const Patron& patron_2);
	bool operator!=(const Patron& patron_1, const Patron& patron_2);

	class Library
	{
	public:
		struct Transaction
		{
			Book b;
			Patron p;
			Chrono::Date d;

			Transaction(Book bb,Patron pp,Chrono::Date dd);
			Transaction();
		};
		Library(std::vector<Book> books, std::vector<Patron> patrons, std::vector<Transaction> transactions);
		Library();
		void add_book(const Book& b);
		void add_patron(const Patron& p);
		void check_out(Book& b, const Patron& p, const Chrono::Date& d);
		void set_fee(const Patron& p, double f);
		std::vector<Book> get_books() const
		{
			return books;
		}
		std::vector<Patron> get_patrons() const
		{
			return patrons;
		}
		std::vector<Transaction> get_transactions() const
		{
			return transactions;
		}
		std::vector<Patron> get_debtors() const;
	private:
		std::vector<Book> books;
		std::vector<Patron> patrons;
		std::vector<Transaction> transactions;
	};
}
