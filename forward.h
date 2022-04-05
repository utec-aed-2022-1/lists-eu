#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    // private:
        // Node<T>* head;
        // int nodes;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
         	clear();      
        }

        T front(){
            return this->head->data;
        }

        T back(){
            return this->tail->data;
        }

        void push_front(T data){
            Node<T> *nodo = new Node<T>(data);
            nodo->next = this->head;

            if(this->head == nullptr){
                this->head = nodo;
                this->tail = nodo;
            } else {
                this->head = nodo;   
            }
            this->nodes++;
        }

        void push_back(T data){
            Node<T> *nodo = new Node<T>(data);
            nodo->data = data;
            nodo->next = nullptr;

            if(this->head == nullptr) {
                this->head = nodo;
                this->tail = nodo;
            } else {
                this->tail->next = nodo;
                this->tail = this->tail->next;
            }
            this->nodes++;
        }

        T pop_front(){
            if (is_empty()){
                throw "[ERROR] -> Empty list";
            }
            T data = this->head->data;
            Node<T> *oldhead = this->head;
            if(this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = this->head->next;
            }

            delete oldhead;
            this->nodes--;
            return data;
        }

        T pop_back(){
            if (is_empty()){
                throw "[ERROR] -> Empty list";
            }
            T data = this->tail->data;
            Node<T> *temphead = this->head;

            if(this->head == this->tail) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                while (temphead->next->next != nullptr) {
                    temphead = temphead->next;
                }
                this->tail = temphead; 
                this->tail->next = nullptr;
            }

            delete this->tail->next;
            this->nodes--;
            return data;
        }

        T insert(T data, int pos){
            if (pos >= this->nodes) {
                throw "[ERROR] -> List is full";
            }
            Node<T> *temp = this->head;
            int i = 0;
            while (i < pos - 1){
                temp = temp->next;
                i++;
            }
            Node<T> *newnode = new Node<T>(data);
            newnode->next = temp->next;
            temp->next = newnode;
            this->nodes++;
            return newnode->data;
        }

        bool remove(int pos){
            if (is_empty()){
                // throw "[ERROR] -> Empty list";
                return false;
            }

            Node<T> *temp = this->head;
            for (int i = 0; temp != nullptr && i < pos - 1; i++){
                temp = temp->next;
            } 

            Node<T> *next = temp->next->next;
            delete temp->next;
            temp->next = next;
            return true;
        }

        T& operator[](int pos){
            Node<T> *temp = this->head;
            int i = 0;
            while (i < pos){
                temp = temp->next;
                i++;
            }
            return temp->data;
        }

        bool is_empty(){
            return this->head == nullptr ? true : false;
        }

        int size(){
            return this->nodes;
        }

        void clear(){
            while (this->head != nullptr){
                this->head = this->head->next;
                this->head = nullptr;
                delete this->head;
            }
            this->head = nullptr;
            this->nodes = 0;
        }
        
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
        }

        bool is_sorted(){
            for (int i = 0; i < this->nodes - 1; ++i) {
                if ( operator[](i) > operator[](i+1)) {
                    return false;
                }
            }
            return true;
        }

        void reverse(){
            // List<int> *reverse = new ForwardList<int>();
            // Node<T> *temp = this->head;

            // while (temp != nullptr) { 
            //     reverse->push_front(temp->data);
            //     temp = temp->next;
            // } 
            // return reverse;
            throw("sin definir");
        }

        std::string name(){
            return "Forward List";
        }
        
};

#endif