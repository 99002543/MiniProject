#ifndef __base_h
#define __base_h
#include <string>
#include<list>
#include<vector>
using namespace std;
class base
{
	string date;
	string o_price;
	string c_price;
	string h_price;
	string l_price;

	public:
	base();
	
	base(string,string,string,string,string);
	string getdate();
	string geto_price();
	string getc_price();
	string geth_price();
	string getl_price();
	void display();
	void display_date();
};
#endif
