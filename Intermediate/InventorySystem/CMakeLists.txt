cmake_minimum_required(VERSION 3.10)
project(InventorySystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(InventoryApp 
                src/main.cpp
                src/Item.cpp 
                src/Inventory.cpp
                src/Logger.cpp
)