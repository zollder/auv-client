/*
 * SocketClient.cpp
 *
 *      Author: AUV Capstone
 */

#include "SocketClient.h"
#include <iostream>
#include <sstream>

//-----------------------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------------------
SocketClient::SocketClient()
{
	portNumber = 5000;
	ipServer = "127.0.0.1";

	log = new Logger("Socket Client [KPI]");
}

SocketClient::SocketClient(int port, char *ip )
{
	portNumber = port;
	ipServer = ip;

	log = new Logger("Socket Client [KPI]");
}
//-----------------------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------------------
SocketClient::~SocketClient()
{
	delete log;

}

void SocketClient::start()
{
	connfd = -1;

	//create socket inside the kernel and return socket descriptor
	connfd = socket(AF_INET, SOCK_STREAM, 0);

	if (connfd < 0)
	{
		log->error("[ERROR] Failed to Open Socket");
		exit(EXIT_FAILURE);
	}

	memset(&server_addr, '0', sizeof(server_addr));
	memset(recBuff, '0',sizeof(recBuff));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portNumber);

	if( inet_pton(AF_INET, ipServer , &server_addr.sin_addr) <=0 )
	{
		log->error("[ERROR] inet_pton to Open");
		exit(EXIT_FAILURE);
	}

}

void SocketClient::recvMsg()
{
	numBytes = 0;

	if( connect( connfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		log->error("[ERROR] Failed to Connect to Server");
		//exit(EXIT_FAILURE);
	}

	while ( (numBytes = recv( connfd, recBuff, sizeof(recBuff) , MSG_WAITALL ) ) > 0)
	{
		recBuff[numBytes] = 0;

		if(numBytes < 0)
			    	log->error("[ERROR] Read Error");
		else
		{
			for( int  x = 0; x < 15 ; x++ )
				printf("%.2f\t", recBuff[x]);
			printf("\n");
		}

	}
}
