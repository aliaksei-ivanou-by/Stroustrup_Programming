int* p = (int*)7; // reinterpret_cast<int*>(7)
int x = (int)7.5; // static_cast<int>(7.5)
typedef struct S1
{
	/* ... */ 
} S1;
typedef struct S2
{
	/* ... */ 
} S2;
S1 a;
const S2 b;
S1* p = (S1*)&a; // reinterpret_cast<S1*>(&a)
S2* q = (S2*)&b; // reinterpret_cast<S2*>(&b)
S1* r = (S1*)&b; // may be error

#define REINTERPRET_CAST(T, v) ((T)(v))
#define CONST_CAST(T, v) ((T)(v))
S1* p = REINTERPRET_CAST(S1*, &a);
S2 q = CONST_CAST(S2*, &b);