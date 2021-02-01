#include <stdio.h>
#include <stdlib.h>

typedef void (*func)(struct Shape*);
#define CREATE_OBJECT(object, name) object* name = (object*)malloc(sizeof(object));
#define ADD_FUNCTION(name, p_func, func) name->shape.functions->p_func = &func;

struct Functions
{
	func draw;
};

struct Shape
{
	int x;
	int y;
	struct Functions* functions;
};

struct Circle
{
	struct Shape shape;
	int radius;
};

struct Rectangle
{
	struct Shape shape;
	int width;
	int height;
};

void draw(struct Shape* shape)
{
	shape->functions->draw(shape);
}

void draw_shape(struct Shape* shape)
{
	printf("Shape :: Draw\nx = %d, y = %d\n", 
		shape->x, shape->y);
}

void draw_circle(struct Shape* shape)
{
	struct Circle* circle = (struct Circle*)shape;
	printf("Cicle :: Draw\nx = %d, y = %d, radius = %d\n", 
		circle->shape.x, circle->shape.y, circle->radius);
}

void draw_rectangle(struct Shape* shape)
{
	struct Rectangle* rectangle = (struct Rectangle*)shape;
	printf("Rectangle :: Draw\nx = %d, y = %d, width = %d, height = %d\n", 
		rectangle->shape.x, rectangle->shape.y, rectangle->width, rectangle->height);
}

struct Shape* shapeCreate(int x, int y)
{
	CREATE_OBJECT(struct Shape, shape);
	CREATE_OBJECT(struct Functions, functions);
	functions->draw = &draw_shape;
	shape->functions = functions;
	shape->x = x;
	shape->y = y;
	return shape;
}

struct Shape* circleCreate(int x, int y, int radius)
{
	CREATE_OBJECT(struct Circle, circle);
	circle->shape = *shapeCreate(x, y);
	ADD_FUNCTION(circle, draw, draw_circle);
	circle->radius = radius;
	return circle;
}

struct Shape* rectangleCreate(int x, int y, int width, int height)
{
	CREATE_OBJECT(struct Rectangle, rectangle);
	rectangle->shape = *shapeCreate(x, y);
	ADD_FUNCTION(rectangle, draw, draw_rectangle);
	rectangle->width = width;
	rectangle->height = height;
	return rectangle;
}

int main()
{
	struct Shape* shape = shapeCreate(1, 4);
	struct Circle* circle = circleCreate(1, 2, 3);
	struct Rectangle* rectangle = rectangleCreate(1, 10, 5, 10);
	draw(shape);
	draw(circle);
	draw(rectangle);
}