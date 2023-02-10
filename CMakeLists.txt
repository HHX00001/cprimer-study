cmake_minimum_required(VERSION 3.24)
project(cprimer-study)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/include LIB_SRC)

add_executable(main main.cpp)

add_executable(test0_1 c-study-01/test01.cpp)
add_executable(test0_2 c-study-01/test02.cpp)
add_executable(test0_3 c-study-01/test03.c)
add_executable(test0_4 c-study-01/test04.c)

add_executable(test3_1 c-study-03/test3_1.c)
add_executable(test3_4 c-study-03/test3_4.c)
add_executable(test3_7 c-study-03/test3_7.c)

add_executable(test4_1 c-study-04/test4_1.c)
add_executable(test4_2 c-study-04/test4_2.c)
add_executable(test4_4 c-study-04/test4_4.c)

add_executable(test5_1 c-study-05/test5_1.c)

add_executable(test6_1 c-study-06/test6_1.c)

add_executable(test7_1 c-study-07/test7_1.c)

add_executable(test8_1 c-study-08/test8_1.c)
add_executable(test8_5 c-study-08/test8_5.c)

add_executable(test9_3 c-study-09/test9_3.c)
add_executable(test9_5 c-study-09/test9_5.c)
add_executable(test9_7 c-study-09/test9_7.c)

add_executable(test10_1 c-study-10/test10_1.c)

add_executable(test11_1 c-study-11/test11_1.c)
add_executable(test11_5 c-study-11/test11_5.c)

add_executable(test12_1 c-study-12/test12_1.c c-study-12/global.c c-study-12/global1.c)
add_executable(test12_2 c-study-12/parta.c c-study-12/partb.c)

add_executable(test12_4 c-study-12/test12_4.c)

add_executable(test14_1 c-study-14/test14_1.c)
add_executable(test14_10 c-study-14/test14_10.c)

add_executable(test15_1 c-study-15/test15_1.c)

add_executable(test16_1 c-study-16/test16_1.c)

add_executable(test16_5 c-study-16/test16_5.c ${LIB_SRC})