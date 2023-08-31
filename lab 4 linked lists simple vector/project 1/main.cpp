/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 *
 * Created on April 23, 2023, 1:13 PM
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <iterator>
#include <ctime>

using namespace std;
//function prototypes
int inputValidation ();
int turn ();//turning function
int bunny_encounter ();
int snake_encounter ();
int babyDragon_encounter ();
int gameOver ();
int stoneGiant_encounter ();
int testConnection ();
int roll (int);
//global constants
int decision = 0;
string character;
int connection = 0;
bool baby = false; //for dragon baby
int hp = 14; //hit points (health)
int luck = 0; //luck from dice rolls

//inventory array values
//gives each item a value for how important it is to the story
int dagger = 1;
int flute = 1;
int foxfur = 2;
int rabbitsfoot = 2;
int snakescale = 2;
int snakefang = 2;
int geode = 1;
int stonestatue = 3;
int dragontear = 4;
//inventory array subscript counter
int item = 2;
//int inventory[7] = {dagger, flute};//inventory array
list<int> inventory{dagger, flute};

int main(int argc, char** argv) {
    char ch;//for cin.get
    int character_choice;
    int connection = 0;
    
    cout << "Dungeons and Dragons: The Forgotten Forest\n\n";
    
    cout << "Long ago, an ancient forest began to die.\n"
            "The witch of the woods cast a spell to save the forest.\n"
            "In doing so, she trapped her spirit in a magic tree.\n"
            "Years later, a King ordered for half of the forest to be\n"
            "cut down to make room for expansion. His men cut down the\n"
            "magic tree, so when the forest began to die again, so\n"
            "did the kingdom. The king has called upon you to save the land.\n"
            << endl;
            
    //cout << "test rolls\n"
      //      "d20: " << roll (20) << endl;
    cin.get(ch);
    do//1
    {
        cout << "Are you a witch, or a warlock?\n" << "Enter 1 for witch\n"
            << "Enter 2 for warlock\n";
        cin >> character_choice;
        if (character_choice == 1)
        {
            character = "witch";
        }
        else if (character_choice == 2)//1
        {
            character = "warlock";
        }
        else
        {
            cout << "Invalid entry.\n";
        }
    }
    while (character_choice != 1 && character_choice !=2);
    
    cout << "You have chosen to be a " << character << ".\n";      
    cout << "--------------------------------------------------------------\n"; 
    cout << "When you enter the forest, you hear whispering...\n"
            "The whispering is coming from the largest tree stump.\n"
            "The spirit of the stump, the witch of the woods, says that\n"
            "her wand is protected, deep in the mountain.\n"
            "You must go there, retrieve the wand, and cast a spell\n"
            "to save the forest. She says that the wand will only be\n"
            "granted to those who have a strong connection to the forest...\n\n";
    
    cout << "And so you begin your quest. You start on a path to the mountain,"
            "but you get lost...\n\n";
    cin.get(ch);
    
    for(int count = 0; count < 3; count++)//1
    {
        turn();
    }
    
    cout << "you find some bunnies about to be eaten by a fox, interact?\n"
            <<  "1. interact     2. keep walking\n";
    decision = inputValidation ();

    if (decision == 1)
    {
        bunny_encounter ();
    }
    else//1
    {
        cout << "You chose to keep going.\n\n";
    }
    
    for(int count = 0; count < 3; count++)//2
    {
        turn();
    }
    
    cout << "You stumble across an area with a lot of small tunnels going\n"
            << "into the ground, interact?\n"
            << "1. interact     2. keep walking\n";
    decision = inputValidation ();
    if (decision == 1)
    {
        snake_encounter ();
    }
    else//2
    {
        cout << "You chose to keep going.\n\n";
    }
    
    for(int count = 0; count < 3; count++)//3
    {
        turn();
    }
    
    cout << "You enter a clearing, and in the center there is a perfect\n"
            << "circle of mushrooms. Interact?\n"
            << "1. interact     2. keep going\n";
    decision = inputValidation();
    if (decision == 1)
    {
        do//2
        {
            cout << "You chose to interact.\n 1. step in circle     "
                << "2. walk around circle      3. give offering\n";
            cin >> decision;
            if (decision == 1)
            {
                cout << "The fae do not appreciate that... they curse you!\n";
                gameOver ();
            }
            else if (decision == 2)//2
            {
                cout << "You avoid the wrath of the fae, but they would\n"
                        << "have appreciated a gift.";
                connection--;
                cout << "Your connection to the forest is getting weaker.../n/n";
            }
            else if (decision == 3)
            {
                cout << "The fae appreciate your gift!\n";
                connection++;
                cout << "Your connection to the forest is growing stronger...\n\n";
            }
            else
            {
                cout << "Invalid input. Try again.\n\n";
            }
        }
        while (decision != 1 && decision !=2 && decision !=3);
    }
    else //3
    {
        cout << "You chose to keep going.\n\n";
    }
    
    for(int count = 0; count < 3; count++)//4
    {
        turn();
    }        
    
    cout << "You finally arrive at the base of the mountain.\nHowever, a"
            << "small dragon is blocking your path. Interact?\n"
            << "1. interact     2. keep walking\n";
    decision = inputValidation ();
    if (decision == 1)
    {
        babyDragon_encounter ();
    }
    else //4
    {
        cout << "You chose to keep going.\n\n";
    }

    cout << "It is slowly beginning to snow and the wind is picking up.\n"
            << "You notice a pair of skeletons huddled together, but there\n"
            << "is a small cave up ahead.\n"
            << "1. take shelter    2. keep going\n";
    decision = inputValidation ();
    if (decision == 1)
    {
        cout << "You take shelter in the cave, and find a geode in there.\n";
        //item++;
        //inventory[item] = geode;
        inventory.push_back(geode);
        connection++;
        cout << "Your connection to the forest is growing stronger...\n\n";
    }
    else//5
    {
        cout << "You fool. You have contracted frostbite.\n";
        gameOver ();
    }
    
    for(int count = 0; count < 3; count++)//5
    {
        turn ();
    }
    
    cout << "As you approach the entrance, you notice a stone giant admiring\n"
            << "something in his hands. He notices you and stares, expressionless.\n"
            << "Interact?\n 1. interact    2. keep walking\n";
    decision = inputValidation ();
    if (decision == 1)
    {
        stoneGiant_encounter ();
    }
    else
    {
        cout << "You chose to keep going.\n\n";
    }
    
    for(int count = 0; count < 3; count++)//6
    {
        turn ();
    }
    
    cout << "You enter a circular room with writing on the walls. It says:\n"
            << "Only those who have learned the ways of the forest may restore it.\n";
    testConnection ();
    cin.get(ch);
    
    cout << "You reach the top of the mountain, and find a large dragon looking\n"
            << "over the edge and crying.";
    if (baby = true)
    {
        cout << "The dragon notices you have her baby with you. She begins\n"
                << "to weep with joy as they rejoice.\n"
                << "As thanks, she gives you a dragon tear."
                << "Dragon Tear added to inventory.";
        //item++;
        //inventory[item] = dragontear;
        inventory.push_back(dragontear);
        cout << "The dragon does you a favor and flies you back to the stump.\n";
    }
    else
    {
        cout << "The dragon does you a favor and flies you back to the stump.\n"
                << "On the way there, she spots her baby and they are reunited.\n";
    }
    
    cin.get(ch);
    
    cout << "You finally make it back to the tree stump with the wand.\n"
            << "You can feel your connection to the forest telling you\n"
            << "to make an offering for the spell to work.\n\n";
    cin.get(ch);
    cout << "You put all of the items you've collected on your journey\n"
            << "on the stump in the circle."
            << "You cast a spell to restore life to the forest...\n";
    int total = 0;
    for (int count = 0; count < item; count++)
    {
       // total += inventory[count];
    }
    if (total > 7)
    {
        cout <<"... and it works! You feel the energy being restored!\n\n"
                << "Y O U    W I N ! ! !";
    }
    else
    {
        cout << "... but it didn't seem to be enough.\n"
                << "it is too late for this forest now...\n\n";
        gameOver();
    }
    return 0;
}



