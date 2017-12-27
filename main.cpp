



#include "FileControler.h"
#include "InitCSV.h"
#include "Decoder.h"
#include "Strategy.h"
#include "HumanStrategy.h"
#include "ComputerStrategy.h"
#include "InitObject.h"

int main() {
    FileControler *file = new InitCSV("/home/eliran/Desktop/CPP/WarGame/init_file_example.csv");
    Decoder *buffer = new Decoder(file);
    InitObject init(buffer);
    init.Initialze();
    FileControler *file2 = new InitCSV("/home/eliran/Desktop/CPP/WarGame/player1_file_example.csv");

    Strategy *s = new HumanStrategy(buffer->getSoldiers(),buffer->getBattlefieldheight()
    ,buffer->getBattlefieldwidth(),file2);
    s->implementStrategy();
    const std::vector<std::list<Point2d>> &points = s->getDestination();
    std::cout << std::endl;
    std::cout << std::endl;
    int i = 0;
    for (auto &t:points) {
        std::cout << i;
        auto p = t.begin();
        while (p != t.end()) {
            std::cout << *p << ",";
            ++p;
        }

        i++;
        std::cout << std::endl;
    }
        ComputerStrategy cp(buffer->getSoldiers(),buffer->getBattlefieldheight()
                ,buffer->getBattlefieldwidth());
        cp.implementStrategy();
    const std::vector<std::list<Point2d>> &points2=cp.getDestination();

    std::cout << std::endl;
     i = 0;
    for (auto &t:points2) {
        std::cout << i;
        auto p = t.begin();
        while (p != t.end()) {
            std::cout << *p << ",";
            ++p;
        }

        i++;
        std::cout << std::endl;
    }

    return 0;
}