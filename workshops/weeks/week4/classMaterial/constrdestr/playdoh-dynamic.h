// playdoh-class.h

class playdoh {
  char colour; //private
  int weight; //private
  char* type;
  
  public:
    playdoh(); // our constr
    ~playdoh(); // our destr
    playdoh(char c, int w, const char* t = "kid friendly"); // overloaded 3 arg constr
    void setColour(char c);
    void setWeight(int w);
    void setType(const char* t);
    void display() const;
};

const int x = 0;
