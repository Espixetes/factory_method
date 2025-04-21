#pragma once
#include "Handler.h"
#include <unordered_map>
#include <windows.h>
#include <chrono>
#include <fstream>



struct File_Info
{
    std::string name;
    std::size_t size;
    std::filesystem::perms permission;
};



class File_handler : public Handler
{
public:
    File_handler(const fs::path& path) ;
    void Process(std::vector<File_Info>& files_info);

private:
    fs::path m_file_path;
};

