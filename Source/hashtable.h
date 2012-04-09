#ifndef _class_
#define _class_
#include <unordered_map>
#include <string>
#include <iostream>


struct frames;
typedef std::tr1::unordered_map<std::string,frames> hashtable;
hashtable framelist;
frames setframesr(int setstart,int setstop);
void setFrames(std::string name,int start, int stop);
int getStartframe(std::string sf);
int getStopframe(std::string sf);
int main();

#endif

