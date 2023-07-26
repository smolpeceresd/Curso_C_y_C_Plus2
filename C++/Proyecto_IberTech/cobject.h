#ifndef COBJECT_H
#define COBJECT_H

template <typename T>
class CObject
{
public:
    CObject(const T & dato_);
    ~CObject();

    T getDato() const;
    void setDato(const T &newDato);

private:
    T dato;
};

#endif // COBJECT_H
