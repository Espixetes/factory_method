#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <vector>

namespace fs = std::filesystem;

struct File_Info;


class Handler
{
public:
	Handler(const fs::path& path);
	virtual void Process(std::vector<File_Info>& files_info) = 0;
	virtual ~Handler() = default;

private:
	fs::path m_path;
};

