//
//  rec10
//  Inheritance exercise with Instruments and Musicians
//  Andrew Qu aq447
//

#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    virtual void makeSound() const = 0;
    virtual void play() const = 0;
private:
};

void Instrument::makeSound() const{
    cout << "To make a sound... ";
}

class Musician {
public:
    Musician() : instr(nullptr) {}
    
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }
    
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }
    
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    
    void perform() const {
        if (instr) instr->play();
    }
private:
    Instrument* instr;
};

class MILL {
public:
    void receiveInstr(Instrument& instr) {
        for(size_t i = 0;i < inventory.size();i++){
            if (inventory[i] == nullptr) {
                inventory[i] = &instr;
                return;
            }
        }
        inventory.push_back(&instr);
    }
    Instrument* loanOut() {
        for(size_t i = 0;i < inventory.size();i++){
            if (inventory[i] != nullptr) {
                Instrument* retPtr = inventory[i];
                inventory[i] = nullptr;
                return retPtr;
            }
        }
        return nullptr;
    }
    void dailyTestPlay() const {
        for(Instrument* instrPtr : inventory){
            if (instrPtr){
                instrPtr->makeSound();
            }
        }
    }
private:
    vector<Instrument*> inventory;
};

class Orch {
public:
    void addPlayer(Musician& recruit) {
        if (musicians.size() < 25) {
            musicians.push_back(&recruit);
        }
        else{
            cerr << "Orch at capacity" << endl;
        }
    }
    
    void play() const {
        for(Musician* player : musicians){
            player->perform();
        }
        cout << endl;
    }
private:
    vector<Musician*> musicians;
};

//----------CHILDREN OF INSTRUMENT----------
class Brass : public Instrument {
public:
    Brass(unsigned mouthSize) : mouthPieceSize(mouthSize){}
    void makeSound() const{
        Instrument::makeSound();
        cout << "blow on a mouthpiece of size ";
        cout << mouthPieceSize << endl;
    }
private:
    unsigned mouthPieceSize;
};

class Strings : public Instrument {
public:
    Strings(unsigned pitchVal) : pitch(pitchVal){}
    void makeSound() const{
        Instrument::makeSound();
        cout << "bow a string with pitch ";
        cout << pitch << endl;
    }
private:
    unsigned pitch;
};

class Percussion : public Instrument {
public:
    void makeSound() const{
        Instrument::makeSound();
        cout << "hit me!" << endl;
    }
private:
};

//----------GRANDCHILDREN OF INSTRUMENT----------
class Trumpet : public Brass {
public:
    Trumpet(unsigned mouthSize) : Brass(mouthSize){}
    void play() const override{
        cout << "Toot";
    }
private:
};

class Trombone : public Brass {
public:
    Trombone(unsigned mouthSize) : Brass(mouthSize){}
    void play() const override{
        cout << "Blat";
    }
private:
};

class Violin : public Strings {
public:
    Violin(unsigned pitchVal) : Strings(pitchVal){}
    void play() const override{
        cout << "Screech";
    }
private:
};

class Cello : public Strings {
public:
    Cello(unsigned pitchVal) : Strings(pitchVal){}
    void play() const override{
        cout << "Squawk";
    }
private:
};

class Drum : public Percussion {
public:
    void play() const override{
        cout << "Boom";
    }
private:
};

class Cymbal: public Percussion {
public:
    void play() const override{
        cout << "Crash";
    }
private:
};

//PART TWO
int main() {
    // The initialization phase
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);
    
    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
} // main
