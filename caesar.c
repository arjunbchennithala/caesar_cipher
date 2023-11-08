#include <stdio.h>
#include <string.h>

int isCaps(char val) {
	if(val < 'a'  && val >= 'A') {
		return 1;
	}else{
		return 0;
	}
}

int main(int argc, char** argv) {
	if(argc<2) {
		printf("Input  : %s <string>\n", argv[0]);
		return 1;
	}

	char* cipher = argv[1];

	for(int i=0; i<26; i++) {
		for(int j=0; j<strlen(cipher); j++) {
			char c = cipher[j];
			if(c > 'z' || c < 'A')  {
				printf("%c", c);
				continue;
			}
			if(isCaps(c)) {
				c -= i;
				if(c<'A') {
					c = 'Z' - ('A' - c - 1);
				}
			}else{
				c -= i;
				if(c<'a') {
					c = 'z' - ('a'-c-1);
				}
			}
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}
