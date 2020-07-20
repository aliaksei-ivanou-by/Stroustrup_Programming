#include "iostream"
#include "iomanip"

int main()
{
	int l_name=10;
	int l_surname=12;
	int l_cell_phone=15;
	int l_e_mail=30;
	std::cout<<std::setw(l_name)<<"Name"<<std::setw(l_surname)<<"Surname"
			<<std::setw(l_cell_phone)<<"Cell phone"<<std::setw(l_e_mail)<<"E-mail"<<"\n";
	std::cout<<std::setw(l_name)<<"Smith"<<std::setw(l_surname)<<"Cooper"
			<<std::setw(l_cell_phone)<<"+375291111111"<<std::setw(l_e_mail)<<"smith_cooper@mail.com"<<"\n";
	std::cout<<std::setw(l_name)<<"Johnson"<<std::setw(l_surname)<<"Richardson"
			<<std::setw(l_cell_phone)<<"+375292222222"<<std::setw(l_e_mail)<<"johnson_richardson@mail.com"<<"\n";
	std::cout<<std::setw(l_name)<<"Williams"<<std::setw(l_surname)<<"Morales"
			<<std::setw(l_cell_phone)<<"+375293333333"<<std::setw(l_e_mail)<<"williams_morales@mail.com"<<"\n";
	std::cout<<std::setw(l_name)<<"Davis"<<std::setw(l_surname)<<"Jenkins"
			<<std::setw(l_cell_phone)<<"+375294444444"<<std::setw(l_e_mail)<<"davis_jenkins@mail.com"<<"\n";
	std::cout<<std::setw(l_name)<<"Miller"<<std::setw(l_surname)<<"Fisher"
			<<std::setw(l_cell_phone)<<"+375297777777"<<std::setw(l_e_mail)<<"miller_fisher@mail.com"<<"\n";
	return 0;
}
