#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    // private:
    //     Node<T>* head;
    //     Node<T>* tail;
    //     int nodes;
    public:
        DoubleList() : List<T>() {}

        ~DoubleList(){
            clear();
        }
        
        T front(){
            return this->head->data;
        };

        T back(){
            return this->tail->data;
        };

        void push_front(T value){
            Node<T> *nodo = new Node<T>(value);
            nodo->prev = nullptr;
            nodo->next = this->head;

            if(this->head == nullptr){
                this->head = nodo;
                this->tail = nodo;
            } else {
                this->head = nodo;   
                nodo->next->prev = nodo;
            }
            this->nodes++;
        };

        void push_back(T value){
            Node<T> *nodo = new Node<T>(value);
            nodo->next = nullptr;
            nodo->prev = this->tail;

            if(this->head == nullptr) {
                this->head = nodo;
                this->tail = nodo;
            } else {
                this->tail->next = nodo;
                this->tail = this->tail->next;
            }
            this->nodes++;
        };

        T pop_front(){
            if (is_empty()){
                throw "Empty list";
            }
            T data = this->head->data;
            if(this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = this->head->next;
            }

            delete this->head->prev;
            this->head->prev = nullptr;
            this->nodes--;
            return data;
        };

        T pop_back(){
            if (is_empty()){
                throw "[ERROR] -> Empty list";
            }

            T data = this->tail->data;
            if(this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
            }

            delete this->tail->next;
            this->tail->next = nullptr;
            this->nodes--;
            return data;
        };

        T insert(T value, int pos){
            Node<T> *temp = this->head;
            int i = 0;
            while (i < pos - 1){
                temp = temp->next;
                i++;
            }
            Node<T> *newnode = new Node<T>(value);
            newnode->next = temp->next;
            newnode->prev = temp;

            temp->next->prev = newnode;
            temp->next = newnode;
            this->nodes++;
            return newnode->data;
        };

        bool remove(int pos){
            if (is_empty()){
                throw "[ERROR] -> Empty list";
            }

            Node<T> *temp = this->head;
            for (int i = 0; temp != nullptr && i < pos - 1; i++)
            {
                temp = temp->next;
            } 

            temp->next = temp->next->next;
            delete temp->next;
            temp->next->prev = temp;
            return true;
        }

        T& operator[](int index){
            Node<T> *temp = this->head;
            int i = 0;
            while (i < index){
                temp = temp->next;
                i++;
            }
            return temp->data;
        };

        bool is_empty(){
            return this->head == nullptr ? true : false;
        };

        int size() {
            return this->nodes;
        };

        void clear(){
            while (this->head != nullptr){
                this->head = this->head->next;
                this->head = nullptr;
                delete this->head;
            }
            this->head = nullptr;
            this->tail = nullptr;
            this->nodes = 0;
        };

        void sort(){
            Node<T> *temp = this->head;
            while (temp) { 
                Node<T> *min = temp; 
                Node<T> *r = temp->next;
                while (r) { 
                    if (min->data > r->data) {
                        min = r; 
                    }
                    r = r->next; 
                } 
                int x = temp->data; 
                temp->data = min->data; 
                min->data = x; 

                temp = temp->next; 
            } 
        };

        bool is_sorted(){
            for (int i = 0; i < this->nodes - 1; ++i)
            {
                if ( operator[](i) > operator[](i+1))
                {
                    return false;
                }
            }
            return true;
        };
        
        void reverse(){
            // List<int> *reverse = new DoubleList<int>();
            // Node<T> *temp = this->head; 

            // while (temp != nullptr) { 
            //     reverse->push_front(temp->data);
            //     temp = temp->next;
            // } 
            throw ("sin definir");
        };

        string name() {
            return "Double List";
        };
};
#endif