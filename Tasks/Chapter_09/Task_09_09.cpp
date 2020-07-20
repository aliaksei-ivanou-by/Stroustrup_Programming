#include "iostream"
#include "Task_09_09_Lib.h"

int main()
{
	Lib::Library lib;
	Lib::Book book1(Lib::ISBN(9780, 4393, 5807, 'a'),
	        "Harry Potter and the Order of the Phoenix",
	        "Rowling, J.K.",
	        2003,
			Lib::Book::children,
	        false);
	lib.add_book(book1);
	Lib::Book book2(Lib::ISBN(9780, 4393, 5807, 'b'),
	        "Harry Potter and the Order of the Phoenix",
	        "Rowling, J.K.",
	        2003,
			Lib::Book::children,
	        false);
	lib.add_book(book2);
	Lib::Book book3(Lib::ISBN(9780, 4393, 5807, 'c'),
	        "Harry Potter and the Order of the Phoenix",
	        "Rowling, J.K.",
	        2003,
			Lib::Book::children,
	        false);
	lib.add_book(book3);
	Lib::Book book4(Lib::ISBN(9780, 4393, 5807, 'd'),
	        "Harry Potter and the Order of the Phoenix",
	        "Rowling, J.K.",
	        2003,
			Lib::Book::children,
	        false);
	lib.add_book(book4);
	std::cout<<"Library:\n";
	std::vector<Lib::Book> books=lib.get_books();
	for (int i=0; i<int(books.size()); ++i)
		std::cout<<books[i]<<"\n";
	Lib::Patron patron1=Lib::Patron(1, "Ivanou, Aliaksei", 0);
	lib.add_patron(patron1);
	Lib::Patron patron2=Lib::Patron(2, "Fatseyeva, Svyatlana", 0);
	lib.add_patron(patron2);
	std::cout<<"List of patrons:\n";
	std::vector<Lib::Patron> patrons=lib.get_patrons();
	for (int i=0; i<int(patrons.size()); ++i)
		std::cout<<patrons[i].get_name()<<", "<<patrons[i].get_card_number()<<"\n";
	lib.set_fee(patron1, 100);
	lib.set_fee(patron2, 200);
	std::cout<<"\nList of debtors:\n";
	std::vector<Lib::Patron> debtors=lib.get_debtors();
	for (int i=0; i<int(debtors.size()); ++i)
		std::cout<<debtors[i].get_name()<<", "<<debtors[i].get_fees()<<"\n";
	lib.check_out(book2, patrons[1], Chrono::Date(2020, Chrono::Date::jan, 23));
	std::cout<<"\nTransactions:\n";
	std::vector<Lib::Library::Transaction> transactions=lib.get_transactions();
	for (int i=0; i<int(transactions.size()); ++i)
		std::cout<<transactions[i].b<<transactions[i].d<<"\n"<<transactions[i].p.get_name()<<"\n";
	return 0;
}
