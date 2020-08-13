# c++

### C++存在整数除法

5/4=1

### 自动类型转换

#### 赋值

int a = 3.135 √

double 给 float 精度降低，如果超出范围，结果未定义

float 给 int 取整 ， 如果超出范围 结果未定义

long 给 short 通常只复制右边的字节

#### 列表初始化

更严格

不允许缩窄

可以接受“缩窄”常数

不接受缩窄变量

#### 表达式中：

加法自动提升到 int

##### 顺序

1. long double
2. double
3. float
4. 整型提升
5. 如果有无符号相同： 转换为更高级的 否则：
6.
7. 无符号等级高：有符号的转换为无符号
8. 有符号表示出无符号所有值： 无符号转换为有符号
9. 否则： 有符号的无符号版本

#### 传参

提升

# 第 4 章

### 数组

#### 列表初始化

int x[3] = {0} 所有都会成为 0

当列表数量较少时，剩下全部自动变成 0

可以省略等号

不包含任何东西： 全是 0

#### 数组不能直接互相赋值

#### 字符串初始化

char x[] = {"123"} ×

char x[] = "123" √

#### 读入对比

- cin 忽略前方空白 看到不符合规定的地方或者空白停止 不丢弃后方空白
- cin.get 到回车停止 不忽略也不丢弃 如果是空行的话设置 fail， 超出界限不会设置
- cin.getlind 到回车停止，丢弃回车 如果是空行的话不设置 fail，结果是“”，如果什么都没有的话 fail， 超出界限会设置
- cin.get() 读取下一个任意字符

cin.getline(x,`100).getline(y,100) √

#### 字符串可以列表初始化

#### 其他字面值

L u U

R"(内容)"

也可以在” 和 （中间插入其他东西

R"abc(内容)abc“

### 结构

#### 结构的列表初始化

按顺序 如空，则全是 0 不能缩窄

#### 赋值

成员各自赋值

#### 位字段

unsigned int SN : 4; 四位

unsigned int : 4 空四位

#### union

```c++
union name
{
    int x;
    int y;
}
```

struct 匿名共用体可以直接访问内部，否则要多一层

```c++
struct t
{
    union
    {
        int x;
        long y;
    }
}
t.x
```

#### enum

```c++
enum t {first =3,second =9};
```

#### 限制

只能用枚举常量赋值

可以整型提升

#### 数字

没有赋值的比前面大一

#### 强制转换

可以进行范围内的赋值（2 的幂上下界，不小于 0 的话取 0）可以不是列举出的之一

### 指针

```c++
int* x,y;
x: int*
y: int
x= new int[20]{};
```

#### 类型转换

不能直接用 int 赋值

#### delete

delete null 是安全的

#### 数组名和指针

|                   数组名                   |                 指针                 |
| :----------------------------------------: | :----------------------------------: |
|                    常量                    |                 变量                 |
|             sizeof 得到总长度              |         sizeof 得到基类长度          |
| &数组名得到整个数组地址，+1 加整个数组长度 | &指针得到指针地址，+1 加的是基类长度 |

#### 结合顺序

先和[]在和\*

#### 字符串常量被解释为地址 最好用 const 指针指着 或者 strcpy 保证不改变

#### 长度不要忘记加一

#### 越界： 都有可能越界

可以用.at 来安全的获取

#### 字符数组初始化

```c++
char x[]="abcd";
char x [] = {"abcd"};
//char*x = "abcd";
//char* x = {"abcd"};
const char * x = "abcd";
char * x = new char [20] {"abcd"};
```



# 第5章

### For

```c++
for (for-init-statement condition; expression)
```

#### 表达式

不能是declearation

不能是for while 等

#### 顺序点

完整表达式是顺序点

完整表达式：不是更大的表达式的一部分

逗号也是顺序点

一个顺序点对于每一个变量最多修改一次，否则未定义行为

#### 前置快于后置

后置需要复制副本

#### 运算优先级

前置++ 前置--  * （从右向左）同级，低于

后置++ 后置--（从左向右）

#### 逗号

优先级最低，值是右边的

#### 关系表达式

关系运算低于数学运算

#### 延时

```c++
#include <ctime>
clock_t systemUnit = second * CLOCKS_PER_SEC;
clock_t start = clock()
```



#### typedefine

#### Do While 

主要用于读入

#### range based for

注意要不要用引用格式

#### 输入输出

##### cin 永远读不到空白

#### cin.get

1. char = cin.get() 获取下一个字符 eof时，char里面是eof
2. cin.get(char) 获取下个字符，eof时，char什么都没有
3. cin.get(char[], size) 获取一行

#### 套路

```c++
while (cin>>x[i++]); i--;
while (cin.get(char[i++])); i--;
while ((char[i++]=cin.get())!=EOF); i--;
```

# 第6章

#### 右值放左边

#### || && ： 也是顺序点

#### 短路优秀

#### cctype 提供字符判断函数

#### goto

```c++
goto label;
label: int x;
```

#### 错误处理

```c++
while (!(cin>>x))
{
    cin.clear();
    while (cin.get()|= '\n');
}
```

#### fstream

和iostream 几乎一样， 包括setf

```c++
ifstream inFile;
inFile.open ("a.txt");
if (!inFile.is_open()){
    exit(1);
}
while (inFile >> x);
if (inFile.eof())
    //结束
else if (inFile.fail())
    //不匹配的输入
else 
    //其他
```

# 第7章

### const

```c++
    int *const p = new int{10};    
	int *const *t2 = &p;
```

t2是指向可变的某一个（指向某一个不变的位置的可变整数的指针）指针

上面有的const一个不能少

下面多出来的const必须从const到倒数第二个不间断才能赋值

### 有关宏定义的comment

宏定义整数不一定被解释为整数，也就是说，并未定死数据类型，在函数匹配中可被认为long， void * int* 等等

函数指针

```c++
double (*pf) (int);
double func (int);
pf= func;
double y = pf(8);
double y = (*pf)(8)
```

把右边（）看作运算符

pf(int) : 如果给pf一个int参数，那么返回前面的

pf[3]: pf 是一个数组，其中每一个是

*pf 对pf解除引用后是，也就是说，pf是指向（）的指针



# 第8章

### 内联函数

在定义或者声明加上inline

好于define

