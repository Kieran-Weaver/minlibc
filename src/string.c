#include <string.h>
#include <stdlib.h>
// From musl libc
char* strtok(char *s, const char* sep){
	static char *p;
	if (!s && !(s = p)) return NULL;
	s += strspn(s, sep);
	if (!*s) return p = 0;
	p = s + strcspn(s, sep);
	if (*p) *p++ = 0;
	else p = 0;
	return s;
}

char * strdup(const char* s){
	int len = strlen(s);
	char * temp = malloc(len + 2);
	strncpy(temp, s, len+1);
	return temp;
}
