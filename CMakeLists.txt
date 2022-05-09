cmake_minimum_required(VERSION 3.21)
project(Project_password_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_password_manager main.cpp Utils/Encrypting/encrypt.cpp Utils/Encrypting/encrypt.h Utils/Decrypting/decrypt.cpp Utils/Decrypting/decrypt.h Utils/Auth/auth.cpp Utils/Auth/auth.h Utils/Seed/seed.cpp Utils/Seed/seed.h Menu/FilePath/filePath.cpp Menu/FilePath/filePath.h)
