/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 *
 * Created on April 23, 2023, 4:54 PM
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <iterator>
#include <ctime>

int roll (int);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int race;
    int health, armor;
    cout <<"Choose your character: \n"
            "1. Elf Wizard: Elegant and unearthly, you are a brilliant and formidable spellcaster. Entranced by the promise of power, your quest for magical knowledge never ends.\n"
            "2. Dwarf Bard: You're the life of the party, inspiring others with magic and song. An entertainer at heart, your gift for storytelling is unmatched.\n"
            "3. Human Druid: You possess a deep affinity with nature, loathing the unnatural and striving for harmony. Embody nature's resilience and even shapeshift into an animal with wild, elemental magic.\n";
    cin >> race;
    
    if (race == 1)
    {
        
    }
    return 0;
}

//dice roller
int roll(int sides)
{
    srand(time(NULL));
    return 1 + ((double) rand()) / RAND_MAX * sides;
}