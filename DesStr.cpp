#include "DesStr.h"
#include<string.h>
#include<cstdlib>
DecStr::DecStr(int val) : Stroka(val)

{

    cout << "DecStr::DecStr(int val):Stroka(val),val=" << val << endl;
}

DecStr::~DecStr()

{

    cout << "DecStr::~DecStr()" << endl;
}

DecStr::DecStr(const char *Str) : Stroka(Str)

{

    for (int i = 0; i < len; i++)

    {

        if (!(pCh[i] >= '0' && pCh[i] <= '9'))

        {

            cout << "Bad stroka, pCh[" << i << "]=" << pCh[i] << endl;

            if (pCh)
                delete[] pCh;

            len = 1;

            pCh = new char[len + 1];

            pCh[0] = '0';
            pCh[1]='\0';

            return;
        }
    }

    cout << "DecStr::DecStr( char* Str):Stroka(Str)" << endl;

    //cout << "fun1=" << fun1() << endl;
}

DecStr::DecStr(const DecStr &from) : Stroka(from)

{

    cout << "DecStr::DecStr(const DecStr& from) : Stroka(from)" << endl;
}

DecStr &DecStr::operator=(const DecStr &Ds)

{

    if (&Ds != this)

    {

        delete[] pCh;

        len = strlen(Ds.pCh);

        pCh = new char[len + 1];

        strcpy(pCh, Ds.pCh);
    }

    cout << "DecStr& DecStr::operator=(const DecStr& Ds)" << endl;

    return *this;
}

// Проверить алгоритм функции, может содержать ошибки!!!

DecStr operator+(const DecStr &pobj1, const DecStr &pobj2)

{

    int num1, num2;

    DecStr tmp;

    num1 = atoi(pobj1.GetStr());

    num2 = atoi(pobj2.GetStr());

    //char* pChTmp;

    char *pTmpCh;

    int A = num1 + num2;

    if (pobj1.len >= pobj2.len)

    {

        pTmpCh = new char[pobj1.len + 1];
    }
    else

    {

        pTmpCh = new char[pobj2.len + 1];
    }
    
    sprintf(pTmpCh,"%d",A);
    if (tmp.pCh)
        delete[] tmp.pCh;

    tmp.pCh = pTmpCh;

    cout << tmp.pCh << endl;

    tmp.len = strlen(tmp.pCh);

    cout << tmp.len << endl;

    cout << "DecStr operator + (const DecStr& pobj1,const DecStr& pobj2)" << endl;

    return tmp;
}