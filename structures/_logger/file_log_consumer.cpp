#include "file_log_consumer.h"
#include <stdexcept>

namespace structures
{
    FileLogConsumer::FileLogConsumer(const std::string& path) :
        fileStream_(path)
    {
        if (!fileStream_.is_open())
        {
            throw std::runtime_error("Failed to open file " + path);
        }
    }

    void FileLogConsumer::logMessage(LogType type, const std::string& message)
    {
        fileStream_ << logTypeToString(type) << ',' << message << std::endl;
    }

    void FileLogConsumer::logDuration(size_t size, structures::DurationType duration, const std::string& message)
    {
//        fileStream_ << logTypeToString(LogType::Duration) << ','
//            << duration.count() << ','
//            << message << ','
//            << std::endl;

        fileStream_ << "Size," << std::to_string(size) << "," << std::to_string(duration.count()) <<"," << message << std::endl;
    }

    FileLogConsumer::~FileLogConsumer()
    {
        fileStream_.close();
    }
}