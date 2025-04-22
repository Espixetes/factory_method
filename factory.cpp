#include "Report_factory.h"

int main(int argc, char* argv[])
{
    
    fs::path path;
    std::vector<File_Info> files_info;
    
    try
    {       
        if (argc == 1)
        {
            throw std::invalid_argument("Error: No folder path provided. Please provide a valid folder path as an argument.");
        }
        path = argv[1];
        
    }
    catch (const std::exception& expected_result)
    {
        std::cerr << expected_result.what() << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred. Please try again." << std::endl;
        return 0;
    }
   


    Folder_handler start(path);
    start.Process(files_info);

  
   
    
    auto report = Report_Factory::Create_Report(Report_Type::TXT);


    report->Print(files_info, path);


   
}
