cmake_minimum_required(VERSION 3.21)
project(DSA_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA_Project main.cpp Item.cpp Inventory.cpp Cart.cpp Admin.cpp DataLayer.cpp Client.cpp User.cpp TransactionHistory.cpp Product.cpp)
