class Point
{   public:
       Point(); 
       Point(int xx,int yy);
	   Point(Point & p);
       ~Point();
       void Move(int x,int y);
       int GetX() {return X;}
       int GetY() {return Y;}
	   void Display();
  private:
       int  X,Y;
};