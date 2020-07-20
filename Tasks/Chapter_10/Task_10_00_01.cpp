#include "iostream"
#include "vector"
#include "fstream"

struct Point
{
	int x;
	int y;
	Point()
		:x(0), y(0) {}
	Point(int x_, int y_)
		:x(x_), y(y_) {}
};

bool operator==(const Point& p1, const Point& p2)
{
	return p1.x==p2.x && p1.x==p2.y;
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1==p2);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	return os<<'('<<p.x<<','<<p.y<<')';
}

std::istream& operator>>(std::istream& is, Point& p)
{
	int x, y;
	char ch1, ch2, ch3;
	is>>ch1>>x>>ch2>>y>>ch3;
	if (!is)
		return is;
	if (ch1!='(' || ch2!=',' || ch3!=')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}
	p=Point(x, y);
	return is;
}

void print_vector(const std::vector<Point>& points)
{
	for(int i=0; i<int(points.size()); i++)
		std::cout<<points[i]<<"\n";
}

void write_to_file(const std::vector<Point>& points, const std::string& filename)
try
{
	std::ofstream ost(filename.c_str());
	if (!ost)
		throw "can't open output file\n";
	for(int i=0; i<int(points.size()); i++)
		ost<<points[i]<<"\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}
void write_from_file(std::vector<Point>& processed_points, const std::string& filename)
try
{
	std::ifstream ist(filename.c_str());
	if(!ist)
		throw "can't open input file";
	Point pp;
	while (ist>>pp)
		processed_points.push_back(pp);
}
catch(const char* msg)
{
	std::cout<<msg;
}

void compare_vectors(const std::vector<Point> & p1, std::vector<Point>& p2)
try
{
	if (p1.size() != p2.size())
        throw "wrong size of vectors";
	for (int i=0; i<int(p1.size()); ++i)
	{
		if (p1[i]!=p2[i])
			throw "p1!=p1";
	}
	std::cout<<"Vectors are equal\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}

int main()
try
{
	std::vector<Point> original_points;
	std::cout<<"Enter 7 (x, y) pairs:\n";
	for (int i=0; i<7; ++i)
	{
		Point p;
		std::cin>>p;
		original_points.push_back(p);
	}

	std::cout<<"\nOriginal points:\n";
	print_vector(original_points);

	std::string filename="Task_10_00_01_mydata.txt";
	write_to_file(original_points, filename);

	std::vector<Point> processed_points;
	write_from_file(processed_points, filename);

	std::cout << "\nOriginal data:\n";
	print_vector(original_points);
	std::cout<<"\nData from ifstream:\n";
	print_vector(processed_points);

	compare_vectors(original_points, processed_points);
}
catch(const char* msg)
{
	std::cout<<msg;
}
