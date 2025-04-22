#pragma once
#include "Report.h"


class Report_TXT : public Report
{
public:
    void Print(const std::vector<File_Info>& files,fs::path filename) const override;
    
};

