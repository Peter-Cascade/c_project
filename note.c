/*20260928
1.declaration: contents
defination: content
.h: the book of content*/

/*20260929
1925-2135
1.there are 4 deffrent kinds of memory in c:
#### ① 代码段（Text Segment）—— 大楼的“印刷图纸”
*   **存什么**：你写的所有函数（包括 `main`）编译后的机器指令。
*   **特点**：**只读**。程序跑起来后，这个区域的内容不能改。如果有人试图通过指针改写代码段的内容，程序会立刻崩溃（Segmentation fault）。
*   **对应**：你之前困惑的“函数定义”，就住在这里。

#### ② 数据段（Data Segment）—— 大楼的“永久储物柜”
*   **存什么**：**全局变量**和**静态变量**。
*   **细分**：
    *   **`.data`区**：已经初始化的全局变量（比如 `int a = 10;`）。
    *   **`.bss`区**：未初始化的全局变量（比如 `int b;`）。程序启动时，操作系统会把这部分清 0。
*   **特点**：程序启动时分配，程序退出时销毁。生命周期贯穿整个程序。

#### ③ 堆（Heap）—— 大楼的“公共租赁仓库”
*   **存什么**：你手动通过 `malloc` / `free` 申请和释放的内存。
*   **特点**：**由程序员全权负责**。它极其灵活，想用多少申请多少，但用完后必须手动归还（`free`）。如果只借不还，就是“内存泄漏”（Memory Leak）。
*   **生长方向**：从低地址向高地址生长。
*   **对应**：Python 里的对象和变量，其实都存在堆里，只不过 Python 有垃圾回收器（GC）自动帮你 `free` 了。

#### ④ 栈（Stack）—— 大楼的“临时餐桌”
*   **存什么**：**局部变量**、**函数参数**、**函数返回地址**。
*   **特点**：**由编译器自动管理**。你调用一个函数，系统就会在栈上给它分配一块“栈帧”（Stack Frame）；函数执行完 `return`，系统立刻把它销毁。
*   **生长方向**：从高地址向低地址生长（与堆相反）。
*   **特点**：空间较小（通常几 MB），如果递归太深或局部数组太大，会“栈溢出”（Stack Overflow）。
*   **对应**：你在 `main` 里写的 `int result = 0;`，这个 `result` 就住在栈上。


2.想象内存是一个巨大的酒店：
内存地址（Address）：酒店走廊上的房间号（比如 0x5FFE68）。
变量名（Variable Name）：你给房间起的一个别名（比如“堆_ptr”）。
值（Value）：房间里实际住的客人（比如 50）。
类型（Type）：房间的类型（单人间叫 int，双人间叫 double）。类型决定了房间里能住什么人，占用多大空间。

在 Python 里，一切都是对象（客人），变量名只是贴在客人身上的标签。
在 C 里，变量就是房间本身。 写 int local_var = 10;，就是盖了一个叫 local_var 的单人间，房间号是 0x5FFE74，里面住了个数字 10。

指针也是变量，指针变量。
一般变量（存储）的值都是具体的，比如50，100，而指针变量存储的是一个内存地址，相当于一个中转站，进行二次引用从而欺骗编译器。

malloc申请的的无名房间只能通过指针访问

3.对指针的进一步理解：
我们可以用“酒店房间”的比喻来把编译器、指针、内存这三者的关系彻底理顺：

普通变量 int a = 10;

你告诉酒店经理（编译器）：“给我开个房间，名字叫 a，里面住客人的数字是 10。”

经理照做，给你分配了房间 0x5FFE74，里面放了 10。

你每次叫 a，经理就直接去 0x5FFE74 房间把 10 拿出来。

指针变量 int *p = &a;

你告诉经理：“给我开个房间，名字叫 p。这个房间不注人，专门放另一个房间的钥匙（地址）。”

经理看了看 &a（也就是 0x5FFE74），确认这是一把 int 类型的钥匙，就把它放进了 p 房间里（p 的值变成了 0x5FFE74）。

二次引用 *p（解引用）

你告诉经理：“去 p 房间里，把里面的钥匙拿出来，打开对应的房间，把里面的数字换成 99。”

经理（编译器）完全知道你在干什么，它生成了指令：“先找到 p 的地址，读出里面的值作为新地址，然后去这个新地址写入 99。”

这就是你所说的“中转站”和“二次引用”。

4. C 是“房间”模型，所以在 C 里，赋值（=）永远是“拷贝值”，而不是“贴标签”。

5.为什么 C 语言要设计成“纯粹命令式”？
回到你刚才看的书中作者的观点：“为了让编译尽可能简单”。这就解释了 C 语言的设计初衷：

C 语言是一门“可移植的汇编语言”。

它不提供任何“魔法”，不帮你做垃圾回收，不帮你做闭包捕获，不帮你做类型动态推断。它要求你每一步都必须有明确的物理含义。只有这样，它才能在没有操作系统的裸机（Bare Metal）上运行，才能写出 Linux 内核和 6.S081 的 xv6。

6.In style, C is a procedural or imperative language, not an object-oriented 
or functional one.
*/

