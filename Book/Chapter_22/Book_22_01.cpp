void draw_all(vector<Shape*>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		v[i]->dwaw();
	}
}

void draw_all(vector<Shape*>& v)
{
	for_each(v.begin(), v.end(), mem_fun(&Shape::draw));
}

template<typename Iter>
void draw_all(Iter b, Iter e)
{
	for_each(b, e, mem_fun(&Shape::draw));
}

int main()
{
	Point p{ 0, 100 };
	Point p2{ 50, 50 };
	Shape* a[] = { new Circle{ p, 50 }, new Triangle{ p, p2, Point{ 25, 25 } } };
	draw_all(a, a + 2);
}

void draw_all(Container& c)
{
	for (auto& p : c)
	{
		p->draw();
	}
}