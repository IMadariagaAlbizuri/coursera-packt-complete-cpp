#pragma one

class Integer{
    int *m_pInt;

    public: 
        Integer();
        // The copy constructor -> Always to pass a reference, to avoid loops
        Integer(int value);
        Integer(const Integer &obj);
        Integer(Integer &&obj);
        int GetValue() const;
        void SetValue(int value);
        ~Integer();
};