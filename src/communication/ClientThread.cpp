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

}

ClientThread::ClientThread( int port , char *ip)
{
	setThreadId( CLIENT_THREAD_ID );
	client = new SocketClient( port, ip );

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
	printf("[KPI::THREAD] START\n");

	flag=true;
	//client->recvMsg();

	while(flag)
	{
		client->start();
		client->recvMsg();
		sleep(3);
	}

	return NULL;
}

void ClientThread::recv()
{

	while(flag)
	{
		client->recvMsg();
		sleep(3);
	}

}

int ClientThread::stop()
{
	printf("[KPI::THREAD] STOP\n");
	return pthread_cancel( CLIENT_THREAD_ID );
}

int ClientThread::kill()
{
	printf("[KPI::THREAD] KILL\n");
	return pthread_kill( CLIENT_THREAD_ID , SIGQUIT );
}
