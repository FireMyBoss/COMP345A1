/**
 * @brief A class representing a backpack that can contain items.
 * 
 * This class inherits from the Item class.
 */

#ifndef Backback_h
#define Backback_h

#include <string>
#include <vector>
#include <stdio.h>
#include "Item.h"

using namespace std;

class Backpack : public Item{

	public:
		
		
		/**
     * @brief Constructs a Backpack object with the given equipped value and space.
     * 
     * @param equippedValue Whether the backpack is equipped or not.
     * @param spc The space of the backpack.
     */
		Backpack(bool equippedValue, int spc) : Item(equippedValue), space(spc){};
		
		
		 /**
     * @brief Explicit constructor for constructing a Backpack object with the given space.
     * 
     * @param spc The space of the backpack.
     */
		explicit Backpack(int spc) : space(spc){};
		
		
		 /**
     * @brief Gets the space of the backpack.
     * 
     * @return The space of the backpack.
     */
		
		int getSpace(){
		
			return space;
			
		}
		
		
		/**
     * @brief Sets the space of the backpack.
     * 
     * @param value The value to set as the space of the backpack.
     */
		
		void setSpace(int value){
		
			space = value;
			
		}
		
		
		/**
     * @brief Gets the contents of the backpack.
     * 
     * @return A vector containing pointers to the items in the backpack.
     */

		vector<Item*> getContents(){
		
			return contents;
			
		}
		
		
		/**
     * @brief Adds an item to the contents of the backpack.
     * 
     * @param itm A pointer to the item to be added to the backpack.
     */
		
		void addContent(Item * itm){
		
			contents.push_back(itm);
			
		}
		
		
		/**
     * @brief Prints information about the backpack.
     * 
     * This function prints information about the backpack to the screen.
     */
		
		void printItem();// creates items in backpack the item to the screen
		
		 /**
     * @brief Prints information about the contents of the backpack.
     * 
     * @param itms A vector containing pointers to the items in the backpack.
     */
		
		void printContents(vector<Item*> itms);

	private:
		
		int space; /**< The space of the backpack. */
		vector<Item*> contents; /**< A vector containing pointers to the items in the backpack. */

};


#endif
