#pragma once
#include "Report.h"

class Report_CSV : public Report
{
    void Print(const std::vector<File_Info>& files, fs::path filename) const override;
};




