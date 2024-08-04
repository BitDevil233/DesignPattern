#pragma once

#include <memory>
#include "Iterator_BC.h"

class Aggregate {
public:
    virtual ~Aggregate() = default;
    
    /// @brief 创建一个迭代器并返回
    /// @return 迭代器
    virtual std::shared_ptr<Iterator_BC> iterator() const = 0;
};
