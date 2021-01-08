#define MAX(x, y) ((x)>=(y)?(x):(y))

int aa = MAX(1, 2);
double dd = MAX(aa++, 2);
char cc = MAX(dd, aa) + 2;

int aa = ((1)>=(2)?(1):(2));
double dd = ((aa++)>=(2):(aa++):(2));
char cc = ((dd)>=(aa)?(dd):(aa)) + 2;
char cc = dd>=aa?dd:aa + 2;

#define ALLOC(T, n) ((T*)malloc(sizeof(T) * n))
double* p = malloc(sizeof(int) * 10);

#define ALLOC(T, n) (error_var = (T*)malloc(sizeof(T) * n), (error_var == 0) ? (error("memory error"), 0) : (error_var)