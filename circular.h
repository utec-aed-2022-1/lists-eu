#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    // private:
    //     Node<T>* head;//sentinel
    //     int nodes; 
    public:
        CircularList() : List<T>() {}

        ~CircularList() {
           clear();
        };

        T front() {
            return this->head->data;
        };

        T back() {
            return this->head->data;
        };

        void push_front(T value) {
            Node<T> *nodo = new Node<T>(value);
            if (this->head == nullptr) {
                this->head = nodo;
                this->tail = nodo;
                this->tail->next = this->tail;
            } else { 
                nodo->next = this->tail->next;
                this->head = nodo;
            }
            this->nodes++;
        };

        void push_back(T value){
            Node<T> *nodo = new Node<T>(value);
            if(this->head == nullptr) {
                this->head = nodo;
                this->tail = nodo;
            } 
            nodo->next = this->tail->next; 
            this->tail->next = nodo; 
            this->tail = nodo;

            this->nodes++;
        };

        T pop_front(){
            if (is_empty()) {
                throw "[ERROR] -> Empty list";
            }
            
            T data = this->head->data;
            Node<T> *oldhead = this->head;
            if(this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = this->head->next;
                this->tail->next = this->head;
            }
            delete oldhead;
            this->nodes--;
            return data;
        };

        T pop_back(){
            if (is_empty()) {
                throw "[ERROR] -> Empty list";
            }

            T data = this->tail->data;
            Node<T> *temphead = this->head;
            if(this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                while (temphead->next != this->tail) {
                    temphead = temphead->next;
                }
                this->tail = temphead;
                delete this->tail->next;
                this->tail->next = this->head;
            }
            this->nodes--;
            return data;
        };

        T insert(T value, int pos){
            if (pos >= this->nodes) {
                throw "[ERROR] -> List is full";
            }

            Node<T> *temp = this->head;
            int i = 0;
            while (i < pos - 1){
                temp = temp->next;
                i++;
            }
            Node<T> *newnode = new Node<T>(value);
            newnode->next = temp->next;
            temp->next = newnode;
            this->nodes++;
            return newnode->data;
        };

        bool remove(int pos){ 
            if (is_empty()) {
                // throw "[ERROR] -> Empty list";
                return false;
            }

            Node<T> *temp = this->head;
            for (int i = 0; temp != this->tail && i < pos - 1; i++)
            {
                temp = temp->next;
            } 

            Node<T> *next = temp->next->next;
            delete temp->next;
            temp->next = next;
            return true;
        } 

        T& operator[](int index){
            Node<T> *temp = this->head;
            int i = 0;
            while (i < index) {
                temp = temp->next;
                i++;
            }
            return temp->data;
        };

        bool is_empty(){
            return this->tail == nullptr ? true : false;
        };

        int size() {
            return this->nodes;
        };

        void clear(){
            while (this->head != this->tail) {
                this->head = this->head->next;
                this->head = nullptr;
                delete this->head;
            }
            this->head = this->tail;
            this->tail = this->head;
            this->nodes = 0;
        };

        void sort(){
            Node<T> *temp = this->head;     
            while (temp != this->tail) { 
                Node<T> *min = temp; 
                Node<T> *r = temp; 
                while (r != this->tail) { 
                    r = r->next; 
                    if (min->data > r->data) {
                        min = r; 
                    }
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
                if ( operator[](i) > operator[](i+1)) {
                    return false;
                }
            }
            return true;
        };

        void reverse(){
            // List<int> *reverse = new CircularList<int>();
            // Node<T> *temp = this->head;

            // while (temp != this->tail) { 
            //     reverse->push_front(temp->data);
            //     temp = temp->next;
            // } 
            // reverse->push_front(temp->data);
            // return reverse; 
            throw ("sin definir");
        };

        string name() {
            return "Circular List";
        }      
};

#endif