//functions*************************************************************
int inputValidation ()
{
    int decision = 0;
    bool answerValid = false;
    while (answerValid == false)//3
    {
        cin >> decision;
        if (decision > 2 || decision < 1)
        {
            cout << "Invalid input. Try again.\n\n";
        }
        else 
        {
            answerValid = true;
            return decision;
        }
    } 
}
//walking in the forest****************************************************
int turn ()
{
    int direction = 0;
    bool answerValid = false;
    while (answerValid == false)//4
    {
        cout << "\nLeft, right, or straight?\n"
            << "1. left    2. right    3. straight\n";
        cin >> direction;
        if (direction > 3 || direction < 1)
        {
            cout << "Invalid input. Try again.\n\n";
        }
        else 
        {
            answerValid = true;
            return direction;
        }
    } 
}
//bunny encounter *******************************************************
int bunny_encounter ()
{
    cout << "You chose to interact.\n\n"
            << "1. Scare the fox away    2. Attack the fox\n";
    decision = inputValidation ();
    if (decision == 1)//1
    {
        cout << "You must roll for Intimidation.\n";
        luck = roll(20);
        
        if (12 < luck < 20)
        {
            cout << "You rolled a " << luck << " - success! \n As the fox scurries away, "
                    "a tuft of it's fur falls off.\n"
                    "Fox Fur added to your inventory.\n";
            connection++;
            inventory.push_back(foxfur);
            cout << "Your connection to the forest is growing stronger...\n\n";
        }
        
        if (luck == 20)
        {
            cout << "You rolled a 20! Super success!\n"
                    "The fox seems to resonate with you...\n"
                    "The fox decides to protect the bunnies from other predators!\n"
                    "Your connection to the forest has grown significantly...\n";
            connection++;
            connection++;
        }
        if (1 < luck <=12)
        {
            cout << "You rolled a " << luck << "... not the best...\n"
                    "The fox was not intimidated by you, and scratches your face before running off.\n"
                    "Roll for damage.\n";
            luck = roll(4);
            hp = hp-luck;
            cout << "You took " << luck << "damage. You now have " << hp << " health.\n\n";
        }
        if (luck == 1)
        {
            cout << "You rolled a 1. Critical failure!\n"
                    "The fox eats the bunnies and then scratches you in the face!\n"
                    "Rolling for damage... \n";
            luck = roll(6);
            hp = hp-luck;
            cout << "You took " << luck << "damage. You now have " << hp << " health.\n"
                    "Your connection to the forest is growing weaker...\n\n";
            connection--;
        }
    }
    
    if (decision == 2)//2
    {
        cout << "You choose to attack with your dagger. You must roll for the attack.\n";
        luck = roll(20);
        
        if (14 <= luck <= 19)
        {
            cout << "You rolled a " << luck << "Success!\n"
                    "You attack the fox and it scurries away, wounded.\n"
                    "From it's meal, it leaves behind a rabbit's foot.\n"
                    "You take it, they are supposed to be good luck after all.\n";
            inventory.push_back(rabbitsfoot);
            connection++;
            cout << "Your connection to the forest is growing stronger...\n\n";
        }
        
        if (1 < luck < 14)
        {
            cout << "You rolled a " << luck << "... not the best...\n"
                    "The fox fights back and bites you. Rolling for damage.\n";
            luck = roll(4);
            hp = hp-luck;
            cout << "You took " << luck << " damage. You now have " << hp << " health.\n\n";
        }
        
        if (luck == 1);
        {
            cout << "You rolled a 1. Critical failure!\n"
                    "The fox bites you a few times and eats the bunnies!\n"
                    "You're pretty roughed up! Rolling for damage.\n";
            luck = roll(6); 
            hp = hp-luck;
            cout << "You took " << luck << " damage. You now have " << hp << " health.\n"
                    "Your connection to the forest is growing weaker...\n\n";
            connection--;
        }
        
        cout << "You chose to see what happens. The fox eats the bunnies,\n"
                << "leaving behind a Rabbit Foot.\nRabbit Foot added to"
                << " your inventory.\n";
        //item++;
        //inventory[item] = rabbitsfoot;
        connection++;
        inventory.push_back(rabbitsfoot);
        cout << "Your connection to the forest is growing stronger...\n\n";
    }
}

