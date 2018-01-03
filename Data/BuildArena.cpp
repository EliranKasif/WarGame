//
// Created by eliran on 03/01/18.
//

#include "BuildArena.h"
void BuildArena::buildArena(Environment& arena,InitObject& data){
    arena.setWSize(data.getBattlefieldwidth());
    arena.setHSize(data.getBattlefieldheight());
    arena.reSizeArena();
    const auto &Players = data.getPlayers();
    std::vector<Player *>::const_iterator itPlayers = Players.begin();
    while (itPlayers != data.getPlayers().cend()) {//loop over Players
        const auto &Soldier = (*itPlayers)->getArmy();
        std::map<Soldiers *, std::list<Point2d>>::const_iterator itSoldiers = Soldier.begin();
        while (itSoldiers != (*itPlayers)->getArmy().cend()) {//loop over Soldiers for each player.
            Soldiers *s2 = (*itSoldiers).first;
            size_t x = (size_t) s2->getSoldierLocation().getX();
            size_t y = (size_t) s2->getSoldierLocation().getY();
            arena.addSoldier(x, y, s2);
            ++itSoldiers;
        }
        ++itPlayers;
    }


    auto &Item = data.getItems();
    auto itItems = Item.begin();
    while (itItems != Item.end()) {//loop over Items on map.
        Items &i = (**itItems);
        size_t x = i.getLocation().getX();
        size_t y = i.getLocation().getY();
        arena.addItem(x, y, i);
        ++itItems;
    }
}
