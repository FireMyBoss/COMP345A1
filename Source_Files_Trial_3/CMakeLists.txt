cmake_minimum_required(VERSION 3.23)
project(Source_Files_Trial_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(character_worn_items)

add_executable(Source_Files_Trial_3
        character_worn_items/Armor.cpp
        character_worn_items/Armor.h
        character_worn_items/Belt.cpp
        character_worn_items/Belt.h
        character_worn_items/Boots.cpp
        character_worn_items/Boots.h
        character_worn_items/Helmet.cpp
        character_worn_items/Helmet.h
        character_worn_items/Ring.cpp
        character_worn_items/ring.h
        character_worn_items/Shield.cpp
        character_worn_items/Shield.h
        character_worn_items/Weapon.cpp
        character_worn_items/Weapon.h
        allcharacters.cpp
        allcharacters.h
        Backpack.h
        Character.cpp
        Character.h
        Equipment.cpp
        Equipment.h
        GroupItemH.h
        Item.h
        main.cpp
        selectItems.cpp
        TreasureChest.h)
