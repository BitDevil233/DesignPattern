# version版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(Iterator VERSION 1.0)
# c++版本
set(CMAKE_CXX_STANDARD 14)

# 包含头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 源文件路径
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_CODE)

# # 添加源文件到可执行文件
add_executable(iterator 
${SRC_CODE} 
main.cpp
)