/*
 * Logger.cpp
 *
 *      Author: CAPSTONE Project AUV
 */
#include "Logger.h"

//-----------------------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------------------
Logger::Logger(char * node )
{
	openlog( node, 0, LOG_USER | LOG_NOWAIT | LOG_NDELAY);

}
//-----------------------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------------------
Logger::~Logger()
{
	closelog();
}

//-----------------------------------------------------------------------------------------
// Log Templates
//-----------------------------------------------------------------------------------------
void Logger::error(char * msg)
{
	syslog(LOG_ERR, msg);
}

void Logger::info(char * msg)
{
	syslog(LOG_INFO, msg);
}
void Logger::notice(char * msg)
{
	syslog(LOG_NOTICE, msg);
}
