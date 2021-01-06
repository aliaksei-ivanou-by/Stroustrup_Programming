Matrix<int, 2> a(3, 4);
int s = a.size();
int d1 = a.dim1();
int d2 = a.dim2();
int* p = a.data();

a(i, j);
a[i];
a[i][j];

a.slice(i);
a.slice(i, n);

Matrix<int, 2> a2 = a;
a = a2;
a *= 7;
a.apply(f);
a.apply(f, 7);
b = apply(f, a);
b = apply(f, a, 7);

a.swap_rows(1, 2);

enum Piece
{
	none,
	pawn,
	knight,
	queen,
	king,
	bishop,
	rook
};
Matrix<Piece, 2> board(8, 8);
const int white_start_row = 0;
const int black_start_row = 7;
Matrix<Piece> start_row = { rook, knight, bishop, queen, king, bishop, knight, rook };
Matrix<Piece> clear_row(8);

board[white_start_row] = start_row;
for (int i = 0; i < 7; ++i)
{
	board[i] = clear_row;
}
board[black_start_row] = start_row;