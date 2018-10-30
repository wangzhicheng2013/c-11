/*
 * AuthorityMessageDispatch.c
 *
 *  Created on: 2018-10-30
 *      Author: root
 */
#include "AuthorityMessageDispatch.h"
static void InsertAuthorityMsgNode(const AuthorityMsgInfo *pAuthorityMsgInfo)
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
		pos = key[index];
		if (NULL == ptr->fields[pos])
		{
			ptr->fields[pos] = CreateAuthorityMsgNode();
			if (NULL == ptr->fields[pos])
			{
				perror("memory use over...!");
				exit(EXIT_FAILURE);
			}
			ptr = ptr->fields[pos];
		}
	}
	ptr->nodetype = COMPLETED;
	ptr->AuthorityMsgProcessFun = pAuthorityMsgInfo->MsgProcessPtr;
}
