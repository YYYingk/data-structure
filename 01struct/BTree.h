#ifndef DISK_BTREE_H
#define DISK_BTREE_H
#define MaxOrder		3			// B树的阶
typedef int KeyType;				// B树节点键值类型

/* B树的阶是MaxOrder（3）,说明最大有3棵子树
 * 在插入节点时，当键值数量为3时，进行分离，申请MaxOrder + 1，从1索引开始填入键值申请的k3
 * 触发节点存放的个数为3，触发分离现象
 * | k0 | k1 | k2 | k3 |		K0无效的，K3是防越界
 * | p0 | p1 | p2 | p3 |
 * p0 < k1,   k1 < p1 < k2，p2 > k2, p3不会访问
 */
 // B树的节点结构
typedef struct _BTNode {
	KeyType key[MaxOrder + 1];				// [ 1...MaxOrder -1 ]
	struct _BTNode* ptr[MaxOrder + 1];		// 0开始存放关系
	struct _BTNode* parent;					// 指向父节点
	int keyNum;								// 该节点的键值数量
} BTNode;

// B树头的结构封装
typedef struct {
	BTNode* root;
	int count;
} DiskBTree;

/* B树查找的结果集，包含查找成功和失败
 * ptr : 查找成功，标记为键值所在的节点地址
 *       查找失败，标记待插入节点的父节点地址
 * pos : 查找成功，标记为键值所在的节点的位序索引号
 *       查找失败，标记待插入节点的父节点的位序索引号
 * tag : 1表示查找成功，0表示查找失败
 * */
typedef struct {
	BTNode* ptr;
	int pos;
	int tag;
}Result;

DiskBTree* initDiskBTree();             // 初始化B树
void releaseDiskBTree(DiskBTree* tree); // 释放B树
// 查找B树中key的位置，分查找成功和失败，分别更新res
void searchBTree(const DiskBTree* tree, KeyType key, Result* res);
// 将key值插入到B树
void insertKey(DiskBTree* tree, KeyType key);
// 将key值从B树删除
void deleteKey(DiskBTree* tree, KeyType key);
// 按层次打印B树
void PrintBTree(const BTNode* t, int tab);
// 按关键字大小升序输出B-树关键字
void orderTravelBTree(const DiskBTree* tree);

#endif // DISK_BTREE_H
