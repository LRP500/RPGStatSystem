cmake_minimum_required(VERSION 3.9)
project(RPGStatSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPGStatSystem src/main.cpp src/RPGStatSystem/RPGStat.cpp src/RPGStatSystem/RPGStat.hpp src/RPGStatSystem/RPGStatCollection.cpp src/RPGStatSystem/RPGStatCollection.hpp src/RPGStatSystem/Collections/RPGDefaultCollection.cpp src/RPGStatSystem/Collections/RPGDefaultCollection.hpp src/RPGStatSystem/RPGStatModifier.cpp src/RPGStatSystem/RPGStatModifier.hpp src/RPGStatSystem/IStatModifiable.cpp src/RPGStatSystem/IStatModifiable.hpp src/RPGStatSystem/RPGStatModifiable.cpp src/RPGStatSystem/RPGStatModifiable.hpp)