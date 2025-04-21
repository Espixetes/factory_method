#pragma once
#include "File_Handler.h"
#include "Factory_method.h"





class Folder_handler : public Handler
{
public:
	Folder_handler(const fs::path& path);
	void Process(std::vector<File_Info>& files_info);

	
private:
	fs::path m_folder_path;
	std::unique_ptr<Handler> m_handler;
};

