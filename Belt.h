#pragma once

/**
 * @file Belt.h
 * @brief Contains the declaration of the Belt class.
 */

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

/**
 * @brief Represents a belt item.
 * 
 * This class inherits from the Equipment class and provides functionality specific to belts.
 */

class Belt : public Equipment{
	
	public:
		
		
		 /**
     * @brief Default constructor for the Belt class.
     * 
     * Constructs a Belt object with a random enchantment.
     */
     
		Belt();
		
		
		/**
     * @brief Sets a random enchantment for the belt.
     * 
     * This function randomly selects an enchantment from the list of available enchantments
     * and sets it for the belt.
     */
		
		void getRandomEnchantment();
	
	private:
	
		static string listOfEnchantments[2]; /**< An array containing the list of enchantments available for belts. */
		
};
