#include "Report_factory.h"



std::unique_ptr<Report> Report_Factory::Create_Report(Report_Type type) {
    try
    {
        switch (type) {
        case Report_Type::TXT: return std::make_unique<Report_TXT>();
        case Report_Type::CSV: return std::make_unique<Report_CSV>();

        default: throw std::invalid_argument("Unsupported report type.");
        }
    }
    catch (const std::runtime_error& expected_result)
    {
        std::cerr << expected_result.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred. Please try again." << std::endl;
    }
}