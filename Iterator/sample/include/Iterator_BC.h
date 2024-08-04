/// @file Iterator.h
/// @author 周安超
/// @date 2024-08-02
/// @brief：此文件包含类 Iterator 的声明。

#pragma once

#include <memory>
#include "Book.h"

/// @brief 迭代器类，用于遍历书架类
class Iterator_BC {
public:
    /// @brief 虚析构函数确保派生类的析构函数被正确调用
    virtual ~Iterator_BC() = default;
    
    /// @brief 纯虚函数，判断是否存在下一个元素
    /// @return 是否有下一个函数
    virtual bool hasNext() const = 0;

    /// @brief 纯虚函数，获取下一个元素
    /// @return 下一个元素的指针
    virtual bool next(Book &book) = 0;
};


