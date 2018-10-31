/*
 * AuthorityMessageDispatch.c
 *
 *  Created on: 2018-10-31
 *      Author: root
 */
#include "AuthorityMessageDispatch.h"
//AuthorityMsgMapper authorityMsgMapper = {0};
/*
 * @purpose:create a new noode
 * */
AuthorityMsgNode *CreateAuthorityMsgNode()
{
	AuthorityMsgNode *ptr = (AuthorityMsgNode *)malloc(sizeof(AuthorityMsgNode));
	if (NULL == ptr)
	{
		return NULL;
	}
	ptr->nodetype = UNCOMPLETED;
	int i;
	for (i = 0;i < S_FIELD_CAPACITY;i++)
	{
		ptr->fields[i] = NULL;
	}
	return ptr;
}
/*
 * @purpose:authorize AE resouce create
 * */
void AuthorizeAECreate()
{
	printf("Now authorize AE create.\n");
}
/*
 * @purpose:authorize Cin resouce create
 * */
void AuthorizeCinCreate()
{
	printf("Now authorize CIN create.\n");
}
/*
 * @purpose:authorize AE resouce delete
 * */
void AuthorizeAEDelete()
{
	printf("Now authorize AE delete.\n");
}
/*
 * @purpose:inserta new node into mapper
 * */
void InsertAuthorityMsgNode(const AuthorityMsgInfo *pAuthorityMsgInfo)
{
	AuthorityMsgNode *ptr = authorityMsgMapper.root;
	char key[64] = "";
	int pos = -1;
	int index = 0;
	snprintf(key, sizeof(key), "%d%d",
			pAuthorityMsgInfo->oprType,
			pAuthorityMsgInfo->resourceType);
	for(;key[index];index++)
	{
		pos = key[index] - '0';
		if (NULL == ptr->fields[pos])
		{
			ptr->fields[pos] = CreateAuthorityMsgNode();
			if (NULL == ptr->fields[pos])
			{
				perror("memory use over...!");
				exit(EXIT_FAILURE);
			}
		}
		ptr = ptr->fields[pos];
	}
	ptr->nodetype = COMPLETED;
	ptr->AuthorityMsgProcessFun = pAuthorityMsgInfo->MsgProcessPtr;
}
/*
 * @purpose:init mapper
 * */
void InitAuthorityMsgMapper()
{
	authorityMsgMapper.root = CreateAuthorityMsgNode();
	if (NULL == authorityMsgMapper.root)
	{
		perror("memory use over...!");
		exit(EXIT_FAILURE);
	}
	AuthorityMsgInfo authorityMsgInfo0 = {CREATE, AE, AuthorizeAECreate};
	AuthorityMsgInfo authorityMsgInfo1 = {CREATE, CIN, AuthorizeCinCreate};
	AuthorityMsgInfo authorityMsgInfo2 = {DELETE, AE, AuthorizeAEDelete};
	InsertAuthorityMsgNode(&authorityMsgInfo0);
	InsertAuthorityMsgNode(&authorityMsgInfo1);
	InsertAuthorityMsgNode(&authorityMsgInfo2);
}
/*
 * @purpose:dispatch authorized message
 * */
void AuthorityMsgDispatch(const AuthorityMsgInfo *pAuthorityMsgInfo)
{
	AuthorityMsgNode *ptr = authorityMsgMapper.root;
	char key[64] = "";
	int pos = -1;
	int index = 0;
	snprintf(key, sizeof(key), "%d%d",
			pAuthorityMsgInfo->oprType,
			pAuthorityMsgInfo->resourceType);
	for(;key[index];index++)
	{
		pos = key[index] - '0';
		if (NULL == ptr->fields[pos])
		{
			break;
		}
		ptr = ptr->fields[pos];
	}
	if (0 == key[index] && COMPLETED == ptr->nodetype)
	{
		ptr->AuthorityMsgProcessFun();
	}
}
