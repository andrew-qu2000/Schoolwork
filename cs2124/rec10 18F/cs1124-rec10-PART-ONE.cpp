
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

private:
    Instrument* instr;
};

class MILL {
public:
    void receiveInstr(Instrument& instr) {
        for(int i = 0;i < inventory.size();i++){
            if (inventory[i] == nullptr) {
                inventory[i] = &instr;
                return;
            }
        }
        inventory.push_back(&instr);
    }
    Instrument* loanOut() {
        for(int i = 0;i < inventory.size();i++){
            if (inventory[i] != nullptr) {
                Instrument* retPtr = inventory[i];
                inventory[i] = nullptr;
                return retPtr;
            }
        }
        return nullptr;
    }
    void dailyTestPlay() {
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
        for(int i = 0;i < musicians.size();i++){
            if (musicians[i] == nullptr) {
                musicians[i] = &recruit;
                return;
            }
        }
        musicians.push_back(&recruit);
    }
private:
    vector<Musician*> musicians;
};

//----------CHILDREN OF INSTRUMENT----------
class Brass : public Instrument {
public:
    Brass(unsigned mouthSize) : mouthPieceSize(mouthSize){}
    virtual void makeSound() const = 0;
private:
    unsigned mouthPieceSize;
};

void Brass::makeSound() const{
    Instrument::makeSound();
    cout << "blow on a mouthpiece of size ";
    cout << mouthPieceSize << endl;
}

class Strings : public Instrument {
public:
    Strings(unsigned pitchVal) : pitch(pitchVal){}
    virtual void makeSound() const = 0;
private:
    unsigned pitch;
};

void Strings::makeSound() const{
    Instrument::makeSound();
    cout << "bow a string with pitch ";
    cout << pitch << endl;
}

class Percussion : public Instrument {
public:
    virtual void makeSound() const = 0;
private:
};

void Percussion::makeSound() const{
    Instrument::makeSound();
    cout << "hit me!" << endl;
}
//----------GRANDCHILDREN OF INSTRUMENT----------
class Trumpet : public Brass {
public:
    Trumpet(unsigned mouthSize) : Brass(mouthSize){}
    void makeSound() const override{
        Brass::makeSound();
    }
    void play() const override{
        cout << "Toot";
    }
private:
};

class Trombone : public Brass {
public:
    Trombone(unsigned mouthSize) : Brass(mouthSize){}
    void makeSound() const override{
        Brass::makeSound();
    }
    void play() const override{
        cout << "Blat";
    }
private:
};

class Violin : public Strings {
public:
    Violin(unsigned pitchVal) : Strings(pitchVal){}
    void makeSound() const override{
        Strings::makeSound();
    }
    void play() const override{
        cout << "Screech";
    }
private:
};

class Cello : public Strings {
public:
    Cello(unsigned pitchVal) : Strings(pitchVal){}
    void makeSound() const override{
        Strings::makeSound();
    }
    void play() const override{
        cout << "Squawk";
    }
private:
};

class Drum : public Percussion {
public:
    void makeSound() const override{
        Percussion::makeSound();
    }
    void play() const override{
        cout << "Boom";
    }
private:
};

class Cymbal: public Percussion {
public:
    void makeSound() const override{
        Percussion::makeSound();
    }
    void play() const override{
        cout << "Crash";
    }
private:
};

// PART ONE
int main() {

    cout << "Define some instruments ------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;
    //drum.makeSound();
    //cello.makeSound();
    //cymbal.makeSound();
    //violin.makeSound();
    //tbone.makeSound();
    //trpt.makeSound();
    //Brass(12); //Brass is abstract
  
    // // use the debugger to look at the mill
    cout << "Define the MILL --------------------------------------------\n";
    MILL mill;
  
    cout << "Put the instruments into the MILL --------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
  
    cout << "Daily test -------------------------------------------------\n";
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    cout << "Define some Musicians---------------------------------------\n";
    Musician harpo;
    Musician groucho;
  	
    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    groucho.testPlay();
    cout << endl;
    groucho.acceptInstr(mill.loanOut());
    cout << endl;
    groucho.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
  
    cout << endl << endl;
  
    groucho.testPlay();
    cout << endl;
    mill.receiveInstr(*groucho.giveBackInstr());
    harpo.acceptInstr(mill.loanOut());
    groucho.acceptInstr(mill.loanOut());
    cout << endl;
    groucho.testPlay();
    cout << endl;
    harpo.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
  
    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
  
    // fifth
    mill.receiveInstr(*groucho.giveBackInstr());
    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
    mill.receiveInstr(*harpo.giveBackInstr());

  
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    cout << endl;
}
