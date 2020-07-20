#ifndef TASK_16_08_STDAFX_H
#include "Task_16_08_stdafx.h"
#include "Task_16_08_Currency_converter.h"
#endif

Graph_lib::Currency_converter::Currency_converter(Point xy, int w, int h, const string& title)
	: Window{ xy, w, h, title },
	amount_in{ Point(10, 10), 150, 20, "" },
	amount_out{ Point(200, 10), 150, 20, "" },
	menu_from{ Point(70, 30), 70, 20, Menu::vertical, "Change" },
	menu_to{ Point(270, 30), 70, 20, Menu::vertical, "Change" },
	text_from{ Point(160, 25), "" },
	text_to{ Point(350, 25), "" }
{
	get_currencies();

	from_cur = 0;
	to_cur = 0;

	attach(amount_in);
	attach(amount_out);

	for (int i = 0; i < currencies.size(); ++i)
	{
		Button* b1 = new Button(Point(0, 0), 0, 0, currencies[i], 
			[](Address b, Address pw)
			{
				int cur = reference_to<Currency_converter>(b).to_cur_pressed();
				reference_to<Currency_converter>(pw).set_label_to(cur);
			}
		);
		menu_to.attach(*b1);
	}
	attach(menu_to);

	for (int i = 0; i < currencies.size(); ++i)
	{
		Button* b2 = new Button(Point(0, 0), 0, 0, currencies[i], [](Address b, Address pw)
			{
				int cur = reference_to<Currency_converter>(b).from_cur_pressed();
				reference_to<Currency_converter>(pw).set_label_from(cur);
			}
		);
		menu_from.attach(*b2);
	}
	attach(menu_from);

	attach(text_to);
	attach(text_from);

	get_rates();
}

void Graph_lib::Currency_converter::get_rates()
{
	const string file_name = "currencies.txt";
	ifstream ifs(file_name.c_str());
	if (!ifs)
	{
		error("Can't open file ", file_name);
	}
	double rate;
	char ch;
	while (ifs >> ch && !isdigit(ch));
	ifs.unget();
	for (int i = 0; i < 4; ++i)
	{
		vector<double> temp;
		rates.push_back(temp);
		for (int j = 0; j < 4; ++j)
		{
			ifs >> rate;
			if (!ifs)
			{
				error("Some problem with adding rate from file ", file_name);
			}
			rates[i].push_back(rate);
		}
	}
}

void Graph_lib::Currency_converter::get_currencies()
{
	ifstream ifs("currencies.txt");
	if (!ifs)
	{
		error("Some problem with adding currency from file");
	}
	string s;
	getline(ifs, s);
	char* cstr = const_cast<char*>(s.c_str());
	char* pch;
	char* next_token = NULL;
	pch = strtok_s(cstr, "\t", &next_token);
	while (pch != NULL)
	{
		string ss = pch;
		currencies.push_back(ss);
		pch = strtok_s(NULL, "\t", &next_token);
	}
}

int Graph_lib::Currency_converter::from_cur_pressed()
{
	int k = (*this).y() - 30;
	int key = 0;
	while (k != 0)
	{
		k -= 20;
		key++;
	}
	return key;
}

void Graph_lib::Currency_converter::set_label_from(int cur)
{

	from_cur = cur;
	text_from.set_label(currencies[cur]);
	redraw();
	calculate();
}

int Graph_lib::Currency_converter::to_cur_pressed()
{
	int k = (*this).y() - 30;
	int key = 0;
	while (k != 0)
	{
		k -= 20;
		key++;
	}
	return key;
}

void Graph_lib::Currency_converter::set_label_to(int cur)
{
	to_cur = cur;
	text_to.set_label(currencies[cur]);
	redraw();
	calculate();
}

void Graph_lib::Currency_converter::calculate()
{
	string input_str = amount_in.get_string();
	if (input_str == "")
	{
		return;
	}
	istringstream iss(input_str);
	double input;
	iss >> input;
	if (!iss)
	{
		return;
	}
	double output = input * rates[from_cur][to_cur];
	ostringstream oss;
	oss << fixed << setprecision(2) << output;
	amount_out.put(oss.str());
}