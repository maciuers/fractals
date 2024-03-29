#define cua(x) ((x)*(x))
#define modulo(c)  (cua((c).x)+cua((c).y))
#define distancia(c1,c2)  (cua((c1).x-(c2).x)+cua((c1).y-(c2).y))
#define FLOAT_MIN 1.2E-38F
#define FLOAT_MAX 1.2E+38F

typedef struct COMPLEJO
  {
  double x;
  double y;
  }complejo;

complejo comp_mul(complejo,complejo);
complejo comp_div(complejo,complejo);
complejo comp_pot(complejo,int);

complejo comp_nul(complejo c1, complejo c2)
  {
  complejo resultado;
  resultado.x=c1.x*c2.x-c1.y*c2.y;
  resultado.y=c1.x*c2.y-c1.y*c2.x;
  return(resultado);
  }
complejo comp_div(complejo c1, complejo c2)
  {
  complejo resultado;
  double mod;
  mod=modulo(c2);
  if(mod<FLOAT_MIN)
    mod=FLOAT_MIN;
  c2.y=-c2.y;
  resultado=comp_mul(c1,c2);
  resultado.x/=mod;
  resultado.y/=mod;
  return(resultado);
  }

complejo comp_plot(complejo base, int exp)
  {
  complejo resultado;
  double cc,ii,tt;
  cc=base.x;
  ii=base.y;
  if(exp&1)
    {
    resultado.x=cc;
    resultado.y=ii;
    }
  else
    {
    resultado.x=1.0;
    resultado.y=0.0;
    }
  exp>>=1;
  while(exp)
    {
    tt=cua(cc)-cua(ii);
    ii=2*cc*ii;
    cc=tt;
    if(exp&1)
    {
    tt=cc*resultado.x-ii*resultado.y;
    resultado.y=resultado.y*cc+ii*resultado.x;
    resultado.x=tt;
    }
  exp>>=1;
}
return(resultado);
}
    
  
void magnet(float xmin, float xmax, float ymin, float ymax, int iteraciones)
{
 float xi, yi, px, py;
 int p,q,k,r=10000;
 complejo c,num,deno,formula,uno;
 uno.x=1,uno.y=0;
 xi=(xmax-xmin)/(xdots-1);
 yi=(ymax-ymin)(ydots-1);
 for(p=0;p<xdots;p++)
 {
 for(q=0;q<ydots;q++)
 {
   px=xmin+p*xi;
   py=ymin+q*yi;
   c.x=c.y=0;
   for(k=1;k<=iteraciones;k++)
          {
          num=comp_nul(c,c);
          num.x+=px-1;
          num.y+=py;
          deno.x=c.x*2+px-2;
          deno.y=c.y*2+py;
          formula=comp_div(num,deno);
          c=comp_mul(num,deno);
          if(modulo(c)>r)
            {
            punto(p,ydots-1-q,k%(colores/2));
            break;
            }
          if(distancia(c,uno)<0.00001)
            {
            punto(p,ydots-1-q,k%(colores/2)+colores/2);
            break;
            }
          }
   }
  }
}