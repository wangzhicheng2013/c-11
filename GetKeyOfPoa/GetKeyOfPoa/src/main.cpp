/*
 * main.cpp
 *
 *  Created on: 2018-12-24
 *      Author: root
 */
#include "DispatchGetKeyOfPoa.h"
int main()
{
	cout << DispatchGetKeyOfPoa::GetInstance().GetPartition("mqtt-08//1212.12") << endl;
	return 0;
}
