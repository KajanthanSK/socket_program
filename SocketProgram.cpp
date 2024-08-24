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

	return 0;
}