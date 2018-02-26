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
    /**
     * The initial capacity of the ArrayList.
     */
    constexpr static int CAPACITY_INITIAL = 3;
    
    /**
     * The increment to use for each increment of the ArrayList.
     */
    constexpr static int CAPACITY_INCREMENT = 3;
    
    /**
     * The number of spots used in the ArrayList. 
     */
    int used;
    
    /**
     * The capacity that the array holds. 
     */
    int capacity;
    
    /**
     * The manual array that is being managed. 
     */
    T* array;
    
    /**
     * Resize the array in order to add more or to have capacity. 
     */
    void resize();
    
    /**
     * Resize the array with a size specification. 
     * 
     * @param newSize the size specification. 
     * @return a boolean value concerning if the resize worked. 
     */
    bool resize(int newSize);
public:
    /**
     * The default constructor for the ArrayList to build the array. 
     */
    ArrayList();
    
    /**
     * The destructor for the ArrayList to take down the array. 
     */
    ~ArrayList();
    
    /**
     * The copy constructor to manage the copying of an ArrayList. 
     * 
     * @param that the ArrayList instance by reference and constant to
     *      be copied. 
     */
    ArrayList(const ArrayList& that);
    
    /**
     * The operator overload used to override the = operator in order to 
     *      set the data of that to this. 
     * 
     * @param that the instance to set the data of for this instance
     * @return this class by reference for chaining and other purposes
     */
    ArrayList<T>& operator=(const ArrayList& that);
    
    /**
     * The operator overload in order to access a part of the ArrayList by
     *      using the [] operator. 
     * 
     * @param index the index to find
     * @return the object of type T that is found at the spot index 
     */
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
    
    /**
     * This function removes the object of type T at the spot index. 
     * 
     * @param index the index to remove the object from
     * @return a copy of the object that was removed 
     */
    T remove(int index);
    
    /**
     * This function removes a range of objects of type T from the array 
     *      inclusively. 
     * 
     * @param start the start point to remove from 
     * @param end the end point to remove from, inclusively
     * @return an ArrayList object of the objects that were removed from this
     *      instance of ArrayList of type T
     */
    ArrayList<T> removeRange(int start,int end);
    
    /**
     * This function removes one copy of the T toRemove.
     * 
     * @param toRemove the instance of T to remove 
     * @return if the remove was followed through and removed an object 
     */
    bool removeOne(T toRemove);
    
    /**
     * This function removes all copies found of the T toRemove.
     * 
     * @param toRemove the T to remove all copies of
     * @return if a copy of toRemove was removed 
     */
    bool removeAllOf(T toRemove);
    
    /**
     * This funciton replaces only one of the toReplace T objects with the
     *      replacement T object. 
     * 
     * @param toReplace the T object to replace 
     * @param replacement the T object to replace toReplace with
     * @return if a copy of toReplace was replaced 
     */
    bool replaceOne(T toReplace,T replacement);
    
    /**
     * This function replaces all of the copies of toReplace with replacement.
     * 
     * @param toReplace the copy of T to replace whenever found 
     * @param replacement the replacement to replace toReplace with
     * @return a boolean value concerning if a copy of toReplace was found
     *      and then replaced, at least one will turn it to true 
     */
    bool replaceAllOf(T toReplace,T replacement);
    
    /**
     * This function returns a sub-ArrayList that contains all of the T
     *      objects from start to end, inclusively. 
     * 
     * @param start the start of the index of the new sub-ArrayList 
     * @param end the end of the index of the new sub-ArrayList 
     * @return the sub-ArrayList from start to end, inclusively 
     */
    ArrayList<T> getSubArrayList(int start,int end);
    
    /**
     * This function removes all objects from the ArrayList. 
     */
    void clear();
    
    /**
     * This function returns the size of the ArrayList, in how many objects
     *      are held in this ArrayList. 
     * @return the number of objects that are held in this ArrayList
     */
    int size();
    
    /**
     * This function adds to the capacity of the ArrayList. 
     * 
     * PRECONDITION:: toAdd does not put the size of the ArrayList out of 
     *      bounds of the integer bounds.
     * @param toAdd the number of spots to add 
     */
    void addCapacity(unsigned int toAdd);
    
    /**
     * This function finds the index of the T object toFind and returns
     *      the index. 
     * @param toFind the object instance of T to find 
     * @return the index of the object instance of T that was found 
     */
    int indexOf(T toFind);
    
    /**
     * This function trims the size of the array, whether there are objects
     *      in the way or not, to the new size of newSize. 
     * 
     * @param newSize the new size to trim to 
     */
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
