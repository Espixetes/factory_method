#pragma once
#include <memory>
#include "Report.h"
#include "Report_TXT.h"
#include "Report_CSV.h"


enum class Report_Type { TXT, CSV };

class Report_Factory {
public:
    static std::unique_ptr<Report> Create_Report(Report_Type type);
};
