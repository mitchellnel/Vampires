# Vampires
__This is the OOP version of the Vampires program. The non-OOP version (along with the description of this program, and the classes within it) can be found at the [Vampires-no-OOP](https://github.com/mitchellnel/Vampires-no-OOP) repository. This project simply focuses on organising the code into several header and source files, and then adding one additional feature.__

#### Concepts:
* Source and header files
* #include guards

## Organising the code into Header and Source files
The vampires.cpp file was taken from the [Vampires-no-OOP](https://github.com/mitchellnel/Vampires-no-OOP) project, and divided into appropriate header files and implementation files (one pair of files for each class). This resulted in 10 files:
* Player.h
* Player.cpp
* Vampire.h
* Vampire.cpp
* Arena.h
* Arena.cpp
* Game.h
* Game.cpp
* globals.h
* utilities.cpp

The main routine was also placed in its own file, main.cpp.

Each header files had its own include guards, and each source file was sure to #include the headers that it needed. And __even if one of those #included files already #included a header file within it, that same header file was also #included in the source file.__ For example, Player.cpp already #included "globals.h", however, for code readability and "what makes sense to anyone reading the program", globals.h was also #included in Arena.cpp (despite the fact that #including "Player.h" would already lead to globals.h being included in the environment.

To avoid a "circular" #include process, foward declarations of classes were used where necessary. For exaxmple, Arena.h has data members for the Arena class that are Vampires and a Player, and both Vampire.h and Player.h have data members for the Arena that the Vampire/Player class belong to, but putting #include "Player.h" leads to Arena.h needing to be included, which needs Player.h to be included, which needs Arena.h to be included etc. etc. So, to avoid this circular dependency, Arena.h has a forward class declaration for Player and Vampire, and both Player and Vampire have a foward class declaration for Arena.

Global constants were placed in their own header file named globals.h. The prototypes for any utility functions (lilke attemptMove or clearScreen) were also palced in this file. The implementations were then placed in utilities.cpp.

Functions that happen to have utility, but are only used by one class implementation (e.g. recommendMove in Game.cpp) are declared and implemented in that class's header and implementation file.

## The History feature
In this version of the Vampires game, we are adding a new command: h for History.

This command shows the user for each grid point how many times a vampire has started its turn poisoned, but alive, at that grid point.

A dot means 0, an alphabetical character A through Y means 1 through 25 (A=1, B=2 etc.), and Z means 26 or more.

To achieve this, a History class was defined with the following public interface:
```
class History
	{
	  public:
	    History(int nRows, int nCols);
	    bool record(int r, int c);
	    void display() const;
	};
```
The constructor for this class initialises a History object that corresponds to an Arena with nRows and nCols columns. You may assume (i.e. no need to check) that these arguments will not exceed MAXROWS and MAXCOLS, respectively, and that neither will be less than 1.

The record function is to be called to notify the History object that a Vampire has started its turn poisoned but alive at a grid point. The function returns false if row r, column c is not within bounds; otherwise, it returns true after recording what it needs to do. This function expects its parameters to be expressed in the same coordinate system as an Arena (e.g. row 1, column 1 is the upper-left-most position).

The display function clears the screen and displays the history grid as the provided programmes do. This function does clear the screen, display the history grid, and write an empty line after the history gird; it does not print the Press enter to continue. message after the display.

The class declaration was placed in History.h, and the implementation for its member functions in History.cpp.

A data member of type History was added to the Arena class, and a member function that returns a reference to its History object was added.