/*
20260930
1020-1200
1.printf 是 C 语言里一个非常特殊的函数（叫做变参函数）。它极其“傻瓜”，它甚至不知道你传进来的参数是什么类型。
printf 的第一个参数是一个字符串（格式化模板），里面带着 %s、%d、%p 等占位符。printf 完全靠这些占位符来决定下一步怎么做。

2.你说：“指针变量存储的内存地址里存储的数据类型是 char”。
这句话不准确。准确的说法是：

指针变量 msg（在栈上，占 8 字节）里存储的，是一个纯数字的地址（比如 0x404000）。这个地址本身没有“类型”。

这个类型 char* 是写给编译器看的“操作说明书”，它包含两层含义：

读多少：当以后你写 *msg（解引用）时，编译器知道去那个地址只读 1 个字节，并按 char 解释。

走多远（指针算术）：当你写 msg + 1 时，编译器知道地址加 1 字节，正好指向下一个字符。

打个比方：
你把一张写着“某某小区 5 号楼 302 室”的纸条（指针）放进你的口袋里（栈变量）。这张纸条上只有地址，没有说 302 室里住的是谁。
char* 这个声明，就像是你手里的说明书，告诉编译器：“302 室里住的是一个单字节的字符”。
如果你写 int* p，说明书就变成了“302 室里住的是一个 4 字节的整数”。当你 *p 时，编译器就会一口气从 302 室读走 4 个字节。

所以，指针类型不是指“地址里存了什么类型的数据”，而是指“当你去那个地址取数据时，该怎么操作”。

*/

/*
20261001
1648-2048
1.#include "helper.h"：这里用双引号。为什么不用尖括号 < >？

< > 告诉编译器去系统目录找（比如 stdio.h）。

" " 告诉编译器去当前项目目录找。*/


/*
20261002
1010-1210
1547-
1.if (n < k)
 puts("if");
else if (r > k)
 puts("else if"); 
else
 puts("else");
In this example, the body of the if, the else if, and the else is a 
single statement; hence, braces are not needed. The bodies are indented 
for readability, but indentation has no impact on flow of control. If a body 
has more than one statement, the body must be enclosed in braces:
if (n < k) { 
 puts("if");
 puts("just demoing");
 Using braces to enclose even a single body statement is admirable 
but rare.

2.光看文字不够，建议你在 C 代码里用 GDB 体会一下什么是“跳转（goto）”：

编译并在 switch 这一行打个断点。

按 n 单步执行。

你会看到，程序没有一行行去看 case 1、case 2，而是直接跳进了匹配的 case 标签里。

只要没遇到 break，它就会顺着往下单步执行。

switch 不是“判断”，而是“跳转”。

case 只是跳转的“目标路标”，一旦到达，路标就失效了。

剩下的路程，“全靠 break 刹车”。没有 break，就会一路“贯穿（fall-through）”。

记住一个铁律：以后写 C 语言的 switch，95% 的情况下，你必须在每一个 case 结尾加上 break;，除非你是故意要让它贯穿。


3.&称为取地址符，我把它叫做编码符，与*解码相反

4.    // 永远要检查 scanf 的返回值！
    // 它返回成功读取到的变量个数。如果用户输入了字母，它返回 0 或 1。

5.圆括号 ()：用于“包裹”和“调用”

函数调用：printf(...)、add(10, 20)。
控制流条件：if (x > 0)、while (i < 5)。
函数参数：int add(int a, int b)。
改变优先级：(a + b) * c。
一句话：圆括号决定了“程序先做什么动作，以及动作的参数是什么”。
花括号 {}：用于“划定边界”和“打包”

代码块（作用域）：if (...) { ... }、while (...) { ... }、函数的定义 int main() { ... }。它们把一堆语句打包成一个整体。
初始化列表：int arr[3] = {1, 2, 3};、struct Point p = {10, 20};。
一句话：花括号就是“一栋房子”，里面装着属于它的东西。

6.A cast is not an assignment: in the second example shown previously, the cast 
(float) does not change what is stored in n but rather creates a new value 
then assigned to variable f.

7.老手技巧：把常量写在左边（Yoda 写法）
因为 5 = a 是给常量赋值，C 编译器必然报错，立刻发现问题。这种写法叫 Yoda 条件式（像尤达大师说话"五个是 a"），在 Linux 内核等大量项目中广泛使用。
8.
Bit（位）​
最小单位，0 或 1，8 个 bit = 1 byte
Byte（字节）​
8 bit，内存/存储的基本寻址单位
字符​
信息的逻辑单位，一个字、一个字母
字符集​
字符到编号的映射表（如 Unicode 收录了哪些字符）
编码​
编号到二进制的转换规则（如 UTF-8、GBK）
*/

