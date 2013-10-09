#include <winsock2.h>
#include "Net.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>;
using namespace std;
Net *net;
void playerA()
{
		bool gameover = false;
	char ip[] = "149.153.102.38";
	char ipsend[] = "149.153.102.44";
	int port = 28000;
	//net::setupUDP(port,ip);
	net->setupUDP(port,ip);
	char message[200] = "";

	//send

	char sendMessage[] =  "hello B";
	
	while(!gameover)
	{
		if(kbhit())
		{
		cin >> sendMessage ;
		if(sendMessage[0] == 'x')
		{
			exit(0);
		}
		net->sendData(ipsend,28001,sendMessage);
		}
		net->receiveData(message);
		
	if ( strcmp(message, "") > 0)
	{
		cout << message <<endl;
	cout << net->getSenderIP() <<endl;
		 strcpy(message, "");
	}
		}
}
void playerB()
{
	bool gameover = false;
	char ip[] = "149.153.102.44"; //"127.0.0.1"; 
	char ipsend[] = "149.153.102.38";
	int port = 28001;
	//net::setupUDP(port,ip);
	net->setupUDP(port,ip);
	char message[200] = "";
		char sendMessage[] =  "hello B";
	while(!gameover)
	{
			if(kbhit())
			{
		cin >> sendMessage;
		if(sendMessage[0] == 'x')
		{
			exit(0);
		}
		net->sendData(ipsend,28000,sendMessage);
		}
      net->receiveData(message);
			
	if ( strcmp(message, "") > 0)
	{
		cout << message <<endl;
	cout << net->getSenderIP() <<endl;
		 strcpy(message, "");
	}

	}
}


int main()
{
	net = new Net();
	net->initialise();
	string input = "";
	cin>> input ;
	if(input == "a")
	{
		playerA();
	}
	else if(input == "b")
	{
		playerB();
	}
	system("PAUSE");
	return 0;

}



