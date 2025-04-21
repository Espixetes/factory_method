#include "Factory_method.h"
#include "Folder_Handler.h"


std::unique_ptr<Handler> Factory_method::Create_handler(const fs::path& path) 
{
    try
    {
    if (std::filesystem::is_regular_file(path))
    {
        return std::make_unique<File_handler>(path);
    }
    else if (std::filesystem::is_directory(path))
    {
        return std::make_unique<Folder_handler>(path);
    }
    else
    {
        throw std::invalid_argument("Unsupported path type: not a file or folder");
    }
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