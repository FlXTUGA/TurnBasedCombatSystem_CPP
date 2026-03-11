**Turn-Based Combat System (C++)**

A simple turn-based combat system written in C++ designed as a learning project for gameplay programming and object-oriented design.

The goal of this project is to explore how classic RPG combat systems work internally, including character stats, defensive mechanics, and turn resolution.

This project is part of my journey to become a gameplay programmer.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Features

## Combat System
- Turn-based combat loop
- Multiple enemies
- Player actions:
  - Attack
  - Defend
  - Open Inventory
  - Wait
- Turn resolution system

## Character System
- Character health and max health
- Damage and defense values
- Race and Class modifiers affecting gameplay

## Item System
- Inventory system
- Base `Item` class
- Polymorphic item behavior
- Healing potion (`PocaoVida`) implementation

## UI System
- Console-based UI module
- Colored terminal output
- Typewriter-style text effect
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Project Structure

```
Project2/
│
├── Character # Character stats and combat interactions
├── PlayerClass # Player-specific behaviour
├── Combat # Combat flow and turn resolution
├── Inventario # Inventory management system
├── Item # Base item class
├── PocaoVida # Healing potion implementation
├── Raca # Race modifiers and attributes
├── UI # Console UI and player interaction
└── main.cpp # Program entry point
```
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Gameplay Example**

Player: TIGAS
HP: 100 / 100

Enemies:
Goblin HP: 30

Skeleton HP: 40

Choose action:
[1] Attack
[2] Defend
[3] Inventory
[4] Wait


Example mechanics:
- Attack deals damage to the enemy
- Defend reduces incoming damage
- Wait skips the turn
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
# Technologies Used

- **C++**
- Object-Oriented Programming
- Polymorphism
- Modular project architecture
- Console-based user interface
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Learning Goals**
This project focuses on practicing:

- Object-Oriented Programming in C++
- Gameplay system architecture
- Turn-based combat mechanics
- Polymorphism and item systems
- Separation of gameplay logic and UI
- Modular project structure
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Future Improvements**
Planned features include:

- Status effects (poison, stun, burn)
- Skills and abilities
- Critical hit system
- Experience and leveling system
- Random encounters
- Improved enemy AI
- Equipment system
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
**Author**
TIGAS

Computer Science student and aspiring Gameplay Programmer.
