//
// Created by tiago on 09/10/2019.
//

#include "FootbalPlayer.h"

FootbalPlayer::FootbalPlayer(string position, string club, const float weight, const float height, float pass_value,bool injury):Person(name,birthdayDate) {
    this->position=position;
    this->club = club;
    this->weight= weight;
    this->height = height;
    this->pass_value = pass_value;
    this->injury= injury;

}
