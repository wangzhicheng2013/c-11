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
	AuthorityMsgInfo authorityMsgInfo0 = {CREATE, AE, AuthorizeAECreate};
	AuthorityMsgInfo authorityMsgInfo1 = {CREATE, CIN, AuthorizeCinCreate};
	AuthorityMsgInfo authorityMsgInfo2 = {DELETE, AE, AuthorizeAEDelete};
	AuthorityMsgDispatch(&authorityMsgInfo0);
	AuthorityMsgDispatch(&authorityMsgInfo1);
	AuthorityMsgDispatch(&authorityMsgInfo2);
	return 0;
}