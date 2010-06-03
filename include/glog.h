#include "../src/log4cplus/include/log4cplus/logger.h"
#include "../src/log4cplus/include/log4cplus/fileappender.h"
#include "../src/log4cplus/include/log4cplus/layout.h"

#define GENE_LOG log4cplus::Logger::getInstance("main")
#define LOG_ERROR(x) LOG4CPLUS_ERROR(GENE_LOG, x.toStdString())
#define LOG_WARNING(x) LOG4CPLUS_DEBUG(GENE_LOG, x.toStdString())
#define LOG_INFO(x) LOG4CPLUS_INFO(GENE_LOG, x.toStdString())
