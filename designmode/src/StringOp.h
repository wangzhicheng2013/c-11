/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-08-24
Description:string operation set
ChangeLog:
			1. create this file
 **************************************************/
#ifndef STRINGOP_H_
#define STRINGOP_H_
#include <string.h>
#include <string>
namespace stringop {
using namespace std;
class StringOp
{
public:
	/*
	 * @purpose:erase source string with delete string
	 * */
	static void Erase(string &sourcestr, const string &delstr);
};
}

#endif /* STRINGOP_H_ */
