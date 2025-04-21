#include "Handler.h"

Handler::Handler(const fs::path& path)
{
    try
    {
        if (fs::exists(m_path))
        {
            throw std::runtime_error("Error: The path '" + m_path.string() + "' is not a valid.");
        }
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

