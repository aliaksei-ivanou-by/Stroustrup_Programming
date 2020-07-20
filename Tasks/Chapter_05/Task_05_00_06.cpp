#include "iostream"
#include "vector"
int main()
{
	try
	{
		std::cout<<"1 Success!\n";
		std::cout<<"2 Success!\n";
		std::cout<<"3 Success"<<"\n";
		std::cout<<"4 success"<<"\n";
		int res=7; std::vector<int> v(10); v[5]=res; std::cout<<"5 Success!\n";
		v[5]=7; if (v[5]=7) std::cout<<"6 Success!\n";
		if (true) std::cout<<"7 Success!\n"; else std::cout<<"7 Fail!\n";
		bool c=false; if (!c) std::cout<<"8 Success!\n"; else std::cout<<"8 Fail!\n";
		std::string s="ape"; c="fool"<s; if (!c) std::cout<<"9 Success!\n";
		s="ape"; if (s!="fool") std::cout<<"10 Success!\n";
		s="ape"; if (s!="fool") std::cout<<"11 Success!\n";
		s="ape"; if (s!="fool") std::cout<<"12 Success!\n";
		std::vector<char> vv(5); for (int i=0; i<vv.size(); i++) std::cout<<"13 Success!\n";
		std::vector<char> vvv(5); for (int i=0; i<vv.size(); i++) std::cout<<"14 Success!\n";
		s="15 Success!\n"; for (int i=0; i<12; i++) std::cout<<s[i];
		if (true) std::cout<<"16 Success!\n"; else std::cout<<"16 Fail!\n";
		int x=20; char cc=x; if (cc==x) std::cout<<"17 Success!\n";
		s="18 Success!\n"; for (int i=0; i<12; i++) std::cout<<s[i];
		std::vector<char> vvvv(5); for (int i=0; i<vv.size(); i++) std::cout<<"19 Success!\n";
		int ii=0; int jj=9; while(ii<10) ii++; if (jj<ii) std::cout<<"20 Success!\n";
		x=2; double d=2*x+0.5; if (d==2*x+0.5) std::cout<<"21 Success!\n";
		s="22 Success!\n"; for (int i=0; i<=11; i++) std::cout<<s[i];
		int i=0, j=9; while(i<10) ++i; if (j<i) std::cout<<"23 Success!\n";
		x=4; d=2*x+0.5; if (d==2*x+0.5) std::cout<<"24 Success!\n";
		std::cout<<"25 Success!\n";
		return 0;
	}
	catch(std::exception& e)
	{
		std::cerr<<"Error: "<<e.what()<<"\n";
		return 1;
	}
	catch(std::exception& e)
	{
		std::cerr<<"Unknown exception!"<<"\n";
		return 2;
	}
}
