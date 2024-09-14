#include <iostream>
///1、编译器处理类时，先处理类的成员变量，然后才处理成员函数体，因此成员函数可以随意使用成员变量
///2、不需要参数的构造参数叫默认构造函数，Sales_data(int m = 10)，这种也算默认构造函数；2、编译器创建的构造函数叫做合成的默认构造函数（编译器生成的肯定不需要参数）
///3、类中含有vector和string，拷贝和赋值和销毁是比较安全的，如果类使用类外内存空间要小心
class Sales_data
{
    friend Sales_data add(const Scales_data&, const Scales_data&);///友元函数的声明一定在类内，将add函数声明为友元函数，这样就可以访问类内部非public的变量了
    public:
        Sales_data();///1、构造函数不能声明为const数据，因为即使在创建const属性的类实例时，其const属性也是在构造函数执行完才获得的；
                     ///2、在这我们定义了默认构造函数，编译器就不替我们生成了，
                     ///3、构造函数没有返回类型
        
        //Sales_data() = default;///这个default关键字是为了告诉编译器，我要使用一个带参数的函数，因此这个默认函数我也用自己的，也就是这个构造函数
        ///如果自己定义了需要带参数的构造函数，编译器就不生成合成的默认构造函数了，这是c++规定的，如果我们还未定义Sales_data（）这种默认构造函数，那么不能这么使用Sales_data A来创建对象
        Sales_data(const std:string & s): bookNo_(s){}///当定义了这个构造函数的时候，说明我们想管控成员变量的初始化，那么我们就不要使用合成默认构造函数了，因此要定义一个默认构造函数，也就是default的。
        explicit Sales_data(int a);///禁用隐式转换，explicit在定义的时候不再添加
        
        ///拷贝发生的时间：当某个类对象被当作参数或者函数使用值返回，或者用一个对象初始化另一个对象
        Sales_data(const Sales_data&) = default;///拷贝构造函数，注意传的是类对象的引用，而不是值传递，初始化一个新对象的时候
        Sales_data& operator=(const Sales_data &);///拷贝赋值运算符 ，更改一个老对象的值的时候
        Sales_data(const Sales_data&) = delete;///禁用拷贝构造函数
        Sales_data& operator=(const Sales_data &) = delete;///禁用拷贝赋值运算符
        ///当类可能会管理类外的内存时（如动态分配内存时），通常要手动定义该类的拷贝和析构操作，如果使用系统默认的拷贝操作可能发生浅拷贝
        
        ~Sales_data(){}
        //virtual ~Sales_data(){}///基类的析构函数最好声明为虚函数，防止派生类析构时会只析构基类的部分，析构函数要注意得类以外的内存空间做好清理工作


        std::string isbn()const {return bookNo_;}///1、定义在类内部的函数都是内联的；2、const的作用是修改隐式this指针的，让this指向一个常量类对象，因此它不能做改变成员的操作；
        Sales_data & combine(const Sales_data & rhs);
        
        double avg_price() const;
        static int test0(){return test_1_;};///静态成员函数只能访问静态成员变量或静态成员函数，静态成员函数或者变量属于整个类，并不属于某一个实例化的对象，它没有this指针


    public:
        std::string bookNo_;///如果有初始值的话，编译器合成的默认构造函数会使用这个值初始化成员变量，否则按照相应原则赋值
        int units_sold_ = 0;
        double revenue_ = 0.0;
        mutable int test_1_ = 0;///mutable关键字可以保证，即使是const成员函数也能更改这个变量
        static int test_2_ = 0;///静态成员存在于对象之外,它不由类的构造函数初始化
    
    protected:
        int test_3_ = 0;///想要由派生类继承，但是外部访问不到的，可以用protect
};

Scales_data add(const Scales_data&, const Scales_data&);///友元函数的声明与正常函数的声明没有关系，这个函数声明也是要有的