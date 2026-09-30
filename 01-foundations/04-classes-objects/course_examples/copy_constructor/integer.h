#pragma one

class Integer{
    int *m_pInt;

    public: 
        Integer();
        // The copy constructor -> Always to pass a reference, to avoid loops
        Integer(Integer &obj);
        Integer(int value);
        int GetValue() const;
        void SetValue(int value);
        ~Integer();
};