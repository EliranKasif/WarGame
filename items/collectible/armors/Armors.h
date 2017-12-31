//
// Created by eliran on 18/12/17.
//

#ifndef WARGAME_ARMORS_H
#define WARGAME_ARMORS_H


#include "../CollectibleItems.h"

class Armors: public CollectibleItems {

public:
    /*
     * @brief Constructor
     * @param double armor level
     */
    Armors(double _armorlevel);

    /*
     * @brief default Constructor
     */
    Armors();

    /*
     * @brief virtual Destructor
     */
    virtual ~Armors();

    /*
     * @brief get the level of the armor
     * @return const int
     */
    const double getLevelarmor() const;

protected:
    /*
     * @brief pure virtual func for specific print of the derived classes
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const override =0;

private:
    const double levelarmor;

};


#endif //WARGAME_ARMORS_H
