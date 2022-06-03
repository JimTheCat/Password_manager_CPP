cmake_minimum_required(VERSION 3.21)
project(Project_password_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_password_manager main.cpp Utils/Encrypting/encrypt.cpp Utils/Encrypting/encrypt.h Utils/Decrypting/decrypt.cpp Utils/Decrypting/decrypt.h Utils/Auth/auth.cpp Utils/Auth/auth.h Utils/Seed/seed.cpp Utils/Seed/seed.h Menu/FilePath/filePath.cpp Menu/FilePath/filePath.h Utils/FileVectorConverter/converter.cpp Utils/FileVectorConverter/converter.h Menu/Design/menu.cpp Menu/Design/menu.h Menu/Wyszukaj/wyszukaj.cpp Menu/Wyszukaj/wyszukaj.h Menu/Dodaj/dodaj.cpp Menu/Dodaj/dodaj.h Utils/Timestamp/timestamp.cpp Utils/Timestamp/timestamp.h Menu/DodajKat/addCategory.cpp Menu/DodajKat/addCategory.h Menu/Edytuj/edit.cpp Menu/Edytuj/edit.h Menu/Posortuj/sort.cpp Menu/Posortuj/sort.h Menu/Usun/deletePassword.cpp Menu/Usun/deletePassword.h Menu/UsunKat/deleteCategory.cpp Menu/UsunKat/deleteCategory.h)
