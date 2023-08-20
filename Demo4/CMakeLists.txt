# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 是否使用自己的 MathFunctions 库
option (USE_MYMATH
	   "Use provided math implementation" ON)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# 是否加入 MathFunctions 库
if(USE_MYMATH)
    # 将math添加到include路径中
    # 这样cmake在编译过程中就能直接找到math中的头文件
    # 编写main的时候就不需要include相对路径了
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    # 将 EXTRA_LIBS 的值与字符串 "MathFunctions" 连接，重新赋值给 EXTRA_LIBS
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
else()
    # 不链接math库会报错，因为linux中默认没有math库
    LINK_LIBRARIES(m)
endif(USE_MYMATH)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable (Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})
