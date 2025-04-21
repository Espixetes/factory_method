#include "Folder_handler.h"



Folder_handler::Folder_handler(const fs::path& path) : Handler(path)
{
    try
    {
        if (!fs::is_directory(path))  
        {
            throw std::invalid_argument("Error: The path '" + path.string() + "' is not a valid directory.");
        }
        m_folder_path = path;
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


void Folder_handler::Process(std::vector<File_Info>& files_info)
{
    try {
        std::vector<fs::path> folder_records;

        for (const auto& data : fs::directory_iterator(m_folder_path)) {
            folder_records.push_back(data.path());
        }

        for (const fs::path& path : folder_records)
        {
            try
            {
                m_handler = Factory_method::Create_handler(path);
                m_handler->Process(files_info);
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


    }
    catch (const std::exception& expected_result) {
        std::cerr << "Mistake: " << expected_result.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred. Please try again." << std::endl;
    }
}



