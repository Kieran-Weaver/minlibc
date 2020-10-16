#include <ctype.h>
int isxdigit(int c){
	return isdigit(c) || (tolower(c)-'a' < 6);
}

int isblank(int c){
	return (c == '\t') || (c == ' ');
}
