#ifndef KONTENER_H
#define KONTENER_H

#include "Dane.h"
#include <string>
template <typename Type>
struct Kontener
{
public:
    Kontener() = default;
    ~Kontener();
    void wstaw(Type);
    Type Zdejmij();
    int len(){
    return counter;
    }


private:
    struct Node
    {
        Node *nast;
        Type data;
        Node(Type D, Node *N = nullptr)
        {
            data = D;
            nast = N;
        }
    };
    Node *pocz = nullptr;
    int counter = 0;

};

template <typename Type>
Kontener<Type>::~Kontener()
{
    while(pocz != nullptr)
    {
        Node *killer = pocz;
        pocz = pocz -> nast;
        delete killer;
    }
}

template <typename Type>
void Kontener<Type>::wstaw(Type data)
{
    counter++;
    Node *NewNode = new Node(data);
    if(pocz == nullptr)
        pocz = NewNode;
    else
    {
            Node *Runner = pocz;
            Node *PreRunner;
            while(Runner != nullptr && Runner->data >= NewNode ->data)
            {
                PreRunner = Runner;
                Runner = Runner -> nast;
            }
            if(Runner == pocz){
                pocz -> nast = NewNode;
                pocz = NewNode;
            }
            else{
            PreRunner->nast = NewNode;
            NewNode -> nast = Runner;

        }
    }
}

template <typename type>
type Kontener<type>::Zdejmij(){
    if(pocz == nullptr || counter == 0)throw logic_error("List is empty");
    Node *killer = pocz;
    type DoZdjecia;
    DoZdjecia = killer->data;
    pocz = pocz->nast;
    delete killer;
    counter--;
    return DoZdjecia;
}



#endif // KONTENER_H
