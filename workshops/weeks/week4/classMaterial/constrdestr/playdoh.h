// playdoh.h

class playdoh {
  char colour; //private
  int weight; //private
  
  public:
    playdoh(); // default const
    ~playdoh(); // destructor

    playdoh(char c, int w = 50); // 2 arg constr

    bool isEmpty() const;
    void setColour(char c);
    void setWeight(int w);

    void display() const;
    void display(const playdoh& p) const; // Class privacy display
    void makePlaydoh();

    playdoh retCopy();
    playdoh& retRef();
};