int snake_encounter ()
{
    cout << "You chose to interact.\n\n"
            << "1. use dagger     2. use flute\n";
    decision = inputValidation ();
    if (decision == 1)//3
    {
        cout << "You chose violence. You attack and kill the snakes.\n"
                << "You scavenge a Snake Fang."
                << " Snake Fang Added to your inventory.\n";
        //item++;
        //inventory[item] = snakefang;
        connection--;
        inventory.push_back(snakefang);
        cout << "Your connection to the forest is getting weaker...\n\n";
    }
    if (decision == 2)//4
    {
        cout << "You play a song to charm the snakes, and they leave\n"
                << "you alone. As they retreat, a single snake scale\n"
                << "is left behind.\nSnake Scale added to your inventory.\n";
        //item++;
        //inventory[item] = snakescale;
        connection++;
        inventory.push_back(snakescale);
        cout << "Your connection to the forest is growing stronger...\n\n";
    }
}

int babyDragon_encounter ()
{
    cout << "You chose to interact.\n\n"
            << "The dragon seems to be looking at the top of the mountain"
            << "and crying...\n 1. leave him    2. take him with you\n";
    decision = inputValidation ();
    if (decision == 1)//5
    {
        cout << "You chose to abandon the dragon and keep going.\n";
        connection--;
        cout << "Your connection to the forest is getting weaker...\n\n";
    }
    if (decision == 2)//6
    {
        cout << "You chose to take the baby dragon with you. He stops crying.\n";
        connection++;
        cout << "Your connection to the forest is growing stronger...\n\n"; 
        bool baby = true;
    }
}

