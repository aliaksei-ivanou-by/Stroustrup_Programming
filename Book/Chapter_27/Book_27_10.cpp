enum color
{
	red,
	blur,
	green
};
int x = green; /* ok in C and C++ */
enum color col = 7; /* ok in C, error in C++ */

enum color x = blue;
++x; /* error in C++ */
++xl; /* error in C++ */

color c2 = blue; /* error in C, ok in C++ */
enum color c3 = red; /* ok */