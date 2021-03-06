// PointwiseIO.h
// created by Kuangdai on 1-Jun-2017 
// IO for point-wise receivers

#pragma once

#include "eigenc.h"
#include <string>

class PointwiseIO {
public:
    virtual ~PointwiseIO() {};
    
    // before time loop
    virtual void initialize(int totalRecordSteps, int bufferSize, bool ENZ,
        const std::vector<std::string> &names,
        const std::vector<std::string> &networks) = 0;
    
    // after time loop
    virtual void finalize() = 0;
    
    // dump to user-specified format
    virtual void dumpToFile(const RMatXX_RM &bufferDisp, const RColX &bufferTime, int bufferLine) = 0;
};

