//playdoh.h
//

struct playdoh {
  private:
  char colour;
  int weight;
  public:
  void setColour(char c);
  void setWeight(int w);
  void display() const;
};

void display();
