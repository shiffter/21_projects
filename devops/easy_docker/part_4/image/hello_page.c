#include <fcgi_stdio.h>

void main(void) {
	int count = 0;
	while (FCGI_Accept() >= 0) {
		printf("Content-type: text/html\r\n");
		printf("\r\n");
		printf("hello world\r\n");
	}
}
