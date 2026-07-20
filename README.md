# 数据结构与算法练习仓库

> 个人学习《数据结构》过程中整理的 C/C++ 代码实现与算法题解集合。

本仓库主要用于记录和复习常见的数据结构、经典算法以及部分 OJ 题目的实现。代码以 **C 语言** 为主，部分 OJ 题解使用 **C++**。

---

## 📚 内容概览

### 1. 线性结构

| 模块 | 文件 | 说明 |
|---|---|---|
| 顺序表 | `ArrayList.*`、`arraylistmain.c` | 动态数组、增删改查 |
| 单链表 | `Link.*`、`LinkList.h`、`Linkmain.c` | 带头结点/不带头结点的链表操作 |
| 循环链表 | `LinkLoopList.*`、`lllmain.c` | 单向循环链表 |
| 双向循环链表 | `DoubleLoopList.*`、`dllmain.c` | 双向循环链表 |
| 顺序栈 | `stack.*`、`stackmain.c` | 基于数组的栈 |
| 链栈 | `linkStack.*`、`linkStackmain.c` | 基于链表的栈 |
| 顺序队列 | `ArrayQueue.*`、`ArrayQueuemain.c` | 循环队列 |
| 链队列 | `ListQueue.*`、`ListQueuemain.c` | 基于链表的队列 |

### 2. 树与二叉树

| 模块 | 文件 | 说明 |
|---|---|---|
| 二叉树 | `binary_tree.*`、`binary_treemain.c` | 建立、遍历（前/中/后/层序） |
| 线索二叉树 | `thread_BTree.*`、`thread_BTreeMain.c` | 中序线索化及遍历 |
| 二叉搜索树 | `binary_search_tree.*` | BST 的插入、删除、查找 |
| AVL 树 | `avlTree.*`、`avlTreemain.c` | 平衡二叉搜索树 |
| B 树 | `BTree.*`、`BTreeMain.c` | B-Tree 的基本操作 |
| 红黑树 | `RedBlackTree.*`、`RedBlackTreeMain.c` | Red-Black Tree 实现 |
| 哈夫曼树 | `haff.*`、`haffmantree.h`、`haffmain.c` | Huffman 树与编码 |

### 3. 图论

| 模块 | 文件 | 说明 |
|---|---|---|
| 邻接矩阵 | `martix.*`、`martixmain.c`、`MatrixGraph.h` | 图的顺序存储 |
| 邻接表 | `AdjancencyList.*`、`AdjancencyList_Main.c` | 图的链式存储 |
| 十字链表 | `crossLinkGraph.*`、`crossLinkGraph_main.c` | 有向图的十字链表表示 |
| 链式前向星 | `链式前向星.cpp` | 图论竞赛常用存图方式 |
| Prim | `Prim.*` | 最小生成树 |
| Kruskal | `Kruskal.*` | 最小生成树 + 并查集 |
| Dijkstra | `Dijkstra.*`、`DjikstraMain.c`、`Tini-Dijkstra.cpp` | 单源最短路 |
| Bellman-Ford | `Bellman-Ford.cpp` | 含负权边的最短路 |
| SPFA | `SPFA.cpp` | 队列优化的 Bellman-Ford |
| Floyd | `Floyd.*` | 多源最短路 |
| 拓扑排序 | `TopoSort.*`、`Topomain.c` | AOV 网拓扑排序 |
| 关键路径 | `KeyPath.*`、`Keymain.c` | AOE 网关键路径 |

### 4. 排序算法

| 算法 | 文件 |
|---|---|
| 冒泡排序 | `bubble_sort.*`、`swap_sort_main.c` |
| 插入排序 | `insert_sort.*`、`insert_sort_main.c` |
| 归并排序 | `merge_sort.*`、`merge_main.c` |
| 快速排序 | `quick_sort.*` |
| 堆排序 | `heap_sort.*`、`heap_main.c`、`mini_Heap.*` |

> 公共排序辅助函数见 `sort_helper.*`。

### 5. 字符串与查找

| 模块 | 文件 | 说明 |
|---|---|---|
| KMP | `KMP.*`、`KMPmain.c` | 字符串匹配 |
| 哈希 + 前缀和 | `字符串匹配 哈希+前缀和.cpp` | 字符串哈希匹配 |
| 并查集 | `quickfind.*`、`quickunion.*` | 路径压缩、按秩合并 |

### 6. 算法题解（OJ）

| 来源 | 题目示例 |
|---|---|
| 洛谷 lg | 棋盘、选数、八皇后、走迷宫、01 背包、快速幂、单调栈/队列、BFS/DFS、最短路等 |
| LeetCode lc | LRU（146）、字符串反转（151） |
| XUPT | 回文、查找 |
| 其他 | 搜索 N 迷宫、斐波那契数列、欧拉筛 |

---


## 📁 目录说明

```text
01struct/
├── *.c / *.h          # 数据结构基础实现
├── *.cpp              # 部分算法题解或 C++ 特性实现
├── *_main.c / *_Main.c / *main.c   # 对应模块的测试/演示入口
```

---

## 🎯 学习路线建议

1. **线性结构**：顺序表 → 链表 → 栈 → 队列
2. **树**：二叉树 → 线索二叉树 → BST → AVL → B 树 → 红黑树
3. **图**：邻接矩阵/表 → 遍历 → 最小生成树 → 最短路 → 拓扑排序/关键路径
4. **排序**：冒泡/插入 → 快排/归并/堆排
5. **字符串与高级结构**：KMP、并查集、线段树、单调栈/队列等

---

## 📝 备注

- 本仓库为个人学习记录，代码风格与注释密度不一，部分实现参考了教材或网络资料。
- 文件名保留了创建时的原始拼写（如 `AdjancencyList`、`DjikstraMain`），便于本地工程对应。
- 如果你有更好的实现或发现 Bug，欢迎提交 Issue 或 Pull Request。

---

## 📄 License

本项目采用 [MIT License](LICENSE) 开源。

> 如果对你有帮助，欢迎点个 ⭐️ Star ~
