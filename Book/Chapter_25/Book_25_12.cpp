void f(short val)
{
	unsigned char right = val&0xff;
	unsigned char left = val >> 8;
	// ...
	bool negative = val&0x8000;
}

enum Printer_flags
{
	acknowledge = 1;
	paper_empty = 1 << 1;
	busy = 1 << 2;
	out_of_black = 1 << 3;
	out_of_color = 1 << 4;
	// ...
};

unsigned char x = out_of_color | out_of_black;
x |= paper_empty;

if (x & out_of_color)
{
	// ...
}

unsigned char y = x &(out_of_color | out_of_black);

Flags z = Printer_flags(out_of_color | out_of_black);