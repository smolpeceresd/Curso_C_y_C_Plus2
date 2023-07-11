#ifndef CIRCULANTE_H
#define CIRCULANTE_H
#include <iostream>
using namespace std;

class Circulante
{
public:
    Circulante(bool circulante_no_circulante);
    ~Circulante();

    bool getCirculante_no_circulante() const;
    void setCirculante_no_circulante(bool newCirculante_no_circulante);

private:
    bool circulante_no_circulante;
};

#endif // CIRCULANTE_H
