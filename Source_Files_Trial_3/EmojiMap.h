#pragma once

class EmojiMap {

	public:
		
		EmojiMap();
		EmojiMap(int length, int width);
		~EmojiMap();
		
		int** getMap();
		void setMap(int** mapInfo);
		
		int getLength();
		void setLength(int length);
		
		int getWidth();
		void setWidth(int width);
		
		int getXInd();
		void setXInd(int xInd);
		
		int getYInd();
		void setYInd(int yInd);
		
		int getIsPaused();
		void setIsPaused(int isPaused);
		
		char* getInput();
		void setInput(const char* input);
		
		char* getPrevInput();
		void setPrevInput(const char* prevInput);
		
		char* getMapString();
		void setMapString(const char* mapString);
		
		int getNumberAtCell(int yInd, int xInd);
		void setNumberAtCell(int newNumber, int yInd, int xInd);
		
		int isCellSpecificValue(int value,int yInd, int xInd);
		
		int** getCellsAroundCell(int desiredCellValue, int yInd, int xInd);
		
		int checkCellsAroundCellSpecificValue(int desiredValue, int yInd, int xInd);
		
		int pauseMenu();
		
		int runGameTick(int& diagonalLeft, int& diagonalRight, int& diagonalUp, int& diagonalDown, int** NPCInfo, int numNPCs);
		
		int** runNPCAI(int** NPCInfo, int numNPCs);
		
		void runGame(int** NPCInfo, int numNPCs, int numTicks);
		
		void toString(int csvMode, int gameVideoMode);
		
	private:
	
		int** mapInfo;
		
		int length;
		int width;
		
		int xInd;
		int yInd;
		int isPaused;
		
		char* input;
		char* prevInput;
		char* mapString;
		
};


