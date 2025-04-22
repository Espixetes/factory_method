#include "Report_TXT.h"


void Report_TXT::Print(const std::vector<File_Info>& files, fs::path filename) const {
    filename = (filename / "report.txt");
    std::ofstream file_stream(filename);
    try {
        if (!file_stream) {
            throw std::runtime_error("Could not open file");
        }

        for (const auto& file : files) {

            file_stream << "Name: " << file.name << "\n";
            file_stream << "Size: " << file.size << " bytes\n";
            file_stream << "Permission: " << static_cast<unsigned>(file.permission) << "\n";
            file_stream << "Archieve: " << file.archive << "\n";
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
