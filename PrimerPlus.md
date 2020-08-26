# c++

[TOC]

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

### 引用

const引用才能创建临时变量

#### 临时变量条件

参数类型正确，不是左值

参数类型不正确，但可以转换

#### 返回引用不能返回被销毁的

#### 返回引用要注意这个可以被赋值

#### 基类引用可以引用派生类

### 格式化输出套路

```c++
ios_base::fmtflags init ;
init = cout.setf(ios_base::fixed);
cout.precision (0);
os.setf(init);
```

### 默认参数

定义在原型中

```c++
int f ( int n, int m=3,int p=0);
```

不能跳过一直到最后

### 函数重载

#### 引用与否不作为特征标 特征标只包括自变量

#### 重载引用

```c++
void f(int &);
void f (int &&);
void f (const int &);
```

如果没有第二个，那么右值会自动到第三个

#### 可以使用默认参数减少重载

### 函数模板

```c++
template <typename T>//or class T
void f (T&a,T&b);
```

#### 函数模板重载

```c++
template <typename T>//or class T
void f (T&a,T&b,int t);
...
template <typename T>//or class T
void f (T&a,T&b,int t){
    
}
```

#### 显式具体化 

```c++
template<>
void f <MyClass> (MyClass &a,MyClass &b);
template<>
void f (MyClass &a,MyClass &b);
...
template<>
void f (MyClass &a,MyClass &b)
{
    
}
```

#### 显式实例化

一般由编译器经行隐式实例化

显式实例化可以要求编译器立刻实例化这个函数

```c++
template void f <int> (int &a ,int &b);
```

意思是立即用原来的模板生成int的版本

显式具体化提供不同的，新的函数实现，而显式实例化只是照着模板生成了一份

代码中也可以显式实例化

```c++
f<int>(a,b);
```



### 重载解析

####  const

const的区别只存在于指针和引用中，否则二义性

#### 更具体的更好

#### 用f<>强制建议使用模板的版本

#### decltype和后置返回类型

通过表达式或者变量推断出类型

```c++
template <typename T>//or class T
auto f (T&a,T&b)-> decltype (a+b);
```

 https://mp.weixin.qq.com/s?__biz=MzI2OTA3NTk3Ng==&mid=2649284296&idx=1&sn=7bbce919d0c7f2f6f62623d7054a8dbc&chksm=f2f9adafc58e24b9db5a46249d0a3364265065e075f0e6066ee0e8a064aefc8c23ab3710a826&scene=21#wechat_redirect 

# 第9章

### 头文件

- 函数原型
- #define 和Const
- 结构声明
- 类声明
- 模板
- 内联函数

 ### extern

声明：

```c++
extern int a;
```

定义：

```c++
extern int b = 0;
int c;
```

想要使用被隐藏的全局：

```c++
:: name
```

#### const 特例

const自动成为static 内部链接性 想要外部需要特别加上extern，另外的变量自动链接性为外部

所以可以放心的把const放在头文件

```c++
//想要外部链接性
extern const int c = 10;
```



### 说明符和限定符

#### mutable

当类或者结构是const时也允许改变

### 函数链接性

默认外部， static 内部

### 语言链接性

通过不同命名标准来寻找函数

```c++
extern "C" void f();
extern "C++" void f ();
//默认C++
```

### 动态存储

#### 小括号初始化 列表初始化

#### new 运算符

```c++
void  * operator new (std::size_t);
void  * operator new[] (std::size_t);
```

#### 定位new运算符

```c++
#include <new>
char * buffer1 =  new char [200];
int * p1= new (buffer1) int[20]; 
```

### 命名空间

using声明类似于变量定义

using编译指令相当于全局变量，使得变量可用，但可以被局部变量隐藏

用声明更好些，因为如果有冲突会提示

using上层也会using所有下层

```c++
namespace anothername = OldNameSpace::InsideSpace
```

未命名的命名空间等效于内部链接性静态变量

using一个重载了的函数将导入所有版本

# 第10章

### 方法只有一个副本，作用在不同对象

### 初始化

```c++
MyClass t = MyClass (1,1,1);
MyClass t (1,1,1);
MyClass t = {1,1,1};
MyClass t {1,1,1};
MyClass t;
MyClass t (); //这是函数，而不是初始化
```

### Const

```c++
void show() const;
void MyClass::show() const{
    
}
```

### 返回的时候注意返回引用或者副本

### 想要创建数组必须要默认构造函数

### 定义const 直接定义即可

```c++
class myclass
{
public:
    int x;
    const int y = 3;
};
```

### 作用域内枚举

```c++
enum class myenum {First,Second=4};
myenum x = myenum:: First;
enum class : short myshortenum { First};//指定为short的底层
```

普通枚举可以隐式转换为整数，但是这种不行

都不能由int隐式转来

