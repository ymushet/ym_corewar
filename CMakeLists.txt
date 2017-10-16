cmake_minimum_required(VERSION 3.7)
project(corewar_vm_validation)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES read_core.c main.c process.c ft_atoi_base.c map.c error.c core2.c corewar_vm_validation.h read_core2.c visualization/visualization.c visualization/visualization.h visualization/set_color.c)
add_executable(corewar_vm_validation ${SOURCE_FILES})
target_link_libraries(corewar_vm_validation ${CMAKE_SOURCE_DIR}/libft/libft.a)
