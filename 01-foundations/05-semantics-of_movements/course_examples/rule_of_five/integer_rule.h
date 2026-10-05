#pragma one

class Integer{
    int *m_pInt;

public: 
    Integer();
    // The copy constructor -> Always to pass a reference, to avoid loops
    Integer(int value);

    //Copy constructor
    Integer(const Integer &obj);
    //Move constructor
    Integer(Integer &&obj);

    //Copy assignment 
    Integer & operator=(const Integer &obj);

    //Move assignment
    Integer & operator=(Integer && obj);

    int GetValue() const;
    void SetValue(int value);
    ~Integer();
};