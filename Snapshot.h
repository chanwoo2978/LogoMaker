//
// Created by Chan Lee on 3/24/22.
//

#ifndef INPUTTEXTPROJECT_SNAPSHOT_H
#define INPUTTEXTPROJECT_SNAPSHOT_H
#include <iostream>

class Snapshot {
private:
    std::string data;

public:
    Snapshot();
    Snapshot(std::string letter);
    void setString(std::string string);
    std::string getString() const;

    // this function will return a snapshot of the object's current state
    virtual Snapshot& getSnapshot();

    // this function will apply a snapshot to the object.
    //This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot);

};



#endif //INPUTTEXTPROJECT_SNAPSHOT_H
