cmake_minimum_required(VERSION 3.16)
project(Jocul_PAV C)

set(CMAKE_C_STANDARD 11)

add_executable(Jocul_PAV main.c initializare_pav.c pav_master.c pav_master.h)