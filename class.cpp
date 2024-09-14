#include "class.h"

Sales_data::test_2_ = 0;///类内静态成员的初始化

double Sales_data::avg_price() const
{

}

Sales_data & Sales_data::combine(const Sales_data & rhs)
{
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;

    return *this;///返回当前调用this指针的类实例，其实返回的是引用
}

void test0()
{
    int x = Sales_data::test0();///对class内静态成员函数调用
    std::cout << x << std::endl;
    return;
}