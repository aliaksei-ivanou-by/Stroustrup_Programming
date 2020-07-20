#include "iostream"
#include "fstream"

class Roman_int
{
public:
	Roman_int();
	Roman_int(int r_i);
	int as_int() const
	{
		return roman_int;
	}
	void set_val(int v)
	{
		roman_int=v;
	}
private:
	int roman_int;
};

const char N='N';
const char I='I';
const char V='V';
const char X='X';
const char L='L';
const char C='C';
const char D='D';
const char M='M';

Roman_int operator+(const Roman_int& r_i1, const Roman_int& r_i2);
Roman_int operator-(const Roman_int& r_i1, const Roman_int& r_i2);
Roman_int operator-(const Roman_int& r_i);
Roman_int operator*(const Roman_int& r_i1, const Roman_int& r_i2);
Roman_int operator/(const Roman_int& r_i1, const Roman_int& r_i2);
Roman_int operator%(const Roman_int& r_i1, const Roman_int& r_i2);
bool operator==(const Roman_int& r_i1, const Roman_int& r_i2);
bool operator!=(const Roman_int& r_i1, const Roman_int& r_i2);
bool operator>(const Roman_int& r_i1, const Roman_int& r_i2);
bool operator<(const Roman_int& r_i1, const Roman_int& r_i2);
bool operator>=(const Roman_int& r_i1, const Roman_int& r_i2);
bool operator<=(const Roman_int& r_i1, const Roman_int& r_i2);
bool is_valid_char(char ch);
int get_value(char ch);
bool counter_illegal(int counter, char ch);
int roman_int_to_int(const std::string& s);
std::ostream& operator<<(std::ostream& os, const Roman_int& r_i);
std::istream& operator>>(std::istream& is, Roman_int& r_i);
