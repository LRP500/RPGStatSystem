cmake_minimum_required(VERSION 3.9)
project(RPGStatSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPGStatSystem
        src/main.cpp
        src/RPGStatSystem/Stat/RPGStat.cpp src/RPGStatSystem/Stat/RPGStat.hpp
        src/RPGStatSystem/Collection/RPGStatCollection.cpp src/RPGStatSystem/Collection/RPGStatCollection.hpp
        src/RPGStatSystem/Collection/Collections/RPGDefaultCollection.cpp src/RPGStatSystem/Collection/Collections/RPGDefaultCollection.hpp
        src/RPGStatSystem/Modifier/RPGStatModifier.cpp src/RPGStatSystem/Modifier/RPGStatModifier.hpp
        src/RPGStatSystem/Interface/IStatModifiable.hpp
        src/RPGStatSystem/Modifier/RPGStatModifiable.cpp src/RPGStatSystem/Modifier/RPGStatModifiable.hpp
        src/RPGStatSystem/Interface/IStatScalable.hpp
        src/RPGStatSystem/Attribute/RPGAttribute.cpp src/RPGStatSystem/Attribute/RPGAttribute.hpp
        src/RPGStatSystem/Linker/RPGStatLinker.cpp src/RPGStatSystem/Linker/RPGStatLinker.hpp
        src/RPGStatSystem/Linker/Linkers/RPGRatioLinker.cpp src/RPGStatSystem/Linker/Linkers/RPGRatioLinker.hpp
        src/RPGStatSystem/Interface/IStatLinkable.hpp
        src/RPGStatSystem/Vital/RPGVital.cpp src/RPGStatSystem/Vital/RPGVital.hpp
        src/RPGStatSystem/Event/EventHandler.cpp src/RPGStatSystem/Event/EventHandler.hpp
        src/RPGStatSystem/Event/Delegate.hpp
        src/RPGStatSystem/Event/Event.hpp src/RPGStatSystem/Interface/IStatValueEvent.hpp src/RPGStatSystem/Interface/IStatCurrentValueEvent.hpp)