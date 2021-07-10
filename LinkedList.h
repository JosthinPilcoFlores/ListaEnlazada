#include <iostream>
#include <string>
#include "Node.h"
class LinkedList{
    int size;
    //Getter
    Node* getHead()const;
    public:
        Node* head;
        LinkedList();
        LinkedList(int);
        //Getter
        int getSize()const;
        //Funciones Miembro
        void insert(int);
        void insertarElementos(char,int);
        void remove(int);
        void print();
        //Destructor
        ~LinkedList();
        friend std::ostream& operator<<(std::ostream &o, const LinkedList &a);
};
LinkedList::LinkedList(){
    size = 1;
    head = new Node();
    head->next=NULL;
}
LinkedList::LinkedList(int size){
    this->size = 0;
    head = new Node();
    head = NULL;
    int n;
    for(int i=0;i<size;i++){
        std::cout<<"Ingrese numero: "; std::cin>>n;
        insert(n);
    }
}
int LinkedList::getSize()const{
    return size;
}
Node* LinkedList::getHead()const{
    return head;
}
void LinkedList::insert(int n){
    Node* nuevo_nodo = new Node();
    nuevo_nodo->elem = n;
    Node* aux1 = head;
    Node* aux2;
    while((aux1 != NULL) && (aux1->elem<n)){
        aux2 = aux1;
        aux1 = aux1->next;
    }
    if(head == aux1){
        head = nuevo_nodo;
    }else{
        aux2->next = nuevo_nodo;
    }
    nuevo_nodo->next=aux1;
    size+=1;
    std::cout<<"Elemento "<<n<<" insertado correctamente\n";
    system("pause");
    system("cls");
}
void LinkedList::remove(int n){
    if(head != NULL){
        Node* auxBorrar;
        Node* anterior = NULL;
        auxBorrar = head;
        while((auxBorrar != NULL) && (auxBorrar->elem != n)){
            anterior = auxBorrar;
            auxBorrar = auxBorrar->next;
        }
        if(auxBorrar == NULL){
            std::cout<<"El elemento "<<n<<" no existe\n";
        }else if(anterior == NULL){
            std::cout<<"Eliminando elemento "<<n<<std::endl;
            size-=1;
            head = head->next;
            delete auxBorrar;
        }else{
            std::cout<<"Eliminando elemento "<<n<<std::endl;
            size-=1;
            anterior->next = auxBorrar->next;
            delete auxBorrar;
        }
    }else{
        std::cout<<"Elemento "<<n<<" no existe\n";
    }
}
void LinkedList::print(){
    Node* actual = new Node();
    actual = head;
    std::cout<<"Mostrando elementos de la lista enlazada:\n";
    while(actual != NULL){
        std::cout<<actual->elem<<" -> ";
        actual=actual->next;
    }
    std::cout<<std::endl;
}
LinkedList::~LinkedList(){
    std::cout<<"\nInicializando Destruccion...\n";
    while(head != NULL){
        remove(head->elem);
    }
}
void LinkedList::insertarElementos(char opc,int n){
    do{
        std::cout<<"Numero: "; std::cin>>n;
        insert(n);
        std::cout<<"Desea ingresar otro elemento?\n(Digite \"s\" si su respuesta es afirmativa, caso contrario cualquier otra letra)\n";
        std::cin>>opc;
        system("cls");
    }while(opc=='s'||opc=='S');
}
std::ostream& operator<< (std::ostream &o, const LinkedList &a){
    Node* actual = new Node();
    actual = a.head;
    while(actual != NULL){
        o<<actual->elem<<" -> ";
        actual=actual->next;
    }
    o<<'\n';
    return o;
}