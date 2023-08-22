# 查找当前目录下的所有源文件

# 并将名称保存到 DIR_LIB_SRCS 变量

aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
set(SDS_STATES_ALL_SOURCES  ${PROJECT_SOURCE_DIR}/src/max.cpp)

#add_library (MathFunctions ${DIR_LIB_SRCS})

set(ALL_SOURCES
    ${SDS_STATES_ALL_SOURCES}
    PARENT_SCOPE
   )
