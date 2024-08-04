/**
 * @file    Book.h
 * @brief   Declaration of the Book class.
 *
 * @author  Anchao Zhou
 * @date    2024-08-01
 * @version 1.0
 *
 * @details This file contains the declaration of the Book class, which provides
 *          various methods for processing the book properties.
 *
 * @note    This file is part of the Design-pattern-Practice project.
 *
 * @bug     No known bugs.
 *
 * @todo    Add more detailed documentation for each method.
 *
 * @changelog
 *          2024-08-01 Anchao Zhou - Initial version.
 */

#pragma once

#include <string>

/// @brief 表示图书的类
class Book {
public:
    /// @brief Book类的默认构造函数
    Book() : name_("") {}  

    /// @brief Book类的构造函数
    /// @param name 图书名称
    Book(const std::string &name) : name_(name) {}

    /// @brief 获取图书名称
    /// @return 图书名称
    std::string getName() const { return name_; }

private:
    /// @brief 图书名称
    std::string name_;
};
