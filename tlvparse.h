/*****************************************************************************
* 文件描述：PBOC3.0-TLV Parse
* 应用平台：linux
* 创建时间：20150918
* 作者：RedXu
*****************************************************************************/
#ifndef __TLVPARSE__H__
#define __TLVPARSE__H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct TLVNode{
	uint16_t Tag;				/*	T 	*/
	uint16_t Length;			/*	L 	*/
	unsigned char* Value;		/*	V 	*/
	unsigned char TagSize;
	unsigned char LengthSize;
	uint16_t MoreFlag;			/* Used In Sub */
	uint16_t SubFlag;			/* have Sub Node? */
	uint16_t SubCount;		
	struct TLVNode* Sub[256];
	struct TLVNode* Next;
};


/**
 * 解析数据,生成TLV结构
 * @param  buf  [数据]
 * @param  size [数据长度]
 * @return      [TLVNode]
 */
struct TLVNode* TLV_Parse(unsigned char* buf,int size);

/**
 * 合并src结构到target
 * @param target [目标TLVNode]
 * @param src    [源TLVNode]
 */
void TLV_Merge(struct TLVNode* target,struct TLVNode* src);

/**
 * 在node中查找tag.
 * @param  node [TLVNode]
 * @param  tag  [tag标签]
 * @return      [NULL - 未找到]
 */
struct TLVNode* TLV_Find(struct TLVNode* node,uint16_t tag);

/**
 * Free TLVNode Memory
 * @param node [node]
 */
void TLV_Free(struct TLVNode* node);

void TLV_DebugNode(struct TLVNode* node);


#ifdef __cplusplus
}
#endif

#endif

