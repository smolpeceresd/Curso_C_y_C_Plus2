#ifndef PALABRA_H
#define PALABRA_H


class Palabra
{
public:
    Palabra();
    Palabra(char palabra_[100],int cantidad_);
    ~Palabra();

    int getCantidad() const;
    void setCantidad(int newCantidad);

    void setPalabra(char palabra_ [100]);
    char* getPalabra() const;

    Palabra *getNextPalabra() const;
    void setNextPalabra(Palabra *newNextPalabra);

private:
    int cantidad;
    char palabra[100];
    Palabra *nextPalabra;
};

#endif // PALABRA_H
