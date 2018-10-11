/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-10-11
Description:string operation set
ChangeLog:
			1. create this file
			2. add StringContain method
 **************************************************/
#ifndef STRINGOP_H_
#define STRINGOP_H_
#include <string.h>
#include <ctype.h>
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
	/*
	 * @purpose:judge every character of small string is contained in the big string
	 * @return true if it contains
	 * */
	static bool StringContain(const string &bigstr, const string &smallstr);
};
}

#endif /* STRINGOP_H_ */
