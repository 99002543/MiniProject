#ifndef __PERFOR_H
#define __PERFOR_H


#include<iostream>
//#include "Ltts.h"
#include "base.h"
#include<vector>
//using namespace std;

class perfor : public base
{	
list <base> datal;
   public:
   perfor();
  perfor(std::string,std::string,std::string,std::string,std::string);
   void get_data();
   vector<std::string> make_data(std::string);
   string day_high();
   string day_low();
    base* findByDate(std::string);
	int high_rate();
	int low_rate();
	
	//void display();
};

#endif
