#include "src/communication/ClientThread.h"

#define ESC 27

using namespace std;


int main(int argc, char *argv[])
{
	printf("[KPI::MAIN] START\n");

	ClientThread* clientThread = new ClientThread(5000, "192.168.10.50");
	clientThread->start();

    char key;
    do
    {
        key = getchar();

    }while(key != ESC);

    printf("[KPI::MAIN]::Escape Character Triggered\n");
    clientThread->flag=false;

    if( clientThread->stop() != 0 )
    {
    	printf("[KPI::MAIN] failed stop\n");
    	clientThread->kill();
    }

    delete clientThread;
    printf("[KPI::MAIN] END\n");



    return EXIT_SUCCESS;
}
