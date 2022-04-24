cmake_minimum_required(VERSION 3.21)
project(Project_password_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_password_manager main.cpp Utils/EncryptPassword/encryptPassword.cpp Utils/EncryptPassword/encryptPassword.h Utils/DecryptPassword/decryptPassword.cpp Utils/DecryptPassword/decryptPassword.h Utils/Auth/auth.cpp Utils/Auth/auth.h)
