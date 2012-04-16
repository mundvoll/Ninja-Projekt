#ifndef _frametable_
#define _frametable_
#include <unordered_map>
#include <string>
#include <iostream>

struct frames;
typedef std::tr1::unordered_map<std::string,frames> hashtable;
hashtable framelist;
frames setframesr(irr::s32 setstart,irr::s32 setstop);
void setFrames(std::string name,irr::s32 start, irr::s32 stop);
frames getframes(std::string s);
void setactive(frames x);

#endif

