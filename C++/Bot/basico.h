#ifndef BASICO_H
#define BASICO_H

#include <iostream>
using namespace std;

class Basico
{
public:
    Basico(const string tag, const string respuesta);
    ~Basico();

    const string &getTag() const;
    void setTag(const string &newTag);

    const string &getRespuesta() const;
    void setRespuesta(const string &newRespuesta);

private:
    string tag,respuesta;
};

#endif // BASICO_H
