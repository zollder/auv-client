#include "src/communication/ClientThread.h"

#include <syslog.h>

#define ESC 27

using namespace std;


int main(int argc, char *argv[])
{
	syslog(LOG_NOTICE,"[KPI::MAIN] START");

	ClientThread* clientThread = new ClientThread(5000, "192.168.0.10");
	clientThread->start();

    char key;
    do
    {
        key = getchar();

    }while(key != ESC);

    syslog(LOG_NOTICE,"[KPI::MAIN]::Escape Character Triggered");
    clientThread->flag=false;

    if( clientThread->stop() != 0 )
    {
    	syslog(LOG_NOTICE,"[KPI::MAIN] failed stop");
    	clientThread->kill();
    }

    delete clientThread;
    syslog(LOG_NOTICE,"[KPI::MAIN] END");


    return EXIT_SUCCESS;
}
