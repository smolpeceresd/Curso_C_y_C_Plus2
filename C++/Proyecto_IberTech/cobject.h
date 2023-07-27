#ifndef COBJECT_H
#define COBJECT_H


template <typename T>
class CObject
{
public:
    CObject(const T & dato);
    ~CObject();

    T getDato() const;

    virtual void print() const = 0;
    virtual void toString() const =0;
private:
    T dato;
};

template<typename T>
CObject<T>::CObject(const T & dato)
{
    this->dato=dato;
}

template<typename T>
CObject<T>::~CObject()
{

}

template<typename T>
T CObject<T>::getDato() const
{
    return dato;
}

#endif // COBJECT_H
