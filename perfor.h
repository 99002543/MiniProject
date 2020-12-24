#ifndef __PERFOR_H
#define __PERFOR_H


#include<iostream>
//#include "Ltts.h"
#include "base.h"
#include<vector>
//using namespace std;

class perfor : public base
{	

   public:
std::list <base> datal;
std::list <base> sort_data;
   perfor();
  perfor(std::string,std::string,std::string,std::string,std::string,std::string);
  std::list<base>  get_data();
   vector<std::string> make_data(std::string);
   string day_high();
   string day_low();
    void findByDate(std::string);
	int high_rate();
	int low_rate();
	void sortltts(std::list<base>&);
	void topn();
	
	//void display();
};

#endif
