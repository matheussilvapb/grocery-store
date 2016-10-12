#ifndef GROCERY_STORE_HPP
#define GROCERY_STORE_HPP

#include "circular_list.hpp"
#include "cashier.hpp"

class GroceryStore {
public:
    GroceryStore(unsigned int timeToBeSimulated,
            unsigned int paceToCreateClients,
            structures::CircularList<Cashier>&& cashierList);
    void simulate();
    void showResults();

private:
    void createClient();
    bool willGiveUp(const Client&);
    std::size_t queueSize(const Cashier&, bool);

    unsigned int timePassed{0u}; // in seconds
    unsigned int numberOfClientsGone{0u};
    unsigned int lostShoppingValue{0u};
    unsigned int timeToBeSimulated_;
    unsigned int paceToCreateClients_;
    structures::CircularList<Cashier> cashierList_;
};

#endif

