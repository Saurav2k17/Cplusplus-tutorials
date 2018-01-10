#ifndef SALLY_H
#define SALLY_H


class Sally
{
    public:
        Sally(int a, int b);
        void print();
    protected:

    private: //variables should be declared in private section and could be accessed using public member functions
        int regVar;
        const int constVar;
};

#endif // SALLY_H
