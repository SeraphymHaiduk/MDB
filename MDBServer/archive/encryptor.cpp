#include "encryptor.h"
#include <random>
#include "time.h"
#include <QtCore>
unsigned long long int Encryptor::generatePriKey(){
    srand(time(0));
    unsigned long long a = (unsigned long int)rand();
    a = (a<<32)+(unsigned long int)rand();
    return a;
}



unsigned long int Encryptor::generatePartKey(unsigned long a, unsigned long long pri,unsigned long b){

    if(b < a){
        unsigned long c;
        c = b;
        b = a;
        a = c;
    }

    unsigned long d = Encryptor::moduleDivide(a,pri,b);
        return d;
}

unsigned long int Encryptor::moduleDivide(unsigned long int number, unsigned long long power, unsigned long int n)
{
  unsigned long long res = 1;
  while (power)
  {
    if (power % 2)
      res = (1ull * res * number) % n;
    number = (1ull * number * number) % n;
    power /= 2;
  }
  return (unsigned long)res;
}
