#pragma once
#include "Folder_handler.h"
#include <fstream>

class Report
{
public:
	Report() = default;
	virtual void Print(const std::vector<File_Info>& files,  fs::path filename) const = 0;
	virtual ~Report() = default;
};

