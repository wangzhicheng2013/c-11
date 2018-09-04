/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-03
Description:string beads problem jin ri tou tiao
ChangeLog:
			1. create this file
 **************************************************/

#include "StringBeads.h"
Color::Color()
{
	color = 0;
}
void Color::Init(int _color, const vector<int>&_beads)
{
	color = _color;
	for (auto &it : _beads)
	{
		beads[it] = 1;
	}
}
/*
 * @purpose:judge that whether beads are consistent
 * @return true if is
   * */
bool Color::BeadsIsConsistent(int m)
{
	int size = beads.size();
	int i;
	int cnt = 0;
	for (i = 1;i < size;i++)
	{
		if (1 == beads[i])
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
		if (cnt >= m)
		{
			return true;
		}
	}
	if (1 == beads[1])
	{
		cnt++;
	}
	return cnt >= m;
}
StringBeads::StringBeads(int _m)
{
	// TODO Auto-generated constructor stub
	m = _m;
}
/*
 * @purpose:init string beads
 * @vec:first -- color second -- beads set
 * */
void StringBeads::Init(const vector<pair<int, Beads> >&vec)
{
	colors.resize(vec.size());
	int i;
	int size = vec.size();
	for (i = 0;i < size;i++)
	{
		colors[i].Init(vec[i].first, vec[i].second);
	}
}
/*
 * @purpose:get the count of invalid colors
 * */
int StringBeads::GetCountOfInValidColors()
{
	int count = 0;
	for (auto &it : colors)
	{
		if (it.BeadsIsConsistent(m))
		{
			++count;
		}
	}
	return count;
}
StringBeads::~StringBeads()
{
	// TODO Auto-generated destructor stub
}
