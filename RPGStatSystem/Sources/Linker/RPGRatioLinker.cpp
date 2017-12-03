//
// Created by Pierre Roy on 29/11/17.
//

#include "RPGRatioLinker.hpp"

RPGStatSystem::RPGRatioLinker::RPGRatioLinker(RPGStatSystem::RPGStat* stat,
                                              float ratio)
        : RPGStatLinker(stat),
          m_ratio(ratio)
{}
