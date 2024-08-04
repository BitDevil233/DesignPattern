 
 /**
 * @file    BookShelf.cpp
 * @brief   该文件包含了BookShelf类的实现
 *
 * @author  周安超
 * @date    2024-08-02
 * @version 1.0
 *
 * @details 该文件实现了在Book.h头文件声明的方法.
 *
 * @note    该文件是设计模式练习计划的一部分.
 *
 * @bug     目前没有bug.
 *
 * @todo    目前没有TODO事项.
 *
 * @headerfile BookShelf.h
 * 
 * @changelog
 *          2024-08-01 周安超 - 初始版本.
 */

#include "BookShelf.h"
#include "BookShelfIterator.h"

std::shared_ptr<Iterator_BC> BookShelf::iterator() const {
    return std::make_shared<BookShelfIterator>(*this);
}
