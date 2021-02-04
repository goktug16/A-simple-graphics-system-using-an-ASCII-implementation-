#include "graphic_system.h"

void drawHome()
{
	DispWindow Wind(100, 100);

	// front wall
	Rectangle r1(Point(20, 40), Point(80, 80));
	Wind.draw(r1);

	// roof - right side
	Line line1(r1.ne(), r1.n().up(30));
	Wind.draw(line1);

	// roof - left side
	Line line2(Wind.current(), r1.nw());
	Wind.draw(line2);

	// left window
	Rectangle r2(r1.nw().down(10) + Point(10, 0), r1.nw().down(10) + Point(20, 10));
	Wind.draw(r2);

	// right window
	Rectangle r3(r1.ne().down(10) + Point(-20, 0), r1.ne().down(10) + Point(-10, 10));
	Wind.draw(r3);

	// door
	Rectangle r4(r1.s().up(10) + Point(-10, 0), r1.s() + Point(10, 0));
	Wind.draw(r4);

	// chimney
	Wind.draw(Line(line2.c(), line2.c().up(8)));
	Wind.draw(Line(Wind.current(), Wind.current().right(10)));
	Wind.draw(Line(Wind.current(), Wind.current().down(8)));

	// chimney smoke
	Wind.draw(Dot(Wind.current().up(10).left(4)));
	Wind.draw(Dot(Wind.current().up(2).left(2)));
	Wind.draw(Dot(Wind.current().up(2).left(2)));
	Wind.draw(Dot(Wind.current().up(2).right(2)));

	// front door road
	Wind.draw(Line(r4.sw(), Point(r4.sw().left(10).x, 99)));
	Wind.draw(Line(r4.se(), Point(r4.se().right(10).x, 99)));
	Wind.show();

}

void drawRectangles()
{
	DispWindow Wind(50, 50);

	
	for (int i = 0; i < 10; i++)
		Wind.draw(Rectangle(Wind.current(),Wind.current().right(10).down(10)));
	
	Wind.show();
}

void drawLines()
{
	DispWindow Wind(200, 200);

	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
			Wind.draw(Line(Wind.current(), Wind.current().right(10).down(10)));

		Wind.current(Point(0, j*10));
	}
	Wind.show();
}

void drawDots()
{
	DispWindow Wind(150, 100);

	for (int j = 0; j < 30; j++)
	{
		for (int i = 0; i < 30; i++)
		{
			Wind.draw(Dot(Wind.current()));
			Wind.current(Wind.current().right(10).down(10));
		}

		Wind.current(Point(0, j * 10));
	}
	Wind.show();
}

int main()
{
	drawDots();
	
	// uncomment the following lines in order to test your program

	// drawRectangles();
	// drawLines();
	// drawHome();
}
