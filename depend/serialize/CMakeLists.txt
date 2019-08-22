cmake_minimum_required(VERSION 3.5)

project(libserialize)

include_directories(./)


set(compat_src  compat/glibc_compat.cpp
                compat/glibc_sanity.cpp
                compat/glibcxx_sanity.cpp
                compat/strnlen.cpp)

set(support_src support/cleanse.cpp
                support/lockedpool.cpp)


set(basic_link_lib c rt pthread boost_system  boost_program_options boost_filesystem )

ADD_LIBRARY(serialize  ${compat_src}
				  ${support_src})
target_link_libraries(serialize ${basic_link_lib})

