#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <termios.h>
#include <cstring>
#include <cmath>



#include "misc.h"
#include "userInput.h"
#include "EmojiMap.h"

using namespace std;


		
		EmojiMap::EmojiMap() {
		
			mapInfo = nullptr;
			this -> length = 0;
			this -> width = 0;
			this -> xInd = 0;
			this -> yInd = 0;
		
		}
		
		EmojiMap::EmojiMap(int length, int width) {
			
			this -> mapInfo = (int**) (malloc(sizeof(int**)*width));
			
			for(int i = 0; i < width; i++) {
				
				this -> mapInfo[i] = (int*) (malloc(sizeof(int*)*length));
				
				for(int j = 0; j < length; j++) {
				
					this -> mapInfo[i][j] = 2;
				
				}
				
			}
			
			this -> length = length;
			this -> width = width;
			this -> isPaused = 0;
			
			this -> xInd = 0;
			this -> yInd = 0;
			
			this -> input = nullptr;
			
			this -> prevInput = nullptr;
			
			this -> mapString = nullptr;
		
		}
		
		EmojiMap::~EmojiMap() {
		
			if (this -> mapInfo != nullptr) {
			 
				for (int i = 0; i < width; i++) {
                
					free(mapInfo[i]);
					  
				}
            
				free(mapInfo);
        
			}
      
			delete[] input;
			delete[] prevInput;
			delete[] mapString;
		
		}
		
		
		int** EmojiMap::getMap() {
		
			return this -> mapInfo;
		
		}
		
		
		void EmojiMap::setMap(int** mapInfo) {
		
			this -> mapInfo = mapInfo;
		
		}
			 
		
		int EmojiMap::getLength() {
		
			return this -> length;
		
		}
		
		void EmojiMap::setLength(int length) {
		
			this -> length = length;
		
		}
		
		
		int EmojiMap::getWidth() {
		
			return this -> width;
		
		}
		
		void EmojiMap::setWidth(int width) {
		
			this -> width = width;
		
		}
		
		
		int EmojiMap::getXInd() {
		
			return this -> xInd;
		
		}
		
		void EmojiMap::setXInd(int xInd) {
		
			this -> xInd = xInd;
		
		}
		
		
		int EmojiMap::getYInd() {
		
			return this -> yInd;
		
		}
		
		void EmojiMap::setYInd(int yInd) {
		
			this -> yInd = yInd;
		
		}
		
		
		int EmojiMap::getIsPaused() {
		
			return this -> isPaused;
		
		}
		
		void EmojiMap::setIsPaused(int isPaused) {
		
			this -> isPaused = isPaused;
		
		}
		
		
		char* EmojiMap::getInput() {
		
			return this -> input;
		
		}
		
		void EmojiMap::setInput(const char* input) {
    	  
		  this->input = new char[strlen(input) + 1]; // +1 for null terminator
		  strcpy(this->input, input);
		
		}
		
		
		char* EmojiMap::getPrevInput() {
		
			return this -> prevInput;
		
		}
		
		void EmojiMap::setPrevInput(const char* prevInput) {
		  
		  this->prevInput = new char[strlen(prevInput) + 1]; // +1 for null terminator
		  strcpy(this->prevInput, prevInput);
		
		}
		
		
		char* EmojiMap::getMapString() {
		
			return this -> mapString;
		
		}
		
		void EmojiMap::setMapString(const char* mapString) {
		  
		  this->mapString = new char[strlen(mapString) + 1]; // +1 for null terminator
		  strcpy(this->mapString, mapString);
		
		}
		
		
		int EmojiMap::getNumberAtCell(int yInd, int xInd) {
		
    	if((yInd < 0 || xInd < 0) || (yInd >= width || xInd >= length)) { //Check boundary Conditions
			
				return -1;
			
			} else { //Return number at cell
			
				return mapInfo[yInd][xInd];
			
			}
		
		}
		
		void EmojiMap::setNumberAtCell(int newNumber, int yInd, int xInd) {
		
    	if((yInd < 0 || xInd < 0) || (yInd >= width || xInd >= length)) { //Check boundary conditions
			
				return;
			
			} else { //Set number at cell
			
				mapInfo[yInd][xInd] = newNumber;
			
			}
		
		}
		
		int EmojiMap::isCellSpecificValue(int value,int yInd, int xInd) {
			
			return getNumberAtCell(yInd, xInd) == value;
		
		}
		
		
		int** EmojiMap::getCellsAroundCell(int desiredCellValue, int yInd, int xInd) { //-1 flag for desiredCellValue indicates that the cell info doesn't matter 
			
			/**
			* Assign the cells in this order: NW, N, NE, E, SE, S, SW, W
			* Stores coordinates of the 8 cells surroundyng the player, in this format: [yInd, xInd, cellNumber]
			*/
			int** retArr = new int*[8];  
			
			int offsets[8][2] = { // Define the change in x and y indexes required to travel in each direction: [yOffset, xOffset]
				
		    {-1, -1},   // NorthWest (0)
		    {-1, 0},    // North (1)
		    {-1, 1},    // NorthEast (2)
		    {0, 1},     // East (3)
		    {1, 1},     // SouthEast (4)
		    {1, 0},     // South (5)
		    {1, -1},    // SouthWest (6)
		    {0, -1}     // West (7)
				    
			};


			for (int i = 0; i < 8; i++) {
				
			  int newY = yInd + offsets[i][0]; //Set the y index being checked up or down, according to the direction
			  int newX = xInd + offsets[i][1]; //Set the x index being checked left or right, according to the direction
				  
			  int* cellData = new int[3];
				
				retArr[i] = cellData;
			  retArr[i][0] = newY; //Y index
				retArr[i][1] = newX; //X index
				retArr[i][2] = 0;

			  if (newY >= 0 && newY < width && newX >= 0 && newX < length) { // Check boundary conditions

					int numberAtCellBeingChecked = getNumberAtCell(newY, newX);	//Gets the cell info at the relevant direction	
			
					if(desiredCellValue != -1) { //Checks if a specific value at a cell is being checked
						
						if(numberAtCellBeingChecked == desiredCellValue) { //Checks if the cell info obtained matches what number is being searched
								
							retArr[i][2] = numberAtCellBeingChecked;
								
						} else {
							
							retArr[i][2] = -1; //Indicates the desired number was not found
							
						}
						
					} else {
						
						retArr[i][2] = numberAtCellBeingChecked;
						
					}
						      
				} else {
				  
					retArr[i][2] = -2; //Indicates that the desired index is out of bounds
				  
			  }
			  
			}
			
			return retArr;
		
		}
		
		
		int EmojiMap::checkCellsAroundCellSpecificValue(int desiredValue, int yInd, int xInd) {
		
			int offsets[8][2] = {//Define the relative coordinates for each cell: [yOffset, xOffset]
				
		    {-1, -1},   // NorthWest
		    {-1, 0},    // North
		    {-1, 1},    // NorthEast
		    {0, 1},     // East
		    {1, 1},     // SouthEast
		    {1, 0},     // South
		    {1, -1},    // SouthWest
		    {0, -1}     // West
				    
			};

			for (int i = 0; i < 8; i++) {
				
		    int newY = yInd + offsets[i][0];
		    int newX = xInd + offsets[i][1];

		    if (newY >= 0 && newY < width && newX >= 0 && newX < length) { // Check boundary conditions
				    
					if(isCellSpecificValue(desiredValue, newY, newX)) {
					
						return 1;
					
					}

		    }
				    
			}
			
			return 0;
		
		}
		
		int EmojiMap::pauseMenu() {

			int menuSelector = 0;
			int retVal = 0;
			int runLoop = 1;
			  	
			const char* menuOptions[4] = {
        "Paused.\n\n>> Continue?\nQuit?\nDisplay Character Information?\nDisplay Equipment Information\n\nPress W to navigate up, S to navigate down, C to select option\n\n",
        "Paused.\n\nContinue?\n>> Quit?\nDisplay Character Information?\nDisplay Equipment Information\n\nPress W to navigate up, S to navigate down, C to select option\n\n",
        "Paused.\n\nContinue?\nQuit?\n>> Display Character Information?\nDisplay Equipment Information\n\nPress W to navigate up, S to navigate down, C to select option\n\n",
        "Paused.\n\nContinue?\nQuit?\nDisplay Character Information?\n>> Display Equipment Information\n\nPress W to navigate up, S to navigate down, C to select option\n\n"
    };
    
    	do {
    	
				cout << menuOptions[menuSelector];			
				input = userInput(10);
							
				switch(userInputCase(input)) {
							
					case 0: //W key (Up)
								
						menuSelector--;
						menuSelector = menuSelector - 4*floor(menuSelector/4.0);
									
					break;
					case 2: //S key (Down)
								
						menuSelector++;
						menuSelector = menuSelector - 4*floor(menuSelector/4.0);
							
					break;
					case 10: //C key (Select)
								
						switch(menuSelector) {
									
							case 0: //Unpause

								isPaused = 0;
								retVal = 1;
								runLoop = 0;

											
							break;
							case 1: //Quit Game
								
								retVal = 0;
								runLoop = 0;
											
							break;
									
						}
							
				}
				
				if(runLoop != 0) {
					
					delete[] input;
				
				}
				
				clearConsole();	
    	
    	} while(runLoop);
				
			delete[] input;
			input = nullptr;
			
			return retVal;
		
		}
		
		int EmojiMap::runGameTick(int& diagonalLeft, int& diagonalRight, int& diagonalUp, int& diagonalDown, int** NPCInfo, int numNPCs) {
			
			if(prevInput == nullptr) {
			
				prevInput = new char[1];
				prevInput[0] = '\0';
			
			}
			
				toString(0, 1);
					
				clearConsole();
			
				pause(30);
				
				cout << "Previous Input: " << prevInput << "\n";
				cout << getMapString();
				
			
			
			if(isPaused) {
				
				int retVal = pauseMenu();
				
				if(retVal == 1) {
				
					toString(0, 1);
					clearConsole();
					cout << "Previous Input: " << prevInput << "\n";
					cout << getMapString();
				
				}
				
				delete[] prevInput;
    		prevInput = nullptr;
    		prevInput = input;
				
				return retVal;
			
			}
			
			if(checkCellsAroundCellSpecificValue(7, yInd, xInd)) {
			
				cout << "OUCH! I've been hit! \n\n";
				pause(50);
			
			}
		
			input = userInput(40);
			
			setNumberAtCell(2, yInd, xInd);
			
			int** isNPCPresent;
			
		  switch(userInputCase(input)) {

				case 0: // North (W)

					if(isNorthWest(prevInput)) {
						
						diagonalLeft = diagonalTest(0, 50/3); //Testing to see whether to go NorthWest
						
					} else if(isNorthEast(prevInput)) {
					
						diagonalRight = diagonalTest(0, 50/3); //Testing to see whether to go NorthEast
					
					}

					
					if(yInd > 0 && isCellSpecificValue(2, yInd - 1, xInd)) { //Checking to see if the relevant cell is in the bounds of the map, and is a valid space
				            
						yInd--;
				            
					}
					
					if(diagonalLeft && xInd > 0 && isCellSpecificValue(2, yInd, xInd - 1)) {
		                  
				   diagonalLeft = 1;
				   xInd--;
		                  
					} else if(diagonalRight && xInd < (length - 1) && isCellSpecificValue(2, yInd, xInd + 1)) {
		                  
						diagonalRight = 1;
				    xInd++;
		                  
					}
            
				break;
        case 1: // East (D)
        
        	if(isNorthEast(prevInput)) {
						
						diagonalUp = diagonalTest(1, 50/3); //Testing to see whether to go NorthEast
					
					} else if(isSouthEast(prevInput)) {
					
						diagonalDown = diagonalTest(1, 50/3); //Testing to see whether to go SouthEast
					
					}
					
					
					if(xInd < (length - 1) && isCellSpecificValue(2, yInd, xInd + 1)) { //Checking to see if the relevant cell is in the bounds of the map, and is a valid space
                
						xInd++;
                
				  }
				  
						
					if(diagonalUp && yInd > 0 && isCellSpecificValue(2, yInd - 1, xInd)) {
                    
						diagonalUp = 1;
				   	yInd--;
                    
					} else if(diagonalDown && yInd < (width - 1) && isCellSpecificValue(2, yInd + 1, xInd)) {
                    
						diagonalDown = 1; 
			      yInd++;
                   
				  }   
            
				break;
        case 2: // South (S)
					
					if(isSouthWest(prevInput)) {
						
						diagonalLeft = diagonalTest(2, 50/3); //Testing to see whether to go SouthWest
					
					} else if(isSouthEast(prevInput)) {
					
						diagonalRight = diagonalTest(1, 50/3); //Testing to see whether to go SouthEast
					
					}
					
					
					if(yInd < (width - 1) && isCellSpecificValue(2, yInd + 1, xInd)) {
                
						yInd++;
                          
					}
					
					
					if(diagonalLeft && xInd > 0 && isCellSpecificValue(2, yInd, xInd - 1)) {
                    
				    diagonalLeft = 1;
				    xInd--;
                    
			   	} else if(diagonalRight && xInd < (length - 1) && isCellSpecificValue(2, yInd, xInd + 1)) {
                    
			    	diagonalRight = 1;
			    	xInd++;
                    
					}
            
			  break;
        case 3: // West (A)
				
					if(isNorthWest(prevInput)) {
						
						diagonalUp = diagonalTest(3, 50/3); //Testing to see whether to go NorthWest
					
					} else if(isSouthWest(prevInput)) {
					
						diagonalDown = diagonalTest(3, 50/3); //Testing to see whether to go SouthWest
					
					}
					
					if(xInd > 0 && isCellSpecificValue(2, yInd, xInd - 1)) {
                
		        xInd--;      
                        
					}
				
					if((diagonalUp) && yInd > 0 && isCellSpecificValue(2, yInd - 1, xInd)) {
                    
		        diagonalUp = 1;
						yInd--;
                    
			    } else if(diagonalDown && yInd < (width - 1) && isCellSpecificValue(2, yInd + 1, xInd)) {
                    
						diagonalDown = 1;
		        yInd++;
                    
			    }
            
				break;
        case 4: // NorthWest

					if(xInd > 0 && yInd > 0 && isCellSpecificValue(2, yInd - 1, xInd - 1)) {
                
			      xInd--;
			      yInd--;
			      diagonalLeft = 1;
			      diagonalUp = 1;      
                
					}
            
				break;
        case 5: // NorthEast
					
					if(xInd < (length - 1) && yInd > 0 && isCellSpecificValue(2, yInd - 1, xInd + 1)) {
                
			      xInd++;
			      yInd--;
			      diagonalRight = 1;
			      diagonalUp = 1;
                
					}
            
				break;
        case 6: // SouthEast

					if(xInd < (length - 1) && yInd < (width - 1) && isCellSpecificValue(2, yInd + 1, xInd + 1)) {
                
			      xInd++;
			      yInd++;
			      diagonalRight = 1;
			      diagonalDown = 1;
                
				  }
            
				break;
        case 7: // SouthWest

					if(xInd > 0 && yInd < (width - 1) && isCellSpecificValue(2, yInd + 1, xInd - 1)) {
                
						xInd--;
						yInd++;
				    diagonalLeft = 1;
				    diagonalDown = 1;
                
					}
	
			  break;
			  case 8: // If user opens chest
			  
					//Add logic
			  
			  break;
			  case 9: // If user pauses
			  	
			  	isPaused = 1;
				
				break;
				case 11:
				
					cout << "My sword has been swung!\n\n";
					
					isNPCPresent = getCellsAroundCell(6, yInd, xInd);
					
					for(int i = 0; i < 8; i++) {
					
						if(isNPCPresent[i][2] == 6) {
						
							setNumberAtCell(7,isNPCPresent[i][0], isNPCPresent[i][1]);
							
							for(int j = 0; j < numNPCs; j++) {
							
								if(isNPCPresent[i][0] == NPCInfo[j][0] && isNPCPresent[i][1] == NPCInfo[j][1]) {
									
									NPCInfo[j][2] = 7;
									break;
									
								}
							
							}
						
						}
						
						delete[] isNPCPresent[i];
					
					}
					
					delete[] isNPCPresent;
					isNPCPresent = nullptr;
					
					pause(500);
				
				break;
			  default:
			  
			  	diagonalLeft = 0;
					diagonalRight = 0;
					diagonalUp = 0;
					diagonalDown = 0;
					
    	}
    
    	if(strcmp(input, "  ") != 0) {
    		
    		delete[] prevInput;
    		prevInput = nullptr;
    		prevInput = input;
    		
    	} else {
    		
    		delete[] input;
    		input = nullptr;
    		
    	}
    
    	setNumberAtCell(4, yInd, xInd);
			
			return 1;

		}
		
		int** EmojiMap::runNPCAI(int** NPCInfo, int numNPCs) {
			
			int** cellsAroundNPC;
			
			int NPCCurYCoord = 0;
			int NPCCurXCoord = 0;
			
			int NPCState = 0;
			
			int potentialYCoord = 0;
			int potentialXCoord = 0;
			
			int NPCFutureYCoord = 0;
			int NPCFutureXCoord = 0;
			
			int minDistanceSquaredNPCPlayer = 0;
			
			for(int i = 0; i < numNPCs; i++) { //Run this for all NPCS on the map
				
				NPCCurYCoord = NPCInfo[i][0];
				NPCCurXCoord = NPCInfo[i][1];
				NPCState = NPCInfo[i][2];
				
				if(checkCellsAroundCellSpecificValue(4, NPCCurYCoord, NPCCurXCoord)){ //Avoid colliding with the player
				
					continue;
				
				}
				
				setNumberAtCell(2, NPCCurYCoord, NPCCurXCoord);
				
				cellsAroundNPC = getCellsAroundCell(-1,NPCCurYCoord, NPCCurXCoord); //Get cell info around NPC
				
				minDistanceSquaredNPCPlayer = pow((NPCCurYCoord - yInd), 2) + pow((NPCCurXCoord - xInd), 2);
				
				for(int i = 0; i < 8; i++) {
					
					if(cellsAroundNPC[i][2] == 2) { //Ensures that the npc can move to the cell in question
						
						potentialYCoord = cellsAroundNPC[i][0];
						potentialXCoord = cellsAroundNPC[i][1];
						
						int potentialDistanceSquaredNPCPlayer = pow((potentialYCoord - yInd), 2) + pow((potentialXCoord - xInd), 2);
						
						if(potentialDistanceSquaredNPCPlayer < minDistanceSquaredNPCPlayer) {
						
							NPCFutureYCoord = potentialYCoord;
							NPCFutureXCoord = potentialXCoord;
							minDistanceSquaredNPCPlayer = potentialDistanceSquaredNPCPlayer;
						
						}
					
					} 
					
					delete[] cellsAroundNPC[i];
				
				}
				
				setNumberAtCell(NPCState, NPCFutureYCoord, NPCFutureXCoord);
				
				NPCInfo[i][0] = NPCFutureYCoord;
				NPCInfo[i][1] = NPCFutureXCoord;
				NPCInfo[i][2] = NPCState;
				
				delete[] cellsAroundNPC;
				
			}

			
			cellsAroundNPC = nullptr;
			return NPCInfo;
		
		}
		
		void EmojiMap::runGame(int** NPCInfo, int numNPCs, int numTicks) {
		
			int diagonalLeft = 0;
			int diagonalRight = 0;
			int diagonalUp = 0;
			int diagonalDown = 0;
			
			int runLoop = 1;
			
			while(runLoop) {
				
				runLoop = runGameTick(diagonalLeft, diagonalRight, diagonalUp, diagonalDown, NPCInfo, numNPCs);
				
				if(numTicks % 3 == 0) {
				
					NPCInfo = runNPCAI(NPCInfo, numNPCs);
				
				}
				
				numTicks++;
				clearConsole();

			
			}
		
		}
		
		
		void EmojiMap::toString(int csvMode, int gameVideoMode) {
		
			int retStrLen = 1; //Intialize size of return string. Set to one to account for Null Terminator
			
			//TODO: Explain what the gameVideoMode does
			
			int startingRow = 0;
			int startingColumn = 0;
			
			int endingRow = 0;
			int endingColumn = 0;
			
			if(gameVideoMode) {
				
				if(width < 30 || length < 30) {
				
					endingRow = width;
					endingColumn = length;
				
				} else {
				
					int yChunk = (int) floor(getYInd()/29);
					int xChunk = (int) floor(getXInd()/29);

					endingRow = min((yChunk + 1) * 30, getWidth()); 
					endingColumn = min((xChunk + 1) * 30, getLength());
					
					if((yChunk + 1)*29 >= getWidth()) {
					
						startingRow = getWidth() - 30;
					
					} else if(yChunk != 0) {
					
						startingRow = yChunk * 29;
						endingRow -= 1;
					
					}
					
					
					if((xChunk + 1)*29 >= getLength()) {
					
						startingColumn = getLength() - 30;
					
					} else if(xChunk != 0) {
					
						startingColumn = xChunk * 29;
						endingColumn -= 1;
					
					}
					
				}
				
			} else {
			
				endingRow = width;
				endingColumn = length;
			
			}
			
			//For every value in the map, increment retStrLen by the amount of characters needed to store the corresponding emoji/character
			for (int i = startingRow; i < endingRow; i++) {
		  
				for (int j = startingColumn; j < endingColumn; j++) {
		      		
					switch (getNumberAtCell(i, j)) {
		      			
						case 1: //⬛ (Wall)
						case 2: //⬜ (Valid Space)
		      			
							retStrLen += 3; //UTF-8 Needs 3 Characters
							
							if(csvMode) {
							
								retStrLen += 1; //1 for comma
							
							}
		      			
						break;
						case 3: //🎁 (Chest)
			 			case 4: //😃 (Player)
			 			case 5: //🟩 (Valid path to exit)
			 			case 6: //😇 (Good NPC)
			 			case 7: //😈 (Evil NPC)
		      			
							retStrLen += 4; //UTF-8 Needs 4 Characters
		      			
							if(csvMode) {
							
								retStrLen += 1; //1 for comma
							
							}
		      			
			 			break;
			 			case 0:	//Blank Space
			 			default: //Something Went Wrong
		      			
							retStrLen += 2; //Standard ASCII needs one character
							
							if(csvMode) {
							
								retStrLen += 1; //1 for comma
							
							}
									
						}
		      			
					}
		    	
		    retStrLen += 1; //Account for the new line character (new row)
		          
			}  

		  char* retStr = new char[retStrLen]; //Intialize a string with just enough space to store the map data as characters/emojis
		  
		  int k = 0; //Intialize a counter to keep of track of which character is being assigned in the return string
		  
		  //For every value in the map, assign the corresponding emoji/character in the return string
		  for (int i = startingRow; i < endingRow; i++) {
		  
				for (int j = startingColumn; j < endingColumn; j++) {
					
					switch (getNumberAtCell(i, j)) {
            case 0: //Blank Space
            
							retStr[k++] = ' ';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
							   	
						break;
						case 1: //⬛ (Wall)
                
							retStr[k++] = '\xE2';
							retStr[k++] = '\xAC';
							retStr[k++] = '\x9B';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							} 	
							
            break;
           	case 2: //⬜ (Valid Space)
                
							retStr[k++] = '\xE2';
							retStr[k++] = '\xAC';
							retStr[k++] = '\x9C';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
							  
						break;
						case 3: //🎁 (Chest)

							retStr[k++] = '\xF0';
							retStr[k++] = '\x9F';
							retStr[k++] = '\x8E';
							retStr[k++] = '\x81';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
							
						break;
						case 4: //😃 (Player)

							retStr[k++] = '\xF0';
							retStr[k++] = '\x9F';
							retStr[k++] = '\x98';
							retStr[k++] = '\x83';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
							
						break;
						case 5: //🟩 (Valid path to exit)

							retStr[k++] = '\xF0';
							retStr[k++] = '\x9F';
							retStr[k++] = '\x9F';
							retStr[k++] = '\xA9';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
							
						break;
						case 6: //😇 (Good NPC)
						
							retStr[k++] = '\xF0';
							retStr[k++] = '\x9F';
							retStr[k++] = '\x98';
							retStr[k++] = '\x87';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
							
						break;
						case 7: //😈 (Evil NPC)
						
							retStr[k++] = '\xF0';
							retStr[k++] = '\x9F';
							retStr[k++] = '\x98';
							retStr[k++] = '\x88';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
						
						break;
						default: //Something Went Wrong
							
							retStr[k++] = '?';
							
							if(csvMode) {
						
								retStr[k++] = ',';
							
							}
							
					}
            
        }
        
        retStr[k++] = '\n'; // Append newline at the end of each row
        
    	}

    	retStr[k] = '\0'; // Add null terminator to the end of the string
		  
		  delete[] mapString;
		  
		  mapString = retStr;   
		  
		}
		


	

