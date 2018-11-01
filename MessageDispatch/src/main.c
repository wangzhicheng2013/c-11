/*
 * main.c
 *
 *  Created on: 2018-10-31
 *      Author: root
 */
#include "AuthorityMessageDispatch.h"
int main()
{
	InitAuthorityMsgMapper();
	AuthorityMsgInfo authorityMsgInfo0 = {CREATE, AE, NULL};
	AuthorityMsgInfo authorityMsgInfo1 = {CREATE, CIN, NULL};
	AuthorityMsgInfo authorityMsgInfo2 = {DELETE, AE, NULL};
	AuthorityMsgDispatch(&authorityMsgInfo0);
	AuthorityMsgDispatch(&authorityMsgInfo1);
	AuthorityMsgDispatch(&authorityMsgInfo2);
	DestroyAuthorityMsgMapper();
	return 0;
}
