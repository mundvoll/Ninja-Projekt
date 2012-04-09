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




int main() // main Method
{
	return 0;
}

 frames setframesr(int setstart,int setstop) // required for setFrames
 {
	  struct frames ssframes ={setstart,setstop};
	  return ssframes;
 }

 void setFrames(std::string name,int start, int stop) // saves frames; parameters: name of frame(for example "idle"), starting frame, stopping frame;
 {
	   framelist.insert(std::pair<std::string,frames>(name,setframesr(start,stop)));
 }

int getStartframe(std::string sf) // searches starting frame after the name and returns it
 {
	 hashtable::iterator it= framelist.find(sf);
	 if(it!=framelist.end())
     
	 return it->second.returnstart();
 }

int getStopframe(std::string sf) // searches stopping frame after the name and returns it
 {
	 hashtable::iterator it= framelist.find(sf);
	 if(it!=framelist.end())
     
	 return it->second.returnstop();
 }
