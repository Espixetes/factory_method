#pragma once
#include "Handler.h"
#include <memory>

class Folder_handler;
class File_handler;


class Factory_method 
{
public:
    static std::unique_ptr<Handler> Create_handler(const fs::path& path) ;
    
    virtual ~Factory_method() {};
};

