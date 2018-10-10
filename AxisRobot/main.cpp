#include "RS232c.h"
#include <cstdio>

#pragma warning(disable:4996)

using namespace std;

int main() {
	char buf[256];
	int height;
	RS232c rs;
	rs.Connect("COM3",38400,ODDPARITY,0,0,0,20000,20000);

	rs.Send("@SRVO1.1\r\n");
	rs.Read_CRLF(buf, 256);
	printf(buf);
	Sleep(3000);

	rs.Send("@ORG.1\r\n");
	rs.Read_CRLF(buf, 256);
	printf(buf);
	rs.Read_CRLF(buf, 256);
	printf(buf);
	Sleep(5000);

	for (size_t i = 0; i < 50; i++)
	{
		rs.Send("@INCH+.1\r\n");
		rs.Read_CRLF(buf, 256);
		printf(buf);
		rs.Read_CRLF(buf, 256);
		printf(buf);
	}
	//Sleep(5000);

	rs.Send("@?D0.1\r\n");
	rs.Read_CRLF(buf, 256);
	printf(buf);

	sscanf(buf, "D0.1=%d\r\n",&height);
	printf("%fmm", height*0.01);
	Sleep(5000);

	
	rs.Send("@SRVO0.1\r\n");
	rs.Read_CRLF(buf, 256);
	return 0;
}