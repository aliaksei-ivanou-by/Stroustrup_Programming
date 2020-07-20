#include "iostream"
#include "fstream"
using namespace std;

bool whitespace(char ch)
{
    return (ch==' ' || ch=='\t' || ch=='\n');
}

int main()
try {
    string input;
    cout<<"Enter input file name: ";
    cin>>input;
    ifstream ifs(input.c_str());
    if (!ifs)
    	std::cout<<"can't open input file";
    int sum=0;
    char ch=0, ch_=0;
    int i=0;
    int count=0;
    string s;
    while (ifs>>ch)
    {
        if (isdigit(ch))
        {
            ifs.unget();
            if (ifs>>i)
            {
                if (ifs.eof() || ifs.get(ch) && whitespace(ch))
                {
                    ++count;
                    sum+=i;
                    cout<<i<<"\n";
                }
                else
                {
                    ifs.unget();
                    ifs>>s;
                }
            }
            else
            	std::cout<<"can't read integer";
        }
        else
        {
        	ch_=ch;
            ifs.unget();
            ifs>>s;
        }
    }
    cout<<"Sum of "<<count<<" whitespace-separated integers in file: "<<sum<<"\n";
}
catch (exception& e)
{
    cerr<<"exception: "<<e.what()<<"\n";
}
catch (...)
{
    cerr << "exception\n";
}