# 第11章

### 运算符重载

```c++
total = x+y;
total = x.operator+(y);
Class t{
    public:
    t operator+(const t& v ) const;
}
t t::operator+(const t& v ) const
{
    
}
```

### 友元

不是类函数，和类函数完全无关，只是一个能访问内部变量的常规函数

```c++
Class MyClass {
    friend MyClass operator+ (const MyClass , int);
}
MyClass operator+ (const MyClass t , int x){
    
}//定义中不能使用friend
```

#### cout 套路

```c++
Class MyClass {
    friend ostream& operator<< (ostream& ,const MyClass&);
}
ostream& operator<< (ostream& os,const MyClass& t);{
    os<<t.values;
    return os;
}
```

### 随机数

```c++
#include <cstdlib>
#include <ctime>
std::srand (time(0));
std::rand()% x
```

### 类型转换

#### 从其他转成类

一个参数的构造函数

- 初始化时
- 其他赋给类时
- 其他调用了传递类的参数时
- 试图用其他类型代替类返回时
- 在任何一种情况下，使用可以自动转换的内置类型时（二次转换）

#### 转换到其他类型（转换函数）

```c++
Class MyClass{
    double x;
    operator double();
}
MyClass operator double(){
    return x;
}
```

#### 重点：没有二义性

#### explicit 或者用非成员函数

#### 类函数+， 1000+class 错误

不会自动把1000 转换为class

#### 友元函数更能自动适应类型转换

# 第12章

### 静态类成员

在类中声明

在类方法的文件中初始化

用作用域运算符来指出类（不可访问但是可以初始化）

### 复制构造函数

重点在于构造，造出新的

```c++
MyClass new(old);
MyClass new=old;
MyClass new= MyClass ( old);
MyClass *new = new MyClass(old);
f(old)//not reference
    
MyClass(const MyClass & t){
    num++;
    p=new int  {*(t.p)};
    normalx=t.normalx;
}
```

//TODO 样例 见effective

### 赋值运算符

```c++
MyClass& operator= (const MyClass & t){
    if &t == this then
        return *this;
    else {
        delete p;
    	p=new int {*(t.p)};
        return *this
    }
         
}
```

### 比较函数 

做成友元函数更加适合自动类型转换

### 静态成员函数

只能访问静态属性

### []

```c++
char& operator [] (int i){
    return str[i];
}
const char& operator [] (int i) const{
    return str[i];
}
```

### 没有默认的==运算符



### 返回非const：

operator =

operator <<

### 定位new

要手动调用析构函数

按照创建的反向顺序调用，完成后再delete buffer

### 嵌套类

如果是private那么只有通过类访问，如果public，可以通过作用域解析运算符访问

### 成员初始化列表

# 第13章

### 子类初始化

列表初始化调用基类的初始化，如果省略，调用默认

### 定义放一起，分开实现

### vitual 只用于原型

### 只要希望会被用于继承就要考虑使用虚析构函数

### 利用引用或者指针避免派生类被截断成基类

### 友元函数不能是虚函数，可以让友元函数使用类函数

### 重新定义同名的重载会覆盖所有基类的同名方法允许返回类型协变

### 重载的时候需要重新定义每一个版本，仅仅调用基类的即可

### 子类自动调用基类的赋值复制析构

```c++
next::next(const next& t): base (t)
{
    //new and copy
}
next& next::operator=(const next & t){
    if (this=&rs){
        return *this;
    }
    base::operator=(t);
    delete;
    new;
    copy;
    return *this;
}
```

### 子类友元函数使用基类友元函数

强制类型转换

友元函数不能继承

# 第14章

### 列表初始化 先声明的先构造

### 包含和私有继承的区别

包含提供名了名的成员，私有未命名

包含初始化用成员名，私有用类名

### 访问基类对象

强制类型转换

### 需要私有继承：

访问protected

重定义虚函数

### using重定义访问权限

```c++
using base::functionName;// 导入所有同名函数，只要函数名
```

### 多重继承

#### vitual 写在两个派生的继承那里

#### 需要对每个类写public

#### 初始化

需要调用基类，派生1和派生2的构造函数， 派生类的构造不会传递给基类

而普通的派生类只能调用上面一级的构造函数。

#### 用域解析来声明使用的是哪里的的函数

#### 使用模块化的返回值，而不是递增式的

#### 优先于的判定

如果冲突的名字处在一条继承链， 派生优于基类，如果不在一条链上， 相等。

如果存在最优，则可以不使用限定名

## 类模板

```c++
template<typename T>
class MyClass
{
  T function(T x);
  bool inlinefinction (int x){
      return true
  }
};

template <typename T>
T MyClass<T>::function(T x){
    
}
```

### 全部放在头文件中

### 类内可以省略 Type类外部返回值不能省略

