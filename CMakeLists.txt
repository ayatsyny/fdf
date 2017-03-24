cmake_minimum_required(VERSION 3.6)
project(fdf)

set(CCMAKE_C_FLAGS "-std=c99")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")


set(SOURCE_FILES
        main.c
        double_list.c
        draw.c
        init_struct.c
        tools_dbl_lst.c
        fdf.h)

add_executable(fdf ${SOURCE_FILES})
target_link_libraries(fdf ${CMAKE_SOURCE_DIR}/libft/libft.a)