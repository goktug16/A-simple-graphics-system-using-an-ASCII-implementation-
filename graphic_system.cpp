#include "graphic_system.h""
#include <iostream>

using namespace std;

DispWindow::DispWindow(int x,int y)
{
    size_x = x ; 
    size_y = y ;
   
   window = new char*[y];

    for(int i=0 ; i<y; i++)
        window[i] = new char [x];

    for(int i=0 ; i< y;i++)
        for(int j=0;j<x; j++)
            window[i][j]= ' ';
}

Point& Point::operator =(Point & a )
{
    this->x = a.x; 
    this->y= a.y; 
    return *this; 
}
Point Point::operator+(const Point & b)
{
    Point result; 
    result.x = this->x+b.x;
    result.y = this->y+b.y; 
    return result;
}
Point Shape::e()
{
    if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    {   
        d.x= a->myse.x;

        d.y = a->myse.y - (a->myse.y - a->mynw.y) / 2;
    } 
    return d;    
}
Point Shape::w()
{   
    if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    {
        b.x = a->mynw.x;

        b.y = a->myse.y - (a->myse.y - a->mynw.y) / 2;
    }
    return b;
}
Point Shape::se()
{
    if(Rectangle *a=dynamic_cast<Rectangle*>(this))
        gd=a->myse;
    if(Line *a=dynamic_cast<Line*>(this))
        gd=a->bottom; 
    return gd;
}
Point Shape::nw()
{
    if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    { 
        kb= a->mynw;
    }
    if(Line *a=dynamic_cast<Line*>(this))
    {
        kb = a->top;
    }
    return kb;
}
Point Shape::n()
{
    if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    { 
        k.y = a->mynw.y; 

        k.x = a->myse.x - (a->myse.x - a->mynw.x)/2 ;
    }
    if(Line *a=dynamic_cast<Line*>(this))
    {
        k = a->top;
    }
    return k;
}
Point Shape::s()
{
   if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    { 
        g.y = a->myse.y; 

        g.x = a->myse.x - (a->myse.x - a->mynw.x)/2 ;
    }
    if(Line *a=dynamic_cast<Line*>(this))
    {
        g= a->bottom;
    }
    return g;
}
Point Shape::ne()
{
   if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    { 
      kb.y = a->mynw.y;
      kb.x= a->myse.x;
    }
    if(Line *a=dynamic_cast<Line*>(this))
    {
        kb = a->top;
    }
    return kb;
}
Point Shape::sw()
{
   if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    { 
       gb.y = a->myse.y; 
       gb.x = a->mynw.x;
    }
    if(Line *a=dynamic_cast<Line*>(this))
    {
        gb = a->bottom;
    }
    return gb;
}
Point Shape::c()
{
    if(Rectangle *a=dynamic_cast<Rectangle*>(this))
    { 
        m.x = (a->myse.x+ a->mynw.x) / 2;
        m.y = (a->myse.y + a->mynw.y) /2;  
    }
    if(Line *a=dynamic_cast<Line*>(this))
    {
        m.x = (a->bottom.x+ a->top.x) / 2;
        m.y = (a->top.y + a->bottom.y) /2;  
    }
     if(Dot *a=dynamic_cast<Dot*>(this))
    {
        m.x = a->dd.x;
        m.y = a->dd.y;
    }
    
    return m;
}
Point DispWindow::current()
{
    return w_current;
}
Point DispWindow::current(Point p)
{
    w_current = p;
    return w_current;
}

void DispWindow::draw(Rectangle r)
{
    w_current.x = r.se().x;
    w_current.y = r.se().y;
  
   for(int i=0 ; (r.nw().x+i) <= r.ne().x; i++)
   {
       if(r.nw().x + i < size_x && r.nw().y < size_y)
        window[r.nw().y][r.nw().x+i] = '*';
        if(r.sw().y < size_y && r.sw().x+i < size_x)
        window[r.sw().y][r.sw().x+i] = '*';
   }

   for(int i=1; r.nw().y+i < r.se().y; i++)
   {
      if(r.nw().y + i < size_y && r.nw().x < size_x)
       window[r.nw().y+i][r.nw().x] = '*';
    if(r.ne().y + i < size_y && r.ne().x < size_x)
       window[r.ne().y+i][r.ne().x] = '*'; 
   }
}

void DispWindow::show()
{
    for(int i=0; i<size_y ; i++)
    {
        for(int j=0 ;j<size_x ; j++)
            cout<<window[i][j]; 
        cout<<endl;
    }
}
void DispWindow::draw(Dot d)
{
    w_current.x = d.dd.x;
    w_current.y = d.dd.y;
    if(d.dd.x >= size_x || d.dd.y >= size_y)
        return;
    window[d.dd.y][d.dd.x] = '*';
}

Point Point::right(int a)
{
    this->x = this->x +a; 
    return *this;
}
Point Point::left(int a)
{
    this->x= this->x-a;
    return *this; 
}
Point Point::up(int a)
{
    this->y = this->y -a;
    return *this;
}
Point Point::down(int a )
{
    this->y = this->y + a; 
    return *this;
}

void DispWindow::draw(Line lin)
{
    w_current.x = lin.second.x;
    w_current.y = lin.second.y;
    double slope;
    if(lin.bottom.x == lin.top.x)
    {
        for(int i=0 ; lin.bottom.y-i >= lin.top.y; i++)
        {
              if(lin.bottom.y-i <size_y && lin.bottom.x < size_x)
                    window[lin.bottom.y-i][lin.bottom.x] = '*';  
        }
        return;
    }
   slope = (double)(lin.bottom.y - lin.top.y) / (double)(lin.bottom.x - lin.top.x);
    if(slope == 0)
     {
         for(int i=0 ; lin.first.x+i <= lin.second.x; i++)
        {
            if(lin.first.x+i < size_x && lin.first.y < size_y)
                window[lin.first.y][lin.first.x+i]= '*';
        }
     }
    double left;
    double right;
    if(slope == -1)
    {
        left =lin.bottom.x;
        right=lin.top.x;

        for(int i=0 ; lin.bottom.x +i <= lin.top.x ;i++)
        {
            if(lin.bottom.x+i < size_x && lin.bottom.y-i <size_y)
                window[lin.bottom.y-i][lin.bottom.x+i]= '*';
        }
    }
    if(slope==1)
    {
        for(int i= 0 ; lin.top.x+i <= lin.bottom.x ; i++)
        {
                if(lin.top.x+i < size_x && lin.top.y+i < size_y)
                    window[lin.top.y+i][lin.top.x+i]= '*';
        }
    }

    if(slope != 1 && slope!= -1 && slope != 0)
    {
        double y;
        if(slope < 0)
        {
           int firstflag=0;
            left = lin.bottom.x;
            right =lin.top.x;
            right++;
            for(left; left+1 < right ; left+=0.001)
            {
                 y = slope*(left-lin.bottom.x)+ lin.bottom.y;
                if(firstflag==0)
                {
                    firstflag++;
                 window[(int)y][(int)left] = '*';
                }
                 else
                     window[(int)y][(int)left+1]='*';
                 
            }
        }

        if(slope > 0 )
        {
            
            left=lin.top.x; 
            right = lin.bottom.x;
            for(right ; right >left ; right-= 0.001)
            {
                y=slope*(right-lin.bottom.x)+ lin.bottom.y;
                if(right <size_x && y <size_y)
                    window[(int)y][(int)right]= '*';
            }
        }
}
} 
