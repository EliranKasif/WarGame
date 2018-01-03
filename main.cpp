




#include "game/Game.h"

int main (int argc, char *argv[])  {

    Game game;
    try {
        game.read(argc,argv);
        game.initDataStructure();
        game.GameLogic();
        game.GameOver();
    }
    catch (const MyException& e){
        std::cerr<<e.what();
        exit(1);
    }





















    //std::cout<<dataStructure;

//
//    std::list<FileControler*> filecontrolerlist;
//    FileControler *file = new InitCSV("/home/eliran/Desktop/CPP/WarGame/init_file_example.csv");
//    Decoder *buffer = new Decoder(file);
//    InitObject init(buffer);
//    FileControler *file2 = new InitCSV("/home/eliran/Desktop/CPP/WarGame/player1_file_example.csv");
//    filecontrolerlist.emplace_back(file2);
//    auto it= filecontrolerlist.begin();
//    init.Initialze(it);
//    std::cout<<init<<std::endl;
//    Environment environment;
//    environment.setWSize(init.getBattlefieldwidth());
//    environment.setHSize(init.getBattlefieldheight());
//    environment.build();
//    auto& s=init.getPlayers();
//    auto& v=s[0]->getArmy();
//    const auto& it2=v.begin();
//    Soldiers* s2=(*it2).first;
//    size_t x=(size_t)s2->getSoldierLocation().getX();
//    size_t y=(size_t)s2->getSoldierLocation().getY();
//    environment.addSoldier(x,y,s2);
//    //auto& check=environment.SolidersEnviroment[1][3];
//    //const auto& ity=check.begin();
//    //std::cout<<**ity;
//
//
//    delete(buffer);
//    delete(file);
//    delete(file2);










//    Strategy *s = new HumanStrategy(file2);
//    s->implementStrategy();
//    const std::vector<std::list<Point2d>> &points = s->getDestination();
//    std::cout << std::endl;
//    std::cout << std::endl;
//    int i = 0;
//    for (auto &t:points) {
//        std::cout << i;
//        auto p = t.begin();
//        while (p != t.end()) {
//            std::cout << *p << ",";
//            ++p;
//        }
//
//        i++;
//        std::cout << std::endl;
//    }
//        ComputerStrategy cp(buffer->getSoldiers(),buffer->getBattlefieldheight()
//                ,buffer->getBattlefieldwidth());
//        cp.implementStrategy();
//    const std::vector<std::list<Point2d>> &points2=cp.getDestination();
//
//    std::cout << std::endl;
//     i = 0;
//    for (auto &t:points2) {
//        std::cout << i;
//        auto p = t.begin();
//        while (p != t.end()) {
//            std::cout << *p << ",";
//            ++p;
//        }
//
//        i++;
//        std::cout << std::endl;
//    }

    return 0;
}