/*
20261003
0900-1200
1645-
1.在 Python 里，arr = [1,2,3] 时，arr 是一个标签，指向堆里的列表对象。你可以随时让 arr = "hello" 改变它的指向。
但在 C 语言里，int arr[8]; 做了两件事：
在栈上分配了 8 个连续的格子。
把 arr 这个名字，直接绑定到了这 8 个格子的“第一个格子的地址”上。
什么是“指针常量（Pointer Constant）”？
常量：意味着 arr 的值是不能被修改的。你绝不能写 arr = some_other_address;。它生是这块内存的人，死是这块内存的鬼。
指针：意味着 arr 本质上是一个地址（钥匙）。arr 等同于 &arr[0]（第一个元素的地址）。

2.核心规则：指针 +1 = 跳过一整个元素
&arr[0] + 1
int*（指向 int）
往后跳一个 int（4 字节），指向 arr[1]

3.对比：指针变量 int *p vs 数组名 int arr[8]

p 是在栈上单独分配了一个 8 字节的房间，里面放了一把钥匙。

arr 本身没有独立的房间，它就是这个连续内存块开头的别名。

4.“数组即指针”这句话是 C 语言初学者最大的噩梦。更准确、更严谨的说法是：
“数组名在大多数表达式中，会自动退化为指向其首元素的指针。”（Array decays to a pointer to its first element）
因为 C 语言规定，arr[i] 这种写法，在底层被编译器翻译成 *(arr + i)。

arr 被当成地址（首地址）。
arr + i 是指针算术（地址加 i * sizeof(int)）。
*(arr + i) 解引用，取出那个格子里的值。
所以，你平时写 arr[3]，编译器眼里就是 *(arr + 3)。正因为这种底层实现，很多人说“数组就是指针”。

5.int* 里的 int 只说明一件事："我指向的是一个 int"——它描述的是"指针指向什么"，而不是"指针自己是什么类型"。

6.c has no bounds chech for array.

7.In the declaration of ptr, the star comes after the data type int. In the 
dereferencing of ptr, the star comes before the variable’s name. It would be 
an error to change the code to
ptr = k; 
because ptr then would take on values such as 1,2,3,…,8, which almost 
surely are not addresses within the program’s address space. The aim is to 
initialize the array element to which ptr points, not ptr itself.

8.面临的挑战：
一个函数 return 只能返回一个值。但这个 safe_mult 函数需要返回两个信息：

乘法结果（比如 768）

是否发生溢出（0 或 1）

C 语言的解决方案：指针作为“输出参数”
你无法用 return 返回两个值，但你可以用指针参数来“假装”返回第二个值。
“参数 product 指向了乘法结果应该被存放的位置。这个指针参数，是调用者（caller）在 main 函数中声明的一个变量的地址。”

9.数组很多时候可以当成指向0号元素的指针，与arr[0]相同。因此也称为指针数组。
arr[i]就是指向其i号元素的指针。根据元素类型，可能是char*, int*，但是与数组定义时一致。也就是说，同一个数组内各个元素类型相同。
字符串在 C 里就是指针，而整数不是。
int arr1 = {1, 2, 3}
char* arr2 = {"qwr", "qrfg", 0}
in printf, different symbols with % are no just a mark to fill in. 
%s will use the address the paremeter point to, which is the address of the first element in a string or int,
going down the next address, and decode the address one by one and print them, until meeting 0.
%c mean the paremeter only point to a single byte, so there is no need to go down further. 
But we need to tell printf that there is indeed only one byte, so we need to input arr[0][0](or one element intended)
%p work


10.数组名退化成指针指向数组0号元素，用&加码后是自己所在的内存地址，不是指向的
*/

/*
20261004
0930-1200
1540-1700
1730-2130
1.写法	含义
int (*compar)(...)	compar 是指向函数的指针​
int *compar(...)	compar 是一个函数，返回 int*​

2.你说的：
传一个指向能返回 int 的函数的函数指针，这个函数要接收两个指针作为参数。
✅ 完全正确。​ 更精确的表述是：
传一个函数指针，它指向的函数接收两个 const void* 参数、返回 int。

3.int comp_ascd(const void* p1, const void* p2) {
    int x = *(const int*)p1;
    int y = *(const int*)p2;
    return (x > y) - (x < y);   // 永不会溢出，恒返回 -1/0/1
}
    原理：x > y 是 1 或 0，x < y 是 1 或 0，三个组合正好是 1、0、-1。

3.C 语言里，数组作为参数传递时，永远会丢失长度信息。你不能在函数里计算长度，必须在数组退化为指针之前算好。

4.xxx* p: p is a pointer point to xxx. xxx can be a data type or a struct etc.
*/