### 非类型模板

可以使用整数枚举引用指针

不能改变参数的值也不能取地址

### 可以使用默认参数

```c++
template <typename T1,typename T2=int>
class MyClass{
    
};
```

### 具体化和实例化

#### 一般都是隐式实例化

####  显式实例化

```c++
template class Array<string,100>;
```

在模板的命名空间内

#### 显式具体化

```c++
template <> class MyClass<int,int>
{
    
}
```

#### 部分具体化

```c++
template <typename T1,typename T2> class MyClass{};
template <typename T1> class MyClass <T1,int>{};
template <typename T1*,typename T2> class MyClass{};
```

### 模板类中可以嵌套模板类

### 模板可以包含本身就是模板的参数

```c++
template <template <typename T> class TempT> class Crab
{
    TempT<int>x;
}
Crab<Stack> t;
```

### 混用

```c++
template <template <typename T> class TempT,typename T1,typename T2> class Crab
{
    TempT<int>x;
}
```

### 友元函数

#### 非模板友元

```c++
friend void counts();
```

这个是所有模板的友元函数

不能用hasFriend&

```c++
template <class T>
class HasFriend
{
    friend void report (HasFriend<T>&)
}
```

report 本身不是模板函数，只是一个以这个类型为输入的普通函数

需要对每一个具体化都写一份

```c++
void report (HasFriend<int> t){
    
}
void report (HasFriend<double> t){
    
}
```



#### 约束友元

类定义前声明每个函数的模板

```c++
template <typename T> void counts();
template <typename T> void report(T&);
```

函数中再次将模板声明为友元

```c++
template<typename T>
class HasFriend
{
    friend void counts<T>();
    friend void report<>(HasFriend<T>&);
    //friend void report<HasFriend<T>>(HasFriend<T>&);
}
```

调用时由于是友元函数，count不能推断出T是什么，所以要显式的指出，而report不用

#### 非约束友元

```c++
template<typename T>
class HasFriend
{
    template<typename C,typename D>
    friend void report(C&,D);
}
```



#### 区别

约束：int属于int类，各自获得一个具体化

非约束：每个具体化都是每个类具体化的友元

### 别名

```c++
using anothername=oldname;
typedef anothername=oldname;
template <typename T>
	using arrtype=std::array<T,12>;
arrtype<int> t;
```



# 第15章

## 友元

### 友元类

```c++
friend class Remote
```

可以放在任何地方

### 友元成员函数

可以仅仅使得一部分函数是类的友元

#### 前向声明

```c++
class Tv;

class Remote{
	//函数声明
}
class Tv{
    friend void Remote::function(Tv&,int);
    //声明和定义
}
inline void  Remote::function(Tv& t,int c){
    
}
```

1. 类型声明，定义所有要用到的类名称
2. 函数声明，定义所有属性
3. 内联函数定义

### 共同的友元

把函数同时写在两个类中作为friend

### 嵌套类

嵌套类写在public可以通过域解析访问

### 可以在模板类中正常的用嵌套类

## 异常

### abort

```c++
#include <cstdlib>
std::abort()
```

向std::cerr发送异常终止 不一定刷新文件缓冲区

exit 刷新缓冲区，不显示消息

### try catch

```c++
try
{
    
}
catch(char*){
    
}
```

### throw 和 return

return 向上一层， throw一直到能处理为止

### 传递的都是副本，但必须用引用接收

### 按照排列顺序匹配

catch(...){}

### exception 头文件

定义了exception类

#### stdexcept

- logic_error;

  - domain_error；
  - invalid_argument;
  - length_error;
  - out_of_range;

- runtime_error;
  - range_error;
  - overflow_error;
  - underflow_error;

#### new

bad_alloc

有些编译器可以提供返回空指针的new

```c++
new(std::nothrow) int;
new(std::nowthrow) int[];
```

#### set_terminate

写在main里面，替换没被处理时调用的terminate函数

#### 异常规范已经弃用

#### 小心那些指针

## RTTI

只能用于包含虚函数的类

### dynamic_cast

```c++
Base *p= dynamic_cast<Base *> (pp);
```

成功则为指针，失败空

可以向下转换

### typeid

对于(*空指针)，返回bad_typeid

```c++
typeid(x1)==typeid(*p)
```

### type_info

 ## 类型转换

### dynamic_cast

### const_cast

```c++
const High * pbar = &bar;
High pb= const_cast <High *> (pbar)
```

但是更改pbar的值会使得结果不确定

### static_cast

当左到右或者右到左时隐式的即可转换

允许不安全的转换

允许向上向下

### reinterpret_cast

重新解释这块数据

# 第16章

## String

是basic_string<char> 即模板具体化

### 构造函数

