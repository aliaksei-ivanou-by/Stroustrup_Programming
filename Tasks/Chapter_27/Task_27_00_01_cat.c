#include <stdlib.h>

char* cat(const char* id, const char* addr)
{
	int idLength = strlen(id); /* function strlen() works once */
	int idAddr = strlen(addr); /* function strlen() works once */
	int sz = idLength + idAddr + 2; /* +2 - for addition symbol and end of char* */
	char* res = 0;
	res = (char*)malloc(sz);
	if (!res)
	{
		perror("Can't allocate memory\n");
	}
	strcpy(res, id);
	res[idLength] = '@'; /* NOT idLength + 1 */
	strcpy(res + idLength + 1, addr); /* NOT res + idLength + 2 */
	res[sz - 1] = 0; /* end of char* */
	return res;
}


int main()
{
	char* id = "aliaksei.ivanou.by";
	char* domen = "icloud.com";
	char* email = cat(id, domen);
	printf("%s\n", email);
}