/*
20261005
1000-1200
1530-1920
2000-
1.栈帧在return 后会被销毁但是堆不会，如果想返回指向函数内部的指针，（比如在内部建立了一个buffer[64]
不可以直接return，否则拿到的是空指针。
需要在函数内部先malloc，再返回。但是就需要手动free

2.在 get_name1(char buffer[], ...) 的眼里，这两个东西都是 char* 指针。所以编译器觉得类型匹配，放行了。

但 char buffer[BuffSize + 1] 是在栈上真实开辟了 129 个字节的房间，buffer 是这栋房子的首地址。

而 char* buffer; 仅仅声明了一把没有指向任何地方的钥匙（野指针）。你没有给它分配任何存放字符的空间。

当 get_name1 内部用 strncpy 试图往这把未知的钥匙指向的地方写 128 个字节时，操作系统立刻击毙你的程序（Segmentation fault）。

3.如果第二层分配失败（heap_struct->heap_nums == NULL），
必须先把第一层分配的结构体 free 掉！ (free(heap_struct); return NULL;)。如果不写这个 free，结构体内存就泄漏了。

4.name 是一个指针（const char*），在 64 位系统下，sizeof(name) 的结果是 8（指针的大小），而不是字符串的长度。

*/

/*
20261006
0945-
1.你的 C 程序运行在“用户态”。在这个状态下，你的程序没有权限直接操作键盘、屏幕、硬盘这些硬件。
如果你想去读键盘、往屏幕上写字，你必须向操作系统内核（Kernel）申请。
这个申请的过程，就叫 系统调用（System Call）。read 和 write 就是 Linux 系统内核提供给我们的两个最基础的“办事窗口”。

2.Like many of the low-level I/O functions, read returns an int value: 
the number of bytes read, on success, and -1, on error.

3.read: read input from keyboard and put it in to memory
write: write the data from respect memory to the screen

4.main 函数的 return（返回给操作系统）
标准：return 0; 代表成功，非零代表失败
系统调用 / C 标准库函数的 return（返回给调用它的 C 代码）
标准：成功时返回非负值（0 或正数），失败时返回 -1。

5.操作系统把控制开关分配给了不同的二进制位（Bit）：

O_RDONLY = 0x0001 (位0)

O_WRONLY = 0x0002 (位1)

O_RDWR = 0x0004 (位2)

O_CREAT = 0x0040 (位6)

因为它们占用的是不同的位，所以：
O_RDWR | O_CREAT 展开二进制就是 0000 0100 | 0100 0000 = 0100 0100。
这正好等于 0x04 + 0x40 = 0x44。没有发生二进制进位（1+1=0并进1），所以按位或的结果，在数学上恰好等同于加法。

这就像是一个由 0 和 1 构成的“背包”：每加入一个选项，就在对应的口袋里放一个 1。最终得到的那个整数 0x44，完美记录了哪些口袋里有 1。

6.书里的示例代码做了一个非常理想化的假设：它要求 read 必须一次性读完 20 个字节。但真实的系统编程中，read 是不保证读完的。

系统调用 read(fd, buf, 20) 的含义是：“最多给我读 20 个字节”。
如果磁盘很慢，或者网络卡了，内核可能会说：“我现在只能给你 8 个字节”，然后返回 how_many = 8。
这就是著名的短读（Short Read）问题。

如果你是一个成熟的操作系统工程师，你的代码应该这样写（通过循环反复读取，直到读满或者遇到文件末尾 EOF）


// 这是一个工程师级别的心智模型
#include <stdio.h>
ssize_t total_read = 0;
ssize_t bytes_read;
while (total_read < sizeof(read_in)) {
    bytes_read = read(fd, read_in + total_read, sizeof(read_in) - total_read);
    if (bytes_read < 0) {  /* 处理错误  break; }
    if (bytes_read == 0) {  /* 遇到文件末尾 EOF  break; }
    total_read += bytes_read;
}

7.fd 是 source.txt 在你这次打开会话里的"身份证号"，拿着它内核就知道你想操作谁——但它本身不是文件，只是一把钥匙。
因为操作系统不允许直接绕过，一切必须经过操作系统，不可以直接操作文件

8.在 Unix/Linux 里，不只磁盘文件是文件，连键盘、屏幕、鼠标、串口、网络连接，都被抽象成了"文件描述符"。
程序看到的              内核背后实际对应的
─────────────────       ─────────────────────
fd 0 = stdin    ──→    键盘（终端设备 /dev/tty）
fd 1 = stdout   ──→    屏幕
fd 2 = stderr   ──→    屏幕
fd 3 = fp       ──→    磁盘上的 data.txt
*/