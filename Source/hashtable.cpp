#include <unordered_map>
#include <string>
#include <iostream>
#include "hashtable.h"
struct frames
   {
	  int start;
	  int stop;
	  int returnstart()
	  {
		  return start;
	  }
	  int returnstop()
	  {
		  return stop;
	  }
   }ssframes;




int main()
{
	setFrames("A",1,300);
	setFrames("B",400,666);
	std::cout <<getStartframe("A") << getStopframe("A");
	std::cout <<getStartframe("B") << getStopframe("B");
	int i;
		std::cin >>i; 
	return 0;
}

 frames setframesr(int setstart,int setstop)
 {
	  struct frames ssframes ={setstart,setstop};
	  return ssframes;
 }

 void setFrames(std::string name,int start, int stop)
 {
	   framelist.insert(std::pair<std::string,frames>(name,setframesr(start,stop)));
 }

int getStartframe(std::string sf)
 {
	 hashtable::iterator it= framelist.find(sf);
	 if(it!=framelist.end())
     
	 return it->second.returnstart();
 }

int getStopframe(std::string sf)
 {
	 hashtable::iterator it= framelist.find(sf);
	 if(it!=framelist.end())
     
	 return it->second.returnstop();
 }
