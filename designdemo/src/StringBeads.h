/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-03
Description:string beads problem jin ri tou tiao
ChangeLog:
			1. create this file
 **************************************************/
#ifndef STRINGBEADS_H_
#define STRINGBEADS_H_
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
/*
1      2      3
1  1      1      1
2  0      0      0
3  0      1      1
4  0      1      0
5  0      0      1
*/
const static int BEADNUM = 5;
class Color
{
public:
	Color();
	void Init(int, const vector<int>&);
	/*
	 * @purpose:judge that whether beads are consistent
	 * @return true if is
	   * */
	bool BeadsIsConsistent(int);
private:
	int color;
	bitset<BEADNUM + 1>beads;
};
using Beads = vector<int>;
class StringBeads
{
public:
	StringBeads(int);
	/*
	 * @purpose:init string beads
	 * */
	void Init(const vector<pair<int, Beads> >&);
	/*
	 * @purpose:get the count of invalid colors
	 * */
	int GetCountOfInValidColors();
	virtual ~StringBeads();
private:
	vector<Color>colors;
	int m;
};

#endif /* STRINGBEADS_H_ */
