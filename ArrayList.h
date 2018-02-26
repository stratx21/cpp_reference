/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayList.h
 * Author: Josh
 *
 * Created on February 25, 2018, 10:32 PM
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

using namespace std;

template <class T>
class ArrayList{
private:
    constexpr static int CAPACITY_INITIAL = 3;
    constexpr static int CAPACITY_INCREMENT = 3;
    
    int used;
    int capacity;
    T* array;
    
    void resize();
    bool resize(int newSize);
public:
    ArrayList();
    ~ArrayList();
    
    ArrayList(const ArrayList& that);
    
    ArrayList<T>& operator=(const ArrayList& that);
    
    T& operator[](int index);
    
    /**
     * This function retrieves the object at index.
     * 
     * @param index the index to retrieve from
     */
    T get(int index);
    
    /**
     * This function adds the object toAdd to the end of the list. 
     * 
     * @param toAdd the object to add to the end of the list. 
     */
    void add(T toAdd);
    
    /**
     * This function adds the object toAdd at the index index.
     * 
     * @param index the index to add it to
     * @param toAdd the object to add
     * @return bool if it was valid and worked
     */
    bool add(int index,T toAdd);
    
    /**
     * This function sets the object toAdd at the index index and deletes
     *      the object that was previously there. 
     * 
     * @param index the index to set the object at
     * @param toSet the object to set
     * @return bool if it was valid and worked
     */
    bool set(int index,T toSet);
    
    
    T remove(int index);
    ArrayList<T> removeRange(int start,int end);
    bool removeOne(T toRemove);
    bool removeAllOf(T toRemove);
    bool replaceOne(T toReplace,T replacement);
    bool replaceAllOf(T toReplace,T replacement);
    ArrayList<T> getSubArrayList(int start,int end);
    void clear();
    int size();
    void addCapacity(unsigned int toAdd);
    int indexOf(T toFind);
    void trim(int newSize);
};

template <class T>
void ArrayList<T>::resize(){
    this->capacity += CAPACITY_INCREMENT;
    T* temp = new T[this->used];
    for(int element = 0; element < this->used; element++){
        temp[element] = this->array[element];
    }
    
    delete [] this->array;
    this->array = new T[this->capacity];
    
    for(int element = 0; element < this->used; element++){
        this->array[element] = temp[element];
    }
    
    delete [] temp;
}

template <class T>
bool ArrayList<T>::resize(int newSize){
    if(newSize >= this->used){
        this->capacity = newSize;
        T* temp = new T[this->used];
        for(int element = 0; element < this->used; element++){
            temp[element] = this->array[element];
        }

        delete [] this->array;
        this->array = new T[this->capacity];

        for(int element = 0; element < this->used; element++){
            this->array[element] = temp[element];
        }

        delete [] temp;
        
        return true;
    } else{
        return false;
    }
}

template <class T>
ArrayList<T>::ArrayList(){
    this->array = new T[this->CAPACITY_INITIAL];
    this->capacity = this->CAPACITY_INITIAL;
    this->used = 0;
}

template <class T>
ArrayList<T>::~ArrayList(){
    delete [] this->array;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList& that){
    delete [] this->array;
    this->used = that.used;
    this->capacity = that.capacity;
    this->array = new T[this->capacity];
    for(int element = 0; element < this->used; element++){
        this->array[element] = that.array[element];
    }
}

template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& that){
    delete [] this->array;
    this->used = that.used;
    this->capacity = that.capacity;
    this->array = new T[this->capacity];
    for(int element = 0; element < this->used; element++){
        this->array[element] = that.array[element];
    }
    
    return *this;
}

template <class T>
T& ArrayList<T>::operator[](int index){
    if(index < this->used){//in range
        return this->array[index];
    } else{
        return new T;
    }
}

template <class T>
T ArrayList<T>::get(int index){
    if(index < this->used){//in range
        return this->array[index];
    } else{
        return *(new T);
    }
}

template <class T>
void ArrayList<T>::add(T toAdd){    
    if(this->used + 1 >= this->capacity){
        this->resize();
    }
    this->array[this->used] = toAdd;
    this->used++;
}

template <class T>
bool ArrayList<T>::add(int index,T toAdd){
    if(index >= 0){
        if(index >= this->capacity + this->CAPACITY_INCREMENT){
            this->resize(index+1);
        } else if(this->used + 1 >= this->capacity){
            this->resize();
        }

        for(int i = this->used; i > index; i--){
            this->array[i] = this->array[i-1];
        }
        
        this->array[index] = toAdd;

        this->used++;
        return true;
    } else{
        return false;
    }
}

