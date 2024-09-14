#include <iostream>
///1、编译器处理类时，先处理类的成员变量，然后才处理成员函数体，因此成员函数可以随意使用成员变量
///2、不需要参数的构造参数叫默认构造函数；2、编译器创建的构造函数叫做合成的默认构造函数（编译器生成的肯定不需要参数）
///3、类中含有vector和string，拷贝和赋值和销毁是比较安全的，如果类使用类外内存空间要小心
class Sales_data
{
    friend Sales_data add(const Scales_data&, const Scales_data&);///友元函数的声明一定在类内，将add函数声明为友元函数，这样就可以访问类内部非public的变量了
    public:
        Sales_data();///1、构造函数不能声明为const数据，因为即使在创建const属性的类实例时，其const属性也是在构造函数执行完才获得的；
                     ///2、在这我们定义了默认构造函数，编译器就不替我们生成了
                     ///3、构造函数没有返回类型
        
        //Sales_data() = default;///这个default关键字是为了告诉编译器，我要使用一个带参数的函数，因此这个默认函数我也用自己的，也就是这个构造函数
        //Sales_data(const std:string & s): bookNo_(s){}///当定义了这个构造函数的时候，说明我们想管控成员变量的初始化，那么我们就不要使用合成默认构造函数了，因此要定义一个默认构造函数，也就是default的。
        explicit Sales_data(int a);///禁用隐式转换，explicit在定义的时候不再添加
        std::string isbn()const {return bookNo_;}///1、定义在类内部的函数都是内联的；2、const的作用是修改隐式this指针的，让this指向一个常量类对象，因此它不能做改变成员的操作；
        Sales_data & combine(const Sales_data & rhs);
        
        double avg_price() const;
        static int test0(){return test_1_;};


    public:
        std::string bookNo_;///如果有初始值的话，编译器合成的默认构造函数会使用这个值初始化成员变量，否则按照相应原则赋值
        int units_sold_ = 0;
        double revenue_ = 0.0;
        mutable int test_1_ = 0;///mutable关键字可以保证，即使是const成员函数也能更改这个变量
        static int test_2_ = 0;///静态成员存在于对象之外,它不由类的构造函数初始化
};

Scales_data add(const Scales_data&, const Scales_data&);///友元函数的声明与正常函数的声明没有关系，这个函数声明也是要有的