// PointwiseIONetCDF.h
// created by Kuangdai on 1-Jun-2017 
// NetCDF IO for point-wise receivers

#pragma once

#include "PointwiseIO.h"
class NetCDF_Writer;

class PointwiseIONetCDF: public PointwiseIO {
public:
    // before time loop
    void initialize(int totalRecordSteps, int bufferSize, bool ENZ, 
        const std::vector<std::string> &names,
        const std::vector<std::string> &networks);
    
    // after time loop
    void finalize();
    
    // dump to user-specified format
    void dumpToFile(const RMatXX_RM &bufferDisp, const RColX &bufferTime, int bufferLine);
    
private:
    // variable names
    std::vector<std::string> mVarNames;
    
    // file ID
    NetCDF_Writer *mNetCDF = 0;
    
    // location in nc 
    int mCurrentRow = 0;
    
};

