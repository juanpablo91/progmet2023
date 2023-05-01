#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
#include <cmath>

using fptr = double(double);
using alptr = double(fptr, double, double);

double derivForward(fptr f,double x, double h);
double derivCentral(fptr g,double x, double h);
double extraRichardson(alptr I,fptr s,double n,double x, double h);
double sen(double x);

int main(int argc, char **argv) {
  const double x = M_PI/3.0; 
  const double exact = std::cos(x);

  std::ofstream fout("datos.txt"); 
  for(int p = -1; p >= -18; p--) {
    double h = std::pow(10.0, p);
    double forward = derivForward(sen,x, h);
    double central = derivCentral(sen,x, h);
    double richcarsonForward = extraRichardson(derivForward,sen, 1, x , h);
    double richcarsonCentral = extraRichardson(derivCentral,sen, 2, x , h);

    //fout -> for save the data
    std::cout<< h 
        << "\t" << std::fabs(1.0 - forward/exact)      
        << "\t" << std::fabs(1.0 - central/exact)     
        << "\t" << std::fabs(1.0 - richcarsonForward/exact)     
        << "\t" << std::fabs(1.0 - richcarsonCentral/exact)     
        << "\n";     
  }
  
  fout.close();
  
  return 0;
}

double derivForward( fptr f,double x, double h)
{ 
  return (f(x+h) - f(x))/h;
}

double derivCentral(fptr g,double x, double h)
{
  return (g(x+h/2) - g(x-h/2))/h;
}

double extraRichardson(alptr I,fptr s,double n,double x, double h){
  return (std::pow(2,n) * I(s,x,h/2)- I(s,x,h)) / (std::pow(2,n) -1 );
};

double sen(double x)
{
  return std::sin(x);
}


/*update the functions Derives (forward, central) made in class,
using funtion pointers and make extrapolation Richardson using also funtion pointers

1.functions with function pointers (forward, central);
2.extrapolation richardson (receives forward or central)
3.print the diffs relatives, of forward and central and with Richardson
4. make the picture of thats diff as a funtion of h

Github repository directory: semana 4
https://github.com/juanpablo91/progmet2023/tree/master/semana%204
*/