```c++
string(const char* s);
string(size_type n,char c);
string(string &);
string();
string(const char * s,size_type n);//即使超过末尾依然会复制
template <typename Iter >
string(Iter begin,Iter end);
string(const string&,size_type pos=0,size_type n = npos);
string(string &&)noexcept;
staring(initializer_list<char>il);
```

### 读入

```c++
cin>>string;//保留
getline(cin,string);//丢弃
getline(cin,string,'s');
```

指定了分界符号之后，换行变成普通字符

### size=length

## 智能指针

```c++
#include<memory>
shared_ptr<Int> t (new int 0);
```

### unique 赋值

当unique来自右值时允许赋值，否则禁止

### 随机打乱函数

```c++
for (int i =0 ; i<n;i++)
{
    Swap(a[i],a[randInt(i,n-1)]);
}
```

### sort

false：位置不正确

#### 全排序

a<b && b<a -> a==b

#### 完整弱排序

不符合上述条件

### 区别前置和后置++

```c++
myclass& myclass::operator++()
{
    //前置
}
myclass myclass::operator++(int)
{
    //后置，不必指定名称
}
```



### 迭代器类型

- 输入迭代器
- 输出迭代器
- 正向迭代器
- 双向迭代器
- 随机访问迭代器

### 适配器

成为一个接口，取代原来迭代器的位置

```c++
#include <iterator>
```

#### ostream_iterator

```c++
ostream_iterator<int,char> out_iter(cout,"separater");
copy(dice.begin(),dice.end(),out_iter);
```

#### istream_iterator

```c++
ostream_iterator<int,char> in_iter(cin);
copy(in_iter,ostream_iterator<int,char>(),dice.begin());
```

#### insert_iterator

```c++
back_insert_iterator<vector<int>> back(dice);//dice是目的地
front_insert_iterator<quene<int>> front(dice);
insert_iterator<vector<int>> normal(dice,dice.begin());
copy(x.begin(),x.end(), back);
```

## 函数对象

包括函数名，函数指针，重载（）的类

```c++
double operator()(double x);
```

- 生成器
- 一元函数
- 二元函数
- 谓词
- 二元谓词

```c++
template <typename T>
class TooBig
{
    private:
    T cutoff;
    public:
    TooBig(const T& t):cutoff(t){};
    bool operator()(const T &v){return v > cutoff;}
};
```

#### 内置函数符

```c++
#include<functional>
```

所有内置运算符都有函数符

### 自适应函数符

携带了表示参数类型和返回类型的typedef

### binder

作用于自适应函数符

```c++
binder1st(f2,2.5) f1;
binder2nd(f2,2.5) f1;
```

## 算法

```c++
#include <algorithm>
#include<numeric>
```

## 其他库

### valarray 实现数学运算

### initializer_list

#### 可以转换，不能隐式缩窄

#### 对于参数数量固定的，可以用初始值的普通构造函数

也可以使用{}的方法而不必用initializer_list

```c++
#include<initializer_list>
double sum(const std::initializer_list& t)
{
    double s=0;
    for (double x : t)
    {
        s+=x;
    }
    return s;
}
```

## 第17章

### iostream自动定义8个类

cout cin cerr clog 以及对应的wchar_t

### void * 

打印地址

### write

允许超过尾部

```c++
cout.write((char*)&val,sizeof(long));
```



### 强制刷新缓冲区

cout<<flush

### 格式化

#### 默认

浮点数显示为6位有效数字，末尾0不显示

如果指数大于等于6或者小于等于-5则用科学计数法，同样6位有效数字

#### 进制

```c++
cout<<dec<<hex<<oct
```

#### 宽度（一次有效）

```c++
cout.width(12);
```

不会截断

#### 填充字符

```c++
cout.fill("*");
```

#### 精度

默认模式：有效数字

定点模式，科学模式： 小数点之后的位数

#### 打印末尾小数点和0

```c++
cout.setf(ios_base::showpoint);
```

#### setf(以下全部省略ios_base::)

##### 一个参数的版本

###### boolalpha

bool类型输出变成true和false

###### showbase

0x00000000

0132  （oct）

###### uppercase

十六进制大写，E也大写

###### showpos

基数为10正数加上+号

##### 两个参数

###### dec/oct/hex + basefield 

###### fixed/scientific + floatfield

###### left/right/internal + adjustfield

internal : 符号和基数左对齐，数字右对齐

#### 定点和科学

显示末尾0

指的是小数位数

#### setf 套路

```c++
ios_base::fmtflags old=cout.setf(...);
cout.setf(old,...)
```

#### unsetf

#### 控制符

- boolalpha
- noboolalpha
- showbase
- showpoint
- showpos
- uppercase
- internal
- left
- right
- dec
- hex
- oct
- fixed
- scientific

#### 扩展的控制符

```c++
#include <iomanip>
```

- setprecision()
- setfill()
- setw()

