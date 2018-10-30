/*
 * AuthorityMessageDispatch.h
 *
 *  Created on: 2018-10-30
 *      Author: root
 */

#ifndef AUTHORITYMESSAGEDISPATCH_H_
#define AUTHORITYMESSAGEDISPATCH_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define S_FIELD_CAPACITY 256
typedef enum ResourceOperationType
{
	CREATE,
	DELETE
}ResourceOperationType;
typedef enum ResourceType
{
	AE,
	CIN
}ResourceType;
typedef enum NodeType
{
	UNCOMPLETED,
	COMPLETED
}NodeType;
typedef void (*AuthorityMsgProcessPtr)();
typedef struct AuthorityMsgNode
{
	AuthorityMsgProcessPtr AuthorityMsgProcessFun;
	NodeType nodetype;
	struct AuthorityMsgNode *fields[S_FIELD_CAPACITY];
}AuthorityMsgNode;
typedef struct AuthorityMsgMapper
{
	AuthorityMsgNode *root;
}AuthorityMsgMapper;
typedef struct AuthorityMsgInfo
{
	ResourceOperationType oprType;
	ResourceType resourceType;
	AuthorityMsgProcessPtr MsgProcessPtr;
}AuthorityMsgInfo;
static AuthorityMsgMapper authorityMsgMapper = {0};
static AuthorityMsgNode *CreateAuthorityMsgNode()
{
	return (AuthorityMsgNode *)malloc(sizeof(AuthorityMsgNode));
}
static void InsertAuthorityMsgNode(const AuthorityMsgInfo *);
#endif /* MESSAGEDISPATCH_H_ */
