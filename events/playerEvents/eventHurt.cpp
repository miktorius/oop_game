#include "eventHurt.hpp"
#include <iostream>

void eventHurt::execute(Controller& ctrl){
    Player& player = ctrl.getPlayer();
    int dmg = 50;
    int weight = player.getWeight();
    int HP = player.getHP();
    if (weight >= 50){
        if (HP - dmg < 0){ player.setHP(0); }
        else { player.setHP(HP - dmg); }
    }
}

char eventHurt::getSymbol(){
    return sym;
}