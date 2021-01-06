void poor(Shape* p, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		p[i].draw();
	}
}
void f(Shape* q, vector<Circle>& s0)
{
	Polygon s1[10];
	Shape s2[10];
	
	Shape* p1 = new Rectangle{ Point{ 0, 0}, Point{ 10, 20 } };
	poor(&s0[0], s0.size()); // bad
	poor(s1, 10); // bad
	poor(s2, 20); // bad
	poor(p1, 1); // ok
	delete p1;
	p1 = 0;
	poor(p1, 1); // bad
	poor(q, max); // ???
}

class Circle : public Shape
{
	// ...
};
void fv(vector<Shape>&);
void f(Shape&);
void g(vector<Circle& vd, Circle& d)
{
	f(d); // ok
	fv(vd); // error
}

void poor(Shape* p, int sz);
void general(vector<Shape>&);