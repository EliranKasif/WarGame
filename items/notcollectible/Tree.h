//
// Created by eliran on 21/12/17.
//

#ifndef WARGAME_TREE_H
#define WARGAME_TREE_H


#include <ostream>
#include "NotCollectibleItems.h"

class Tree:public NotCollectibleItems {
public:

    /*
     * @brief Constructor
     * @param double width
     * @param double height
     */
    Tree(double width, double height);

   /*
    * @brief default Constructor
    */
    Tree();

    /*
     * @brief virtual Destructor
     */
    virtual ~Tree();

private:
    /*
     * @brief specific print for Tree
     * @param ostream &
     * @return void
     */
    virtual void toString(std::ostream &os) const override;

};


#endif //WARGAME_TREE_H
