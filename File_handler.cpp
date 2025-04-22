#include "File_handler.h"

File_handler::File_handler(const fs::path& path) : Handler(path)
{
	try {
		if (!std::filesystem::is_regular_file(path))
		{
			throw std::invalid_argument("Error: No file path provided. Please provide a valid file path as an argument.");
		}
		m_file_path = path;
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


void File_handler::Process(std::vector<File_Info>& files_info) 
{
	try
	{
	File_Info file_info;

	file_info.name = m_file_path.filename().string();
	file_info.size = fs::file_size(m_file_path);
	file_info.permission = fs::status(m_file_path).permissions();
	file_info.archive = GetFileAttributesW(m_file_path.c_str());
	std::filesystem::file_time_type last_modification_time = std::filesystem::last_write_time(m_file_path);

	files_info.push_back(file_info);
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