#include <unordered_map>
#include <string>
#include <iostream>
#include <irrlicht.h>
#include "frametable.h"

class frametable{
public:
	frametable()
	{}
};

struct frames
   {
	  irr::s32 start;
	  irr::s32 stop;
   }ssframes;

frames active;

int main()
{

}


 frames setframesr(irr::s32 setstart,irr::s32 setstop) // required for setFrames
 {
	  struct frames ssframes ={setstart,setstop};
	  return ssframes;
 }

 void setFrames(std::string name,irr::s32 start, irr::s32 stop) // saves frames; parameters: name of frame(for example "idle"), starting frame, stopping frame;
 {
	   framelist.insert(std::pair<std::string,frames>(name,setframesr(start,stop)));
 }

frames getframes(std::string s)
{
	hashtable::iterator it= framelist.find(s);
    if(it!=framelist.end())
     
    return it->second;
}

void setactive(frames x)
{
	active = x;
}
