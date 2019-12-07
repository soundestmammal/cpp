#include <iostream>
#include <string>
#include "mapWrapper.h"

farmingdale::status farmingdale::mapWrapper::insert(std::string keyToBeInserted, int valueToBeInserted) {
    
    // The map accepts std::pair as a parameter in insert
    std::pair <std::string, int> insertMe(keyToBeInserted, valueToBeInserted);

    // std::map.insert(std::pair)
    /* RETURNS a std::pair --- {a,b}
        (a) An iterator to the (key of the inserted element OR key of the element that prevented insertion)
        (b) bool value that is true if insertion was a success, and false if it was unable to insert.
    */
    const auto [itToKey, succeeded] = myAwesomeMap.insert(insertMe);
    if(succeeded){
        return SUCCESS;
    }
    return FAILURE;
}

farmingdale::status farmingdale::mapWrapper::remove(std::string eraseMe) {
    // I need an iterator to the element that I would like to delete
    std::map<std::string, int>::iterator it;

    it = myAwesomeMap.find(eraseMe);

    // I now have an iterator to the element I want to delete

    // I need to check if it is an iterator to the element OR if it is pointing to the end of the map
    if(it != myAwesomeMap.end()) {
        // It found eraseme
        myAwesomeMap.erase(it);
        return SUCCESS;
    }

    return FAILURE;
}

farmingdale::status farmingdale::mapWrapper::query(std::string findMe, int&value) {
    // Make iterator of proper type
    std::map<std::string, int>::iterator it;
    // Try and find the element
    it = myAwesomeMap.find(findMe);
    // If not found, will return it to end of map
    if(it != myAwesomeMap.end()) {
        // It found the element
        value = it->second;
        return SUCCESS;
    }
    value = -1;
    return FAILURE;
}