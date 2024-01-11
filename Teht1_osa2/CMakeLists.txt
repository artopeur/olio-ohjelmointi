cmake_minimum_required(VERSION 3.5)

project(Teht1_osa2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Teht1_osa2 main.cpp)

include(GNUInstallDirs)
install(TARGETS Teht1_osa2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
