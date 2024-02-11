void figura(float xo, float yo)
{
    long i;
    int xp,yp,col=9;
    double xx,yy,x,y,xa;
    x=xo;
    y=yo;
    for(i=1; !kbhit();i++)
    {
        xa=x<0?-x:x;
        xx=1-y+xa;
        yy=x;
        x=xx;
        y=yy;
        xp=x*30+260;
        yp=300-(y*30);
        if(i%250==0)
          if(++col==15)
          col=9;
        punto(xp,yp,col);
    }
}