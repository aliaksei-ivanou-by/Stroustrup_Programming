#include "iostream"
#include "fstream"
#include "sstream"
#include "vector"
#include "algorithm"

void to_lowercase(std::string& s)
{
    if (s.size()==0)
    	return;
    for (int i=0; i<int(s.size()); ++i)
        s[i]=tolower(s[i]);
}

void remove_punct(std::string& s)
{
    if (s.size()==0)
    	return;
    for (int i=0; i<int(s.size()); ++i)
    	if (ispunct(s[i]) && s[i]!='\'' && s[i]!='-')
        	s[i]=' ';
}

void remove_hyphen(std::string& s)
{
    if (s.size()==0)
    	return;
    if (s[0]=='-' && s[1]==' ')
    	s[0]=' ';
    if (s[s.size()-1]=='-' && s[s.size()-2]==' ')
    	s[s.size()-1]=' ';
    for (int i=1; i<int(s.size())-1; ++i)
    {
        if (s[i]=='-' && s[i-1]==' ' && s[i+1]==' ')
        	s[i]=' ';
        if (s[i]=='-' && s[i+1]=='-')
        {
            s[i]=' ';
            s[i+1]=' ';
            ++i;
        }
    }
}

void expand_aux(std::string& s)
{
    if (s.size()==0)
    	return;
    std::istringstream is(s);
    std::string word;
    std::string s_exp;
    std::ostringstream os(s_exp);
    while (is>>word) {
        if (word=="can't")
        	os<<"cannot";
        else
        	if (word.size()>=3
                 && word[word.size()-3]=='n'
                 && word[word.size()-2]=='\''
                 && word[word.size()-1]=='t')
        	{
        		for (int i=0; i<int(word.size())-3; ++i)
        			os<<word[i];
        		os<<" not";
        	}
        	else
        		os<<word;
        os<<' ';
    }
    s=os.str();
}

void convert_file(const std::string& input, const std::string& output)
try
{
    std::ifstream ifs(input.c_str());
    if (!ifs)
    	throw "can't open input file";
    std::ofstream ofs(output.c_str());
    if (!ofs)
    	throw "can't open output file";

    std::string s;
    while (getline(ifs,s))
    {
        to_lowercase(s);
        remove_punct(s);
        remove_hyphen(s);
        expand_aux(s);
        ofs<<s<<"\n";
    }
}
catch(const char* msg)
{
	std::cout<<msg;
}

void build_dictinary(const std::string& input, const std::string& output)
{
    std::ifstream ifs(input.c_str());
    if (!ifs)
    	throw "can't open input file";
    std::ofstream ofs(output.c_str());
    if (!ofs)
    	throw "can't open output file";

    std::vector<std::string> vs;
    std::string word;
    while (ifs>>word)
        vs.push_back(word);

    sort(vs.begin(),vs.end());

    for (int i=0; i<int(vs.size()); ++i)
        if (i==0 || vs[i]!=vs[i-1])
        	ofs<<vs[i]<<"\n";
}

int main()
try
{
    //std::cout<<"Enter input file name: ";
    std::string input;
    //std::cin>>input;
    input="Task_11_08_input.txt";
    //std::cout<<"Enter output file name: ";
    std::string output;
    //std::cin>>output;
    output="Task_11_08_output.txt";
    convert_file(input, output);
    //std::cout<<"Enter name for dictionary file: ";
    std::string output_dictinary;
    //std::cin>>output_dictinary;
    output_dictinary="Task_11_08_dictinary.txt";
    build_dictinary(output, output_dictinary);
}
catch (std::exception& e)
{
    std::cerr<<"exception: "<<e.what()<<"\n";
}
catch (...)
{
    std::cerr<<"exception\n";
}
