#ifndef SPELLCHECKER_ORDER_H
#define SPELLCHECKER_ORDER_H

// Used by the priority queue to order the words
struct Order {
    int index;
    int score;

    Order(int index, int score) {
        this->index = index;
        this->score = score;
    }

    bool operator < (const Order &other) const {
        return score > other.score;
    }
};

#endif //SPELLCHECKER_ORDER_H
