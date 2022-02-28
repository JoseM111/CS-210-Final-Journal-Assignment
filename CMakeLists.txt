cmake_minimum_required(VERSION 3.21)
project(AirgeadBanking)

set(CMAKE_CXX_STANDARD 20)

add_executable(AirgeadBanking src/AirgeadBankingSource.cpp src/modules/bank/Bank.cpp src/modules/bank/Bank.h src/modules/displayInterface/DisplayInterface.cpp src/modules/displayInterface/DisplayInterface.h)
