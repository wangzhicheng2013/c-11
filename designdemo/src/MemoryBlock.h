/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-18
Description:memory block with moving constructor
ChangeLog:
			1. create this file
**************************************************/

#ifndef MEMORYBLOCK_H_
#define MEMORYBLOCK_H_
#include <string.h>
#include <assert.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>
static const int BLOCKCAPACITY = 1024 * 1024;
using namespace std;
class MemoryBlock
{
public:
	MemoryBlock();
	MemoryBlock(size_t);
	MemoryBlock(const MemoryBlock &);
	MemoryBlock(MemoryBlock &&);
	MemoryBlock & operator = (const MemoryBlock &);
	virtual ~MemoryBlock();
private:
	char *data;
	size_t size;
};

#endif /* MEMORYBLOCK_H_ */
