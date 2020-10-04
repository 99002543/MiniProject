#include "perfor.h"
//#include "base.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include<vector>

//using namespace std;

perfor::perfor(){}
perfor::perfor(std::string d,std::string l,std::string h,std::string o,std::string c):base(d,o,h,l,c){}

vector<std::string> perfor::make_data(std::string line)
{
 vector<std::string> data ;
//vector<string> :: iterator iter;
std::string word;
std::stringstream s(line);  
data.clear();   
    while (getline(s, word, ',')) 
{ 
    data.push_back(word);
} 
return data;
}


void perfor::get_data()
{
  std::string line,word,temp;
  ifstream data;
    data.open("l.csv");
    int row_count =0 ;
    while(getline(data,line))
    {
        row_count +=1;

      //  std::stringstream  lineStream(line);
        std::string        cell;
        int column_count = 0 ;
	vector<string> dat = make_data(line);
	//std::cout<<dat[2]<<endl;
	datal.push_back(base(dat[0],dat[1],dat[2],dat[3],dat[4]));
    }
  /*list<base>::iterator iter;
	for(iter=datal.begin();iter!=datal.end;++iter)
	iter->display();*/	
}

 string perfor::day_high()
 {		
 	int temp, max;
	max=0;
       temp=0;
 	std::list<base>::iterator iter;
	auto iter1=iter;
	for(iter=datal.begin();iter!=datal.end();++iter)	
 	{
		//std::cout<<iter->getdate;
	temp=stoi(iter->geth_price());
        if(temp>max)
        {
            max=temp;
	    iter1=iter;
        }
	}
	return(iter1->getdate());
	//cout<<max<<endl;
		
 	//temp.sort();
 	//return(temp.back());
 }
 int perfor::high_rate()
 {		
 	int temp, max;
	max=0;
       temp=0;
 	std::list<base>::iterator iter;
	auto iter1=iter;
	for(iter=datal.begin();iter!=datal.end();++iter)	
 	{
		//std::cout<<iter->getdate;
	temp=stoi(iter->geth_price());
        if(temp>max)
        {
            max=temp;
	    iter1=iter;
        }
	}
	//iter1->display_date();
	//cout<<max<<endl;
       return(max);
		
 	//temp.sort();
 	//return(temp.back());
 }
string perfor::day_low()
{  	
	
	int temp, min;
	min=1000000;
        temp=0;
 	std::list<base>::iterator iter;
	auto iter1=iter;
	for(iter=datal.begin();iter!=datal.end();++iter)	
 	{
		//std::cout<<iter->getdate;
	temp=stoi(iter->getl_price());
        if(temp<min)
        {
            min=temp;
	    iter1=iter;
        }
	}
	return(iter1->getdate());
     //return(s);
	//cout<<min<<endl;
		
}

int perfor::low_rate()
{  	
	
	int temp, min;
	min=1000000;
        temp=0;
 	std::list<base>::iterator iter;
	auto iter1=iter;
	for(iter=datal.begin();iter!=datal.end();++iter)	
 	{
		//std::cout<<iter->getdate;
	temp=stoi(iter->getl_price());
        if(temp<min)
        {
            min=temp;
	    iter1=iter;
        }
	}
	//iter1->display_date();
	//cout<<min<<endl;
	return(min);	
}
   base* perfor::findByDate(string date)
   {
       list<base>::iterator iter;
    for(iter=datal.begin();iter!=datal.end();++iter)
    {
        if(iter->getdate()==date)
        {
            return &(*iter);
        }
    }
    return NULL;
   }



