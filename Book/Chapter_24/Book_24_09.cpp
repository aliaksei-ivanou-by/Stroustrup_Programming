Matrix<int, 3> a(10, 20, 30);
a.size();
a.dim1();
a.dim2();
a.dim3();
int* p = a.data();
a(i, j, k);
a[i];
a[i][j][k];
a.slice(i);
a.slice(i, j);
Matrix<int, 3> a2 = a;
a = a2;
a *= 7;
a.apply(f);
a.apply(f, 7);
b = apply(f, a);
b = apply(f, a, 7);
a.swap_rows(7, 9);

int grid_nx;
int grid_ny;
int grid_nz;
Matrix<double, 3> cube(grid_nx, grid_ny, grid_nz);