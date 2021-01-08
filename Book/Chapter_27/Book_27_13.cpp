char* p = "asdf";
char s[] = "asdf";

size_t strlen(const char* s);
char* strcat(char* s1, const char* s2);
int strcmp(const char* s1, const char* s2);
char* strcpy(char* s1, const char *s2);
char* strchr(const char* s, int c);
char* strstr(const char* s1, const char* s2);
char* strncpy(char* s1, const char* s2, size_t n);
char* strncat(char* s1, const char* s2, size_t n);
int strncmp(const char* s1, const char* s2, size_t n);

const char* s1 = "asdf";
const char * s2 = "asdf";
if (s1 == s2)
{}
if (strcmp(s1, s2) == 0)
{}

strcmp("dog", "dog") == 0
strcmp("ape", "dodo") < 0
strcmp("pig", "cow") > 0

int lgt = strlen(s1);

strcpy(s1, s2);

string s = id + "@" + addr;
char* cat(const char* id, const char* addr)
{
	int sz = strlen(id) + strlen(addr) + 2;
	char* res = (char*)malloc(sz);
	strcpy(res, id);
	res[strlen(id) + 1] = '@';
	strcpy(res + strlen(id) + 2, addr);
	res[sz - 1] = 0;
	return res;
}