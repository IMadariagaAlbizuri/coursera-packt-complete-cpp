#pragma one

class Integer{
    int *m_pInt;

public: 
    Integer();
    Integer(int value);
    Integer(const Integer &obj);
    int GetValue() const;
    void SetValue(int value);
    ~Integer();
    
    // Integer operator +(const Integer &a) const;
    Integer & operator ++(); // Prefix increment operatorr
    Integer & operator ++(int); // Postfix increment operator
    Integer & operator =(const Integer &obj); // Assignment operator
    Integer & operator=(Integer &&obj); //Move assignment operator

    //A friend function is a function that is not a member of a class but has access to its private and protected members. 
    //A friend function can be a global function or a member of another class. It is declared by using the keyword friend in the class definition.

    //Normally the usage of friend functions create lots of bugs, so they should be used as last resort.
    friend std::ostream & operator <<(std::ostream &out, const Integer &obj);
    friend std::istream & operator >>(std::istream &in, Integer &obj);
};