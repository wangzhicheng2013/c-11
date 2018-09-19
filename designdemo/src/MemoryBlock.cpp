/*************************************************
Copyright:wangzhicheng
Author: wangzhicheng
Date:2018-09-19
Description:memory block with moving constructor
ChangeLog:
			1. create this file
			2.add move copy constructor
**************************************************/

#include "MemoryBlock.h"

MemoryBlock::MemoryBlock()
{
	// TODO Auto-generated constructor stub
	data = nullptr;
	size = 0;
}
MemoryBlock::MemoryBlock(size_t size)
{
	if (size > BLOCKCAPACITY)
	{
		throw std::logic_error("block size is over the limit...");
	}
	this->size = size;
	data = new char[size];
	assert(data != nullptr);
	cout << "MemoryBlock(size_t size) called..." << endl;
}
MemoryBlock::MemoryBlock(const MemoryBlock &block)
{
	if (nullptr == block.data)
	{
		throw std::logic_error("block is null...");
	}
	size = block.size;
	data = new char[size];
	assert(data != nullptr);
	copy(block.data, block.data + size, data);
	cout << "MemoryBlock(const MemoryBlock &block) called..." << endl;
}
MemoryBlock::MemoryBlock(MemoryBlock &&block)
{
	if (nullptr == block.data)
	{
		throw std::logic_error("block is null...");
	}
	*this = move(block);
	cout << "MemoryBlock(MemoryBlock &&block) called..." << endl;
}
MemoryBlock & MemoryBlock::operator = (const MemoryBlock &block)
{
	if (nullptr == block.data)
	{
		throw std::logic_error("block is null...");
	}
	if (this == &block)
	{
		return *this;
	}
	if (nullptr != data)
	{
		delete []data;
	}
	size = block.size;
	data = new char[size];
	assert(data != nullptr);
	copy(block.data, block.data + size, data);
	cout << "MemoryBlock::operator = (const MemoryBlock &block) called..." << endl;
	return *this;
}
MemoryBlock & MemoryBlock::operator = (MemoryBlock &&block)
{
	if (nullptr == block.data)
	{
		throw std::logic_error("block is null...");
	}
	if (this == &block)
	{
		return *this;
	}
	if (nullptr != data)
	{
		delete []data;
	}
	data = block.data;
	size = block.size;
	block.data = nullptr;
	block.size = 0;
	cout << "MemoryBlock::operator = (const MemoryBlock &&block) called..." << endl;
	return *this;
}
MemoryBlock::~MemoryBlock()
{
	// TODO Auto-generated destructor stub
	if (nullptr != data)
	{
		delete []data;
		data = nullptr;
	}
	size = 0;
	cout << "~MemoryBlock() called..." << endl;
}
