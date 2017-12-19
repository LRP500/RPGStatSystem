cmake_minimum_required(VERSION 3.9)
project(RPGStatSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPGStatSystem
        Sources/main.cpp
        Sources/Stat/RPGStat.cpp Sources/Stat/RPGStat.hpp
        Sources/Collection/RPGStatCollection.cpp Sources/Collection/RPGStatCollection.hpp
        Sources/Collection/RPGDefaultCollection.cpp Sources/Collection/RPGDefaultCollection.hpp
        Sources/Modifier/RPGStatModifier.cpp Sources/Modifier/RPGStatModifier.hpp
        Sources/Interface/IStatModifiable.hpp
        Sources/Stat/Modifiable/RPGStatModifiable.cpp Sources/Stat/Modifiable/RPGStatModifiable.hpp
        Sources/Interface/IStatScalable.hpp
        Sources/Stat/Attribute/RPGAttribute.cpp Sources/Stat/Attribute/RPGAttribute.hpp
        Sources/Linker/RPGStatLinker.cpp Sources/Linker/RPGStatLinker.hpp
        Sources/Linker/RPGRatioLinker.cpp Sources/Linker/RPGRatioLinker.hpp
        Sources/Interface/IStatLinkable.hpp
        Sources/Stat/Vital/RPGVital.cpp Sources/Stat/Vital/RPGVital.hpp
        Sources/System/Event/Delegate.hpp
        Sources/System/Event/Event.hpp
        Sources/Interface/IStatValueChange.hpp
        Sources/Interface/IStatCurrentValueChange.hpp
        Sources/Modifier/Mods/RPGStatModBasePercent.cpp Sources/Modifier/Mods/RPGStatModBasePercent.hpp
        Sources/Modifier/Mods/RPGStatModBaseAdd.cpp Sources/Modifier/Mods/RPGStatModBaseAdd.hpp
        Sources/Modifier/Mods/RPGStatModTotalPercent.cpp Sources/Modifier/Mods/RPGStatModTotalPercent.hpp
        Sources/Modifier/Mods/RPGStatModTotalAdd.cpp Sources/Modifier/Mods/RPGStatModTotalAdd.hpp
        Sources/System/optimized_inserter.h)