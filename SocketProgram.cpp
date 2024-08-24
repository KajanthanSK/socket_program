#include<iostream>
#include<WinSock2.h>

using namespace std;

int main()
{
	WSADATA ws;
	/* Loading the .dll (for socket APIs) in our process */
	int error=WSAStartup(MAKEWORD(2, 2), &ws);

	if (error == 0)
	{
		cout << "Successfully initialized socket lib"<<endl;
	}
	else if (error == -1)
	{
		cout << "Not initialized the socket APIs"<<endl;
		return EXIT_FAILURE;
	}

	/* Socket open */
	int nListenerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (nListenerSocket < 0)
	{
		cout << "The socket failed to open"<<endl;
	}
	else
	{
		cout << "Socket open successfully"<<endl;
	}

	/* Set the socket options */
	int optVal = 1;
	error = setsockopt(nListenerSocket, SOL_SOCKET, SO_REUSEADDR, (const char*) & optVal, sizeof(optVal));

	if (error < 0)
	{
		cout << "Not able to set the socket options" << endl;
	}
	else
	{
		cout << "Successfully set the socket options" << endl;
	}

	return 0;
}