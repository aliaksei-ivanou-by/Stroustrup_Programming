#include "Task_09_09_Lib.h"

namespace Lib
{
	ISBN::ISBN(int x1, int x2, int x3, char x4)
		:x1(x1), x2(x2), x3(x3), x4(x4)
	{
		if (!is_isbn(x1, x2, x3, x4))
			std::cout<<"Invalid ISBN number";
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

	bool operator==(const ISBN& isbn1, const ISBN& isbn2)
		{
		return (isbn1.x1==isbn2.x1 && isbn1.x2==isbn2.x2 && isbn1.x3==isbn2.x3 && isbn1.x4==isbn2.x4);
		}

	Book::Book(ISBN isbn_num, std::string title, std::string author, int cop_date, Genre genre, bool check_out)
        :i_n(isbn_num), t(title), a(author), c_d(cop_date), g(genre), ch_out(check_out) {}

	const Book& default_book()
	{
		static const Book b(ISBN(), "", "", 0, Book::fiction, false);
		return b;
	}

	Book::Book()
		:i_n(default_book().isbn()),
		 t(default_book().title()),
		 a(default_book().author()),
		 c_d(default_book().cop_date()),
		 g(default_book().genre()),
		 ch_out(default_book().check_out()) {}

	void Book::check_out_out()
	{
		if (check_out())
			std::cout<<"already checked out";
		ch_out=true;
	}

	void Book::check_out_in()
	{
		if (!check_out())
			std::cout<<"already checked in";
		ch_out=false;
	}

	bool operator==(const Book& book_1, const Book& book_2)
	{
		return (book_1.isbn()==book_2.isbn());
	}

	bool operator!=(const Book& book_1, const Book& book_2)
	{
		return !(book_1==book_2);
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		return os<<book.title()<<"\n"
				<<book.author()<<"\n"
				<<book.isbn().x1<<'-'<< book.isbn().x2<<'-'
				<<book.isbn().x3<<'-'<<book.isbn().x4<<"\n";
	}

	Patron::Patron(int c_n, std::string n, double f)
		:card_number(c_n), name(n), fees(f) {}

	const Patron& default_patron()
	{
		static const Patron p(0, "", 0);
		return p;
	}

	Patron::Patron()
		:card_number(default_patron().get_card_number()),
		 name(default_patron().get_name()),
		 fees(default_patron().get_fees()) {}

	void Patron::set_fee(double f)
	{
		if (f<0)
			std::cout<<"set_fee(): fee cannot be smaller than zero";
		fees=f;
	}

	bool owes_fee(const Patron& p)
	{
		return p.get_fees()>0;
	}

	bool operator==(const Patron& patron_1, const Patron& patron_2)
	{
		return (patron_1.get_card_number()==patron_2.get_card_number());
	}

	bool operator!=(const Patron& patron_1, const Patron& patron_2)
	{
		return !(patron_1==patron_2);
	}

	Library::Transaction::Transaction(Book bb, Patron pp, Chrono::Date dd)
		:b(bb), p(pp), d(dd) {}

	const Library::Transaction& default_transaction()
	{
		static const Library::Transaction tt=Library::Transaction(Book(), Patron(), Chrono::Date());
		return tt;
	}

	Library::Transaction::Transaction()
		:b(default_transaction().b),
		 p(default_transaction().p),
		 d(default_transaction().d) {}

	Library::Library(std::vector<Book> b, std::vector<Patron> p, std::vector<Transaction> t)
		:books(b), patrons(p), transactions(t) {}

	const Library& default_library()
	{
		std::vector<Book> b;
		std::vector<Patron> p;
		std::vector<Library::Transaction> t;
        static const Library l(b,p,t);
        return l;
	}

	Library::Library()
		:books(default_library().get_books()),
		 patrons(default_library().get_patrons()),
		 transactions(default_library().get_transactions()) {}

	void Library::add_book(const Book& book)
	{
		for (int i=0; i<int(books.size()); ++i)
		{
			if (books[i]==book)
				std::cout<<"add_book(): book is already in library";
		}
		books.push_back(book);
	}

	void Library::add_patron(const Patron& patron)
	{
		for (int i=0; i<int(patrons.size()); ++i)
		{
			if (patrons[i]==patron)
				std::cout<<"add_patron(): patron is already in library";
		}
		patrons.push_back(patron);
	}

	void Library::check_out(Book& b, const Patron& p, const Chrono::Date& d)
	{
		bool b_exists=false;
		int b_idx=0;
		for (int i=0; i<int(books.size()); ++i)
		{
			if (books[i]==b)
			{
				b_exists=true;
				b_idx=i;
				break;
			}
		}
		if (!b_exists)
			std::cout<<"check_out(): book is not in library";
		if (books[b_idx].check_out())
			std::cout<<"check_out(): book is already checked out";
		bool p_exists=false;
		int p_idx=0;
		for (int i=0; i<int(patrons.size()); ++i)
		{
			if (patrons[i]==p)
			{
				p_exists=true;
				p_idx=i;
				break;
			}
		}
		if (!p_exists)
			std::cout<<"check_out(): patron is not registered";
		if (patrons[p_idx].get_fees()>0)
			std::cout<<"check_out(): patron owes library fees";
		transactions.push_back(Transaction(books[b_idx], patrons[p_idx], d));
		books[b_idx].check_out();
	}

	void Library::set_fee(const Patron& p, double f)
    {
		int idx=0;
        bool exists=false;
        for (int i=0; i<int(patrons.size()); ++i)
        {
            if (patrons[i]==p)
            {
                exists=true;
                idx=i;
                break;
            }
        }
        if (!exists)
        	std::cout<<"Library::set_fee(): patron does not exist";
        patrons[idx].set_fee(f);
    }

	std::vector<Patron> Library::get_debtors() const
	{
		std::vector<Patron> debtors;
		for (int i=0; i<int(patrons.size()); ++i)
		{
			if (patrons[i].get_fees()>0)
				debtors.push_back(patrons[i]);
		}
		return debtors;
	}
}
