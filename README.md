# STLSourceCodeNote
SGI STL source code analysis and note from 《STL源码剖析》 by 侯捷
（包含电子书、源码注释及测试代码）

		1.1 STL概论
			1.1.1 STL的历史
			1.1.2 STL与C++标准程序库
		1.2 STL六大组件 功能与运用
		1.3 GNU源代码开放精神
		1.4 HP实现版本
		1.5 P.J.Plauger实现版本
		1.6 Rouge Wave实现版本
		1.7 STLport实现版本
		1.8 SGI STL实现版本
			1.8.1 GNU C++headers文件分布(按字母排序)
			1.8.2 SGI STL文件分布与简介
			1.8.3 SGI STL的编译器组态设置(configuration)
		1.9 可能令你困惑的C++ 语法
			1.9.1 stl_config.h中的各种组态
			1.9.2 临时对象的产生与运用
			1.9.3 静态常量整数成员在class内部直接初始化
			1.9.4 increment／decrement／dereference 操作符
			1.9.5 前闭后开区间表示法[ )
			1.9.6 function call操作符(operator())
		2.1 空间配置器的标准接口
			2.1.1 设计一个简单的空间配置器，JJ::allocator
		2.2 具备次配置力(sub-allocation)的SGI空间配置器
			2.2.1 SGI标准的空间配置器，std::allocator
			2.2.2 SGI特殊的空间配置器，std::alloc
			2.2.3 构造和析构基本工具：construct()和destroy()
			2.2.4 空间的配置与释放，std::alloc
			2.2.5 第一级配置器＿malloc_alloc_template剖析
			2.2.6 第二级配置器＿default_alloc_template剖析
			2.2.7 空间配置函数allocate()
			2.2.8 空间释放函数deallocate()
			2.2.9 重新充填free lists
			2.2.10 内存池(memory pool)
		2.3 内存基本处理工具
			2.3.1 uninitialized_copy
			2.3.2 uninitialized_fill
			2.3.3 uninitialized_fill_n
		3.1 迭代器设计思维——STL关键所在
		3.2 迭代器(iterator)是一种smart pointer
		3.3 迭代器相应型别(associated types)
		3.4 Traits编程技法——STL源代码门钥
			3.4.1 迭代器相应型别之一：value_type
			3.4.2 迭代器相应型别之二：difference_type
			3.4.3 迭代器相应型别之三：reference_type
			3.4.4 迭代器相应型别之四：pointer_type
			3.4.5 迭代器相应型别之五：iterator_category
		3.5 std::iterator的保证
		3.6 iterator源代码完整重列
		3.7 SGI STL的私房菜：＿type_traits
		4.1 容器的概观与分类
			4.1.1 序列式容器(sequential containers)
		4.2 vector
			4.2.1 vector概述
			4.2.2 vector定义摘要
			4.2.3 vector的迭代器
			4.2.4 vector的数据结构
			4.2.5 vector的构造与内存管理：constructor，push_back
			4.2.6 vector的元素操作：pop_back,erase，clear，insert
		4.3 list
			4.3.1 list概述
			4.3.2 list的节点(node)	
			4.3.3 list的迭代器
			4.3.4 list的数据结构
			4.3.5 list的构造与内存管理：constructor，push_back，insert
			4.3.6 list的元素操作：push_front，push_back，erase，pop_front，pop_back，clear，remove，unique,splice，merge，reverse，sort
		4.4 deque
			4.4.1 deque概述
			4.4.2 deque的中控器
			4.4.3 deque的迭代器
			4.4.4 deque的数据结构
			4.4.5 deque的构造与内存管理ctor，push_back，push_front
			4.4.6 deque的元素操作pop_back，pop_front，clear，erase，insert
		4.5 stack
			4.5.1 stack概述
			4.5.2 stack定义完整列表
			4.5.3 stack没有迭代器
			4.5.4 以list作为stack的底层容器
		4.6 queue
			4.6.1 queue概述
			4.6.2 queue定义完整列表
			4.6.3 queue没有迭代器
			4.6.4 以list作为queue的底层容器
		4.7 heap(隐式表述，implicit representation)
			4.7.1 heap概述
			4.7.2 heap算法
				push_heap算法
				pop_heap算法
				sort_heap算法
				make heap算法
			4.7.3 heap没有迭代器
			4.7.4 heap测试实例
		4.8 priority_queue
			4.8.1 priority_queue概述
			4.8.2 priority_queue定义完整列表
			4.8.3 priority_queue没有迭代器
			4.8.4 priority_queue测试实例
		4.9 slist 	
			4.9.1 slist概述
			4.9.2 slist的节点
			4.9.3 slist的迭代器	
			4.9.4 slist的数据结构
			4.9.5 slist的元素操作
		5.1 树的导览
			5.1.1 二叉搜索树
			5.1.2 平衡二叉搜索树
			5.1.3 AVL tree
			5.1.4 单旋转
			5.1.5 双旋转
		5.2 RB－tree（红黑树）
			5.2.1 插入节点
			5.2.2 一个由上而下的程序
			5.2.3 RB－tree的节点设计 
			5.2.4 RB－tree的迭代器 
			5.2.5 RB－tree的数据结构 	
			5.2.6 RB－tree的构造与内存管理 	
			5.2.7 RB－tree的元素操作 	
		5.3 set	
		5.4 map	
		5.5 multiset	
		5.6 multimap
		5.7 hashtable	
			5.7.1 hashtable概述 	
				线性探测（linear probing）	
				二次探测（quadratic probing）	
				开链（separate chaining）	
			5.7.2 hashtable的桶子（buckets）与节点（nodes） 	
			5.7.3 hashtable的迭代器 	
			5.7.4 hashtable的数据结构 
			5.7.5 hashtable的构造与内存管理 	
				插入操作（insert）与表格重整（resize）	
				判知元素的落脚处（bkt_num）	
				复制（copy_from）和整体删除（clear）	
			5.7.6 hashtable运用实例 	
			5.7.7 hash functions 	
		5.8 hash_set	
		5.9 hash_map	
		5.10 hash_multiset	
		5.11 hash_multimap	
		6.1 算法概观	
			6.1.1 算法分析与复杂度表示O()
	
			6.1.2 STL算法总览 	
			6.1.3 质变算法mutating algorithms——会改变操作对象之值 	
			6.1.4 非质变算法nonmutating algorithms——不改变操作对象之值 	
			6.1.5 STL算法的一般形式 	
		6.2 算法的泛化过程	
		6.3 数值算法<stl_numeric.h>	
			6.3.1 运用实例 	
			6.3.2 accumulate 
			6.3.3 adjacent_difference 
			6.3.4 inner_product 
			6.3.5 partial_sum 	
			6.3.6 power 	
			6.3.7 itoa 	
		6.4 基本算法<stl_algobase.h>	
			6.4.1 运用实例 	
			6.4.2 equal, fill, fill_n, iter_swap, lexicographical_compare,max,min,mismatch,swap
			6.4.3 copy——强化效率无所不用其极 
			6.4.4 copy_backward 	
		6.5 Set相关算法	
			6.5.1 set_union 	
			6.5.2 set_intersection 	
			6.5.3 set_difference 	
			6.5.4 set_symmetric_difference 	
		6.6 heap算法	
		6.7 其它算法	
			6.7.1 单纯的数据处理 	
			6.7.2 lower_bound(应用于有序区间)	
			6.7.3 upper_bound（应用于有序区间） 	
			6.7.4 binary_search(应用于有序区间)	
			6.7.5 next_permutation 	
			6.7.6 prev_permutation 	
			6.7.7 random_shuffle 	
			6.7.8 partial_sort／partial_sort_copy 	
			6.7.9 sort 	
			6.7.10 equal_range(应用于有序区间)	
			6.7.11 inplace_merge(应用于有序区间)	
			6.7.12 nth_element 	
			6.7.13 merge sort 	
		7.1 仿函数(functor)概观446	
		7.2 可配接(adaptable)的关键448	
			7.2.1 unary_function 	
			7.2.2 binary_function 	
		7.3 算术类(Arithmetic)仿函数451	
		7.4 关系运算类(Relational)仿函数453	
		7.5 逻辑运算类(Logical)仿函数455	
		7.6 证同(identity)、选择(select)、投射(project)456	
		8.1 配接器之概观与分类	
			8.1.1 应用于容器，container adapters 	
			8.1.2 应用于迭代器，iterator adapters 	
			8.1.3 应用于仿函数，functor adapters 	
		8.2 container adapters	
			8.2.1 stack 	
			8.2.2 queue 	
		8.3 iterator adapters	
			8.3.1 insert iterators 	
			8.3.2 reverse iterators 	
			8.3.3 stream iterators 	
		8.4 function adapters	
			8.4.1 对返回值进行逻辑否定：not1，not2 	
			8.4.2 对参数进行绑定：bindlst，bind2nd 
			8.4.3 用于函数合成：compose1，compose2 
			8.4.4 用于函数指针：ptr_fun 	
			8.4.5 用于成员函数指针：mem_fun，mem_fun_ref
		附录A 参考书籍与推荐读物(Bibliography)
		附录B 侯捷网站(本书支持站点简介)
		附录C STLPort的移植经验(by 孟岩)
			Borland C++Builder5
			Microsoft Visual C++6.0
		索引
