# 关于 const

## 0、const修饰的变量

``` cpp
const int a = 10;
```

const修饰某物，某物就不能被改变。

顶层const：可以修饰所有数据类型，表示该类型的**对象本身**是常量。

底层const：与指针和引用有关，表示**地址所指向的对象**是常量。



## 1、指向const修饰的变量（常量）的指针（指针常量）

```cpp
const int a = 10;//顶层const
const int *pa = &a;//底层const
```

如果指针要指向一个const修饰的变量（常量），那么这个指针要被声明为const int * 类型，这样才能保证 a 不能被改变。const在*左边都行，和int可互换位置。

## 2、const修饰的指针（常量指针）

```cpp
int a = 10;
int b = 20;
int *const pa = &a;//顶层const
```

pa是一个const修饰的指针，pa的值（指针指向的值不就是地址吗）不能被改变。const要在*的右边。



```cpp
//顶层const举例
const int a = 10;//顶层const
int b = 20;
int *const pb = &b; //顶层const

//底层const举例
const int a = 10;//顶层const
const int *pa = &a;//底层const
```