template <class T>
bool ArrayList<T>::set(int index,T toSet){
    if(index >= 0){
        if(index >= this->capacity + this->CAPACITY_INCREMENT){
            this->resize(index+1);
        } else if(this->used + 1 >= this->capacity){
            this->resize();
        }
        
        this->array[index] = toSet;
        
        return true;
    } else{
        return false;
    }
}

template <class T>
T ArrayList<T>::remove(int index){
    if(index < this->used && index >= 0){
        T removed;
        removed = this->array[index];
        for(int element = index; element < this->used - 1; element++){
            this->array[element] = this->array[element+1];
        }
        this->used--;
        return removed;
    } else{
        return *(new T);
    }
}

template <class T>
ArrayList<T> ArrayList<T>::removeRange(int start,int end){
    if(start < end && end < this->used && start >= 0){
        ArrayList removed;
        T empty;
        for(int element = start; element <= end; element++){
            removed.add(this->array[element]);
            if((element + (end - start + 1)) < this->used){
                //can move one back
                this->array[element] = this->array[element + (end - start + 1)];
            } else{
                this->array[element] = empty;
            }
            this->used--;
        }
        return removed;
    } else{
        return new T[0];
    }
}

template <class T>
bool ArrayList<T>::removeOne(T toRemove){
    bool foundAndRemoved = false;
    for(int element = 0; element < this->used && !foundAndRemoved; element++){
        if(this->array[element] == toRemove){
            for(int moveBack = element; moveBack < this->used - 1; moveBack++){
                this->array[moveBack] = this->array[moveBack+1];
            }
            this->used--;
            foundAndRemoved = true;
        }
    }
    return foundAndRemoved;
}

template <class T>
bool ArrayList<T>::removeAllOf(T toRemove){
    bool foundAndRemoved = false;
    for(int element = 0; element < this->used; element++){
        if(this->array[element] == toRemove){
            for(int moveBack = element; moveBack < this->used - 1; moveBack++){
                this->array[moveBack] = this->array[moveBack+1];
            }
            this->used--;
            foundAndRemoved = true;
        }
    }
    return foundAndRemoved;
}

template <class T>
bool ArrayList<T>::replaceOne(T toReplace,T replacement){
    bool replaced = false;
    for(int element = 0; element < this->used && !replaced; element++){
        if(this->array[element] == toReplace){
            this->array[element] = replacement;
            replaced = true;
        }
    }
    return replaced;
}

template <class T>
bool ArrayList<T>::replaceAllOf(T toReplace,T replacement){
    bool replaced = false;
    for(int element = 0; element < this->used; element++){
        if(this->array[element] == toReplace){
            this->array[element] = replacement;
            replaced = true;
        }
    }
    return replaced;
}

template <class T>
ArrayList<T> ArrayList<T>::getSubArrayList(int start,int end){
    ArrayList<T> result;
    for(int element = start; element <= end; element++){
        result.add(this->array[element]);
    }
    
    return result;
}

template <class T>
void ArrayList<T>::clear(){
    delete [] this->array;
    this->used = 0;
    this->capacity = CAPACITY_INITIAL;
    this->array = new T[this->capacity];
}

template <class T>
int ArrayList<T>::size(){
    return this->used;
}

template <class T>
void ArrayList<T>::addCapacity(unsigned int toAdd){
    this->resize(this->capacity + toAdd);
}

template <class T>
int ArrayList<T>::indexOf(T toFind){
    for(int element = 0; element < this->used; element++){
        if(this->array[element] == toFind){
            return element;
        }
    }
    return -1;
}

template <class T>
void ArrayList<T>::trim(int newSize){
    if(newSize >= 0 ){
        if(newSize >= this->used){//all the current elements fit
            this->resize(newSize);
        } else{//will delete some elements
            //the resize(int) function copies up to used, but used
            //will be greater than this->used. Thus this compensates by
            //using the new shorter capacity instead. 
            this->capacity = newSize;
            T* temp = new T[this->capacity];
            for(int element = 0; element < this->capacity; element++){
                temp[element] = this->array[element];
            }

            delete [] this->array;
            this->array = new T[this->capacity];

            for(int element = 0; element < this->capacity; element++){
                this->array[element] = temp[element];
            }

            delete [] temp;
        }
    }
}


#endif /* ARRAYLIST_H */
