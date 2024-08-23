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

	return 0;
}