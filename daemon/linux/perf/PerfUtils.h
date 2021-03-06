/* Copyright (C) 2010-2020 by Arm Limited. All rights reserved. */

#ifndef PERF_UTILS_H
#define PERF_UTILS_H

#include "lib/Format.h"
#include "lib/Utils.h"

#include <set>
#include <string>

namespace perf_utils {
    inline std::set<int> readCpuMask(const char * pmncName)
    {
        std::string path = lib::Format() << "/sys/bus/event_source/devices/" << pmncName << "/cpumask";
        return lib::readCpuMaskFromFile(path.c_str());
    }
}

#endif // PERF_UTILS_H