int gameOver ()
{
    cout << "You feel your lifeforce slipping away...\n\n"
            << "G A M E   O V E R\n\n";
    exit(0);
}

int stoneGiant_encounter ()
{
    cout << "You approach him, but he looks intimidated by you.\n"
            << "1. step back    2. step closer\n";
    decision = inputValidation ();
    if (decision == 1)
    {
        cout << "He seemed to appreciate your consideration. He gives you\n"
                << "the rock he is holding.\n Stone Statue added to inventory.\n";
        //item++;
        //inventory[item] = stonestatue;
        connection++;
        inventory.push_back(stonestatue);
        cout << "Your connection to the forest is growing stronger...\n\n";
    }
    if (decision == 2)
    {
        cout << "He is startled by you and runs away!\n";
        connection--;
        cout << "Your connection to the forest is getting weaker...\n\n";
    }
}

int testConnection ()
{
    if (connection <= 3)
    {
        cout << "You do not understand the ways of the forest...\n"
                << "Your connection is too weak...\n"
                << "You may not have the wand. The world has lost all hope.\n";
        gameOver ();
    }
    if (connection > 3)
    {
        cout << "You seem to understand the ways of the forest...\n"
                << "Your connection is strong...\n\n";
        cout << "Suddenly, the magic wand appears in a flash of light.\n"
                << "A staircase appears, leading to the top of the mountain.\n";
    }
}

//dice roller
int roll(int sides)
{
    srand(time(NULL));
    return 1 + ((double) rand()) / RAND_MAX * sides;
}