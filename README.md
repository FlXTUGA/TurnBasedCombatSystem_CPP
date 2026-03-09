**Turn-Based Combat System (C++)**

A simple turn-based combat system written in C++ designed as a learning project for gameplay programming and object-oriented design.

The goal of this project is to explore how classic RPG combat systems work internally, including character stats, defensive mechanics, and turn resolution.

This project is part of my journey to become a gameplay programmer.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Features**

- Turn-based combat loop

- Player actions:
  - Attack
  - Defend
  - Wait

- Character stats system:
  - Health
  - Max Health
  - Damage
  - Defense

- Defense mechanic that reduces incoming damage
  - Console UI with:
  - Typewriter text effect
  - Colored output

- Modular code structure using multiple source files
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Project Structure

```
Project2/
│
├── main.cpp
│   Entry point of the program
│
├── Char.h / Char.cpp
│   Character class and combat logic
│
├── Combat.h / Combat.cpp
│   Handles the combat loop and turn system
│
├── Menu.h / Menu.cpp
│   Console UI utilities (menu, colors, typewriter text)
```
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Gameplay Example**
Player: TIGAS  HP: 100/100
Enemy: Rogerio HP: 60/60

Choose an action:
1) Attack
2) Defend
3) Wait
>

Example mechanics:
- Attack deals damage to the enemy
- Defend reduces incoming damage
- Wait skips the turn
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**How To Run**

Requirements:
- C++ compiler (g++, clang, or MSVC)
- Windows terminal (color support currently uses Windows API)

Compile example:
g++ main.cpp Combat.cpp Menu.cpp Char.cpp -o combat

Run:
./combat
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Learning Goals**
This project focuses on practicing:
- Object-Oriented Programming
- Class design
- Encapsulation
- Turn-based gameplay logic
- Modular C++ project structure
- Basic terminal UI
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Future Improvements**
- Planned features:
- [x] Multiple enemies
- [ ] Status effects
- [ ] Skills and abilities
- [x] Inventory system
- [ ] Random encounters
- [ ] Critical hits
- [ ] Experience and leveling
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Author**
TIGAS

Computer Science student and aspiring Gameplay Programmer.

Currently building a C++ portfolio with small gameplay systems and mechanics.

License

This project is open source and available under the MIT License.
