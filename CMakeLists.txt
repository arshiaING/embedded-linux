cmake_minimum_required(VERSION 3.20)

project(sensor LANGUAGES CXX VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)  
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sensor 
app/src/main.cpp
app/src/FakeSensor.cpp    
app/src/TimeUtils.cpp
)

target_include_directories(sensor PRIVATE app/include)