class DispWindow;
class Point
{
    public:
        int x,y;

        Point(int x_c=0,int y_c=0)
        :x(x_c),y(y_c){}

        Point right(int a=1);
        Point left(int a=1);
        Point up(int a=1); // reducing y coordinate 
        Point down(int a=1);

        Point& operator =(Point&);
        Point operator +(const Point&);

};
class Shape
{
    public:
        virtual void draw(DispWindow& w)=0;
        Point d,b,k,g,kd,kb,gd,gb,m;
        Point e();
        Point w();
        Point n();
        Point s();
        Point ne();
        Point nw();
        Point se();
        Point sw();
        Point c();

};

class Line : public Shape
{
    public: 
        Point top,bottom,first,second;
        Line(Point c ,Point d )
        {
            first= c;
            second = d;
            if(c.y < d.y)
            {
             top=c;
             bottom = d;
            }
            else
            {
                bottom=c;
                top=d;
            }
        }
        void draw(DispWindow& w){}
};

class Rectangle : public Shape
{
    public:
        Point mynw,myse;
        Rectangle(Point c ,Point d )
        {
            mynw=c;
            myse=d;
        }
         void draw(DispWindow& w){}
};


class Dot : public Shape
{
    public:
    Point dd;
        Dot(Point a)
        {
            dd=a;
        }
        void draw(DispWindow& w){}
        
};
class DispWindow : public Point,public Shape
{
    private:
        int size_x,size_y;
        char **window;
        Point w_current;

    public:
        DispWindow(int x,int y);
        void draw(Line); 
        void draw(Rectangle);
        void draw(Dot);
        void draw(DispWindow &a){};
        Point current(Point a);
        Point current();
        void show(); 
};

