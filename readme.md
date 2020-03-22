### C++

### 基础

1.拷贝函数

```java
classname (const classname &obj) {
   // 构造函数的主体
}
```

A x(2);　　//直接初始化，调用构造函数
A y = x;　　//拷贝初始化，调用拷贝构造函数


发生的场景

Line line(10);

test(line);

执行test函数时 传入行参line

1.会先生成临时变量 C

2.调用拷贝函数把line的值给C

3.等test执行完析构掉C对象






#### 概念

C++ 类构造函数 & 析构函数 :Main.cpp
在 C++ 里，所有的变量缺省都是值语义 不像java里是引用 例如Obj obj在c++指向堆 在java指向栈


智能指针

动态内存管理缺点
一种是忘记释放内存，会造成内存泄漏
一种是尚有指针引用内存的情况下就释放了内存，就会产生引用非法内存的指针。

所以需要形成一套 先释放引用再释放内存的机制
智能指针的行为类似常规指针，重要的区别是它负责自动释放所指向的对象
也就是在指针对象析构的地方释放内存


#### 语法
explict 只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式(implicit)


#### 内存区域

Java中内存区域划分有堆,本地方法栈,虚拟机栈,方法区,PC程序计数器

C++中
内存栈区
函数调用过程中 本地变量和调用数据的存放区域 后进先出
内存堆区
动态分配的内存 malloc 需要手动释放否则内存泄漏
自由存储区(free store)：堆的一个子集 内存通过new和free进行申请和释放
常数区
静态区
代码区


堆中内存分配

1.内存管理器分配一个内存块 malloc new
2.内存管理器释放一个内存块 free  delete
3.内存管理器进行垃圾回收 找到不用的内存块释放 并合并为连续的



栈中内存分配
1.从高地址到低地址进行分配
2.调用函数的过程-》参数压栈-》返回函数的地址压入-》（跳转新的函数）-》寄存器保留空间-》参数入栈-》执行完毕
一个函数执行完毕 会返回到执行这个函数的未执行代码中继续珍惜
3.分配和释放只需要移动栈的指针 不会出现内存碎片 即用即走
4.每个函数所占用的栈空间为栈帧fomit-frame-pointer...


 display(line1); 这段代码在执行结束后line1这个对象 会被调用析构函数 当int main主程序结束后也会调用一次




RAII
C++特有的资源管理方式
依托栈和析构函数
来对所有的资源进行管理
使得 C++ 不需要类似于 Java 那样的垃圾收集方法，也能有效地对内存进行管理



接收指针在外层函数结束时回收指针

int main(){
 shape_wrapper wrapper(*ptr);
}
在main函数结束时释放  利用了栈和析构


class shape_wrapper{
public:
    explicit shape_wrapper( shape* ptr = nullptr) : ptr_(ptr) {}

    ~shape_wrapper(){
        delete ptr_;
    }

    //const like java final cannot modify
    shape* get() const {
        return ptr_;
    }
private:
    shape* ptr_;
};