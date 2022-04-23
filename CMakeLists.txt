cmake_minimum_required(VERSION 3.21)
project(Project_password_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_password_manager main.cpp "Features/Log in/login.cpp" "Features/Log in/login.h" Features/EncryptPassword/encryptPassword.cpp Features/EncryptPassword/encryptPassword.h Features/DecryptPassword/decryptPassword.cpp Features/DecryptPassword/decryptPassword.h)
