void conexo(float c1, float c2)
    {
        int k, iteraciones=250;
        float x,y, xx=0, yy=0;
        for(k=1,k<=iteraciones;k++)
        {
            x=xx*xx-yy*yy+c1;
            y=2*xx*yy+c2;
            xx=x;
            yy=y;
            if(x*x+y*y>4)
            print("\nConjunto no conexo.");
            exit(0);
        }
        }
    print("\nConjunto conexo.");
    }