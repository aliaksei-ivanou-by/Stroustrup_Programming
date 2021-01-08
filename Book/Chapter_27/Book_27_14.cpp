char* p = "asdf";
p[2] = 'x';

const char* p = "asdf";

char* strchr(const char* s, int c);
const char aa[] = "asdf";
char* q = strchr(aa, 'd');
*q = 'x';

char const* strchr(const char* s, int c);
char* strchr(char* s, int c);