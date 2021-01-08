FILE* fopen(const char* filename, const char* mode);
int fclose(FILE* stream);

void f(const char* fn, const char* fn2)
{
	FILE* fi = fopen(fn, "r");
	FILE* fo = fopen(fn2, "w");
	
	if (fi == 0)
	{
		error("Can't open file for input");
	}
	if (fo == 0)
	{
		error("Can't open file for output");
	}
	fclose(fo);
	fclose(fi);
}