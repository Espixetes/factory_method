#include "Report_CSV.h"



void Report_CSV::Print(const std::vector<File_Info>& files, const fs::path& filename) const {

     std::ofstream ofs(filename);
     ofs << "Name,Size,Modified\n";
     for (const auto& file : files) 
     {
         ofs << "\"" << file.name << "\",";
         ofs << file.size << ",\"";
         ofs << static_cast<unsigned>(file.permission) << "\"\n";
     }
     ofs.close();
}
