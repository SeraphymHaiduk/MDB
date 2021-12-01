#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H


namespace Encryptor
{
    unsigned long long int generatePriKey();
    unsigned long int generatePartKey(unsigned long a, unsigned long long pri,unsigned long b);
    unsigned long int generateFullKey(unsigned long part,unsigned long pri, unsigned long p);
    unsigned long int moduleDivide(unsigned long int number, unsigned long long int power, unsigned long int n);
}

#endif // ENCRYPTOR_H
