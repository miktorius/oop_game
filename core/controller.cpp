#include "controller.hpp"
#include <iostream>
#include <stdlib.h>
#include "../map/field.hpp"
#include "../graphics/field_view.hpp"
#include "../utils/vector2i.hpp"

Controller::Controller(Mediator *mediator, int w, int h) 
    : field(Field(w, h)), 
    player(Player()), 
    w(w), h(h),
    mediator(mediator),
    view(FieldView()) {}

Controller::Controller(Mediator *mediator) 
    : field(Field()), 
    player(Player()), 
    w(field.getSize().x), h(field.getSize().y),
    mediator(mediator),
    view(FieldView()) {}

void Controller::run() {
    field.changeCellPassability({1,1}, false);
    view.drawField(field, field.getPlayerPosition());
}

void Controller::onCommand(UserCommand cmd){
    Vector2i tmpPos = field.getPlayerPosition();
    //field.getMap()[tmpPos.x][tmpPos.y].detectPlayer();
    switch(cmd) {
    case UserCommand::UP:
        tmpPos.y -= 1;
        break;
    case UserCommand::LEFT:
        tmpPos.x -= 1;
        break;
    case UserCommand::DOWN:
        tmpPos.y += 1;
        break;
    case UserCommand::RIGHT:
        tmpPos.x += 1;
        break;
    case UserCommand::ESC:
        mediator->endGame();
        break;
    }
    if (cmd == UserCommand::ESC) {
        system("clear");
    }
    else {
        tmpPos.x = (tmpPos.x + w) % w;
        tmpPos.y = (tmpPos.y + h) % h;
        if (field.getCellPassability(tmpPos)){
            field.setPlayerPosition(tmpPos);
        }
        view.drawField(field, field.getPlayerPosition());
    }
}
