static_assert(4 <= sizeof(int), "int is too small");
static_assert(!numeric_limits<char>::is_signed, "signed char");

unsigned char a = 0xaa; // 10101010 - 0xaa
unsigned char x0 = ~a; //  01010101 - 0x55

unsigned char a = 0xaa; // 10101010 - 0xaa
unsigned char b = 0x0f; // 00001111 - 0xf
unsigned char x1 = a&b; // 00001010 - 0xa

unsigned char a = 0xaa; // 10101010 - 0xaa
unsigned char b = 0x0f; // 00001111 - 0xf
unsigned char x2 = a^b; // 10100101 - 0xa5

unsigned char a = 0xaa; //    10101010 - 0xaa
unsigned char x3 = a << 1; // 01010100 - 0x54

unsigned char a = 0xaa; //    10101010 - 0xaa
unsigned char x4 = a >> 2; // 00101010 - 0x2a

