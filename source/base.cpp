#include "base.h"
#include <list>
#include <iterator>
#include<iostream>
#include <fstream>
//#include <ofstream>
#include <sstream>
#include <iostream>
#include<vector>
using namespace std;


base::base(){}
base::base(string d,string l,string h,string o, string c):date(d),o_price(o),h_price(h),l_price(l),c_price(c){}
string base::getdate()
{
	return(date);
}
string base::geto_price()
{
	return(o_price);
}
string base::getc_price()
{
	return(c_price);
}
string base::geth_price()
{
	return(h_price);
}
string base::getl_price()
{
	return(l_price);
}
void base::display()
{
	cout<<date;
	cout<<o_price<<endl;
	cout<<c_price<<endl;
	cout<<h_price<<endl;
	cout<<l_price<<endl;
}
void base::display_date()
{ 
	cout<<date<<endl;
}









