#include<iostream>
#include<WinSock2.h>

using namespace std;

#define PORT 99999
struct sockaddr_in srv;

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

	/* Control the mode of socket (I/O) */
	/* Blocking: recv,send */
	/* Non-Blockin: recv,send */
	u_long nMode = 0; // 0->blocking
	error = ioctlsocket(nListenerSocket, FIONBIO, &nMode);

	if (error < 0)
	{
		cout << "The ioctlsocket failed" << endl;
	}
	else
	{
		cout << "Socket mode set to blocking" << endl;
	}

	/* Bind the server code to a port */
	/* IP Address */
	/* Port */
	srv.sin_family = AF_INET;
	srv.sin_port = htons(PORT);
	srv.sin_addr.s_addr = INADDR_ANY;
	memset(&srv.sin_zero, 0, sizeof(srv));
	error = bind(nListenerSocket, (struct sockaddr*)&srv, sizeof(srv));

	if (error < 0)
	{
		cout << "Failed to bind to local port" << endl;
	}
	else
	{
		cout << "Bind to local port sucessfully" << endl;
	}

	return 0;
}