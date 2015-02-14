/*
 * ClientThread.cpp
 *
 *      Author: AUV Capstone
 */

#include "ClientThread.h"

//-----------------------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------------------
ClientThread::ClientThread()
{
	setThreadId( CLIENT_THREAD_ID );
	client = new SocketClient();
	flag=false;
}

ClientThread::ClientThread( int port , char *ip)
{
	setThreadId( CLIENT_THREAD_ID );
	client = new SocketClient( port, ip );
	flag=false;
}
//-----------------------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------------------
ClientThread::~ClientThread()
{
	delete client;
}
//-----------------------------------------------------------------------------------------
// Overrides BaseThread's run() method
//-----------------------------------------------------------------------------------------
void* ClientThread::run()
{
	syslog(LOG_NOTICE,"[KPI::THREAD] START");

	flag=true;

	while(flag)
	{
		client->start();
		client->recvMsg();
		sleep(3);
	}

	return NULL;
}


int ClientThread::stop()
{
	syslog(LOG_NOTICE,"[KPI::THREAD] STOP");
	return pthread_cancel( CLIENT_THREAD_ID );
}

int ClientThread::kill()
{
	syslog(LOG_NOTICE,"[KPI::THREAD] KILL");
	return pthread_kill( CLIENT_THREAD_ID , SIGQUIT );
}
