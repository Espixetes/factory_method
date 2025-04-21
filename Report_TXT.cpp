#include "Report_TXT.h"


void Report_TXT::Print(const std::vector<File_Info>& files, const fs::path& filename) const  {
    std::ofstream ofs(filename);
    for (const auto& file : files) {
        ofs << "Name: " << file.name << "\n";
        ofs << "Size: " << file.size << " bytes\n";
        ofs << "Modified: " << static_cast<unsigned>(file.permission) << "\n";
        ofs << "------------------------\n";
    }
    ofs.close();
}
