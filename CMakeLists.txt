cmake_minimum_required(VERSION 2.8)

project(sailfish)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

include_directories(./include)

set(KV_SRC src/kvdbs/db_leveldb.cpp
			src/kvdbs/db_rocksdb.cpp)

set(DOC_SRC src/docdbs/db_mongo.cpp)

set(DIR_SRC ${KV_SRC}
			${DOC_SRC}
			src/main.cpp)


set(link_lib rocksdb leveldb bsoncxx mongocxx)

add_executable(sailfish ${DIR_SRC} )

target_link_libraries(sailfish ${link_lib})
