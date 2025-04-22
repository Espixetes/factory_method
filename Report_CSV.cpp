#include "Report_CSV.h"



void Report_CSV::Print(const std::vector<File_Info>& files, fs::path filename) const {
    filename = (filename / "report.csv");
    std::ofstream file_stream(filename);
    try {
    if (!file_stream) {
        throw std::runtime_error("Could not open file ");
    }

    file_stream << "Name,Size,Permission,Archieve:\n";

    for (const auto& file : files) {
       

        file_stream << "\"" << file.name << "\","
            << file.size << ","
            << static_cast<unsigned>(file.permission) << ","
            << file.archive << "\n";
    }
    }
    catch (const std::exception& expected_result)
    {
        std::cerr << expected_result.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred. Please try again." << std::endl;
    }

}
