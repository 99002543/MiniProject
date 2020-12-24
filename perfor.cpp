#include "perfor.h"
//#include "base.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include<vector>
#include <bits/stdc++.h>

using namespace std;
float DailySales;
perfor::perfor(){}
perfor::perfor(std::string d,std::string l,std::string h,std::string o,std::string c,std::string v):base(d,o,h,l,c,v){}

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


std::list<base> perfor::get_data()
{
  std::string line,word,temp;
  ifstream data;
    data.open("l.csv");
    int row_count =0 ;
    while(getline(data,line))
    {
        

      //  std::stringstream  lineStream(line);
        std::string        cell;
 
	vector<string> dat = make_data(line);
	//std::cout<<dat[2]<<endl;
	datal.push_back(base(dat[0],dat[1],dat[2],dat[3],dat[4],dat[5]));
    }
  /*list<base>::iterator iter;
	for(iter=datal.begin();iter!=datal.end;++iter)
	iter->display();*/
return datal;	
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
   void perfor::findByDate(string date)
   {	int flag=0;
       list<base>::iterator iter;
       remove("FindbyDate.txt");
       fstream fout;
       fout.open("FindbyDate.txt",ios::out | ios::app);
       
    for(iter=datal.begin();iter!=datal.end();++iter)
    {
        if(iter->getdate()==date)
        {
        	 fout<<"Date"<<iter->getdate()<<"\n"
		     <<"Opening Market Rate   "<<iter->geto_price()<<"\n"
		     <<"Closing Market Rate   "<<iter->getc_price()<<"\n"
		     <<"Highest Price of the Day   "<<iter->geth_price()<<"\n"
		     <<"Lowest Price of the day   "<<iter->getl_price()<<"\n"
		     <<"Stocks Sold and Buyed   "<<iter->get_volume()<<"\n"
		     <<"Approximate turn over of LTTS   "<<  DailySales
		     <<"\n";
           // return &(*iter);
        }
        /*else
        {
        flag++;
        std::cout<<date<<std::endl;
        } */
          
    }
    if(flag!=0)
    	std::cout<<"Invaild"<<std::endl;
    
    //return NULL;
   }
    void perfor::sortltts(std::list<base>& mylist)
	
{	
	mylist.sort( []( base& b1, base& b2)
	{ return b1.get_volume() > b2.get_volume();});
	fstream fout;
	remove("sortedfile.csv");
	fout.open("sortedfile.csv",ios::in|ios::app);
	for( auto iter = mylist.begin(); iter !=  mylist.end(); iter++)
	{
		float AvgDailyPrice;
		//auto temp1,temp2;
		//auto temp1=iter->geto_price();
		//auto temp2=iter->getc_price();
		//auto temp =(iter->geto_price())/2;
		 AvgDailyPrice = (stof(iter->geto_price()))+(stof(iter->getc_price()))/2;
		//float DailySales;
		DailySales=(AvgDailyPrice)*stof((iter->get_volume()));

		fout<<iter->getdate()<<","
		     <<iter->geto_price()<<","
		     <<iter->getc_price()<<","
		     <<iter->geth_price()<<","
		     <<iter->getl_price()<<","
		     <<iter->get_volume()<<","
		     <<DailySales
		     <<"\n";
		     
	}
	fout.close();

}
	void perfor::topn()
	{	int days;
		std::string line;
		std::cout<<"enter the number of top performance days to be listed"<<std::endl;
		std::cin>>days;
		std::list<base>temp;
		fstream fin,fout;
		remove("topn.csv");
		fout.open("topn.csv",ios::out | ios::app);
		fin.open("sortedfile.csv",ios::in);
		std::string a,b,c,d,e,f,g;
			int i=0;
			string str;
			for(int i=0; i<days; i++)
			{ getline(fin,line);
			  stringstream s(line);
			  getline(s,a,',');
			  getline(s,b,',');
			  getline(s,c,',');
			  getline(s,d,',');
			  getline(s,e,',');
			  getline(s,f,',');
			  getline(s,g,',');
			  
			  //getline(s,base(word));
			  //temp.emplace_back(a,b,c,d,e,f,g);
			  /*for(int j=0;j<7;j++)
			  {
			  	 getline(s,str,",");
			  	 fout<<str<<",";
			  }*/
			  fout<<a<<","
			      <<b<<","
			      <<c<<","
			      <<d<<","
			      <<e<<","
			      <<f<<","
			      <<g<<","
			       <<"\n";
			}
			
			fin.close();
			fout.close();
			//return temp;
			
	}
					
			
			
			
			

		
		
		
	
	int main()
{  	
	perfor p;
	std::list<base> c;
	c=p.get_data();
	p.sortltts(c);
	for (auto iter = c.begin(); iter !=c.end(); iter++)
	{
		iter->display();
	}
	p.topn();
	std::string s;
	std::cout<<"enter the date"<<std::endl;
	std::cin>>s;
	p.findByDate(s);

}



