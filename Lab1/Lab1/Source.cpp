#include<iostream>
using namespace std;

// Bieu dien so thap phan duoi dang 32 bit
void PrintBits(unsigned int x) {
    int i;
    for (i = 8 * sizeof(x) - 1; i >= 0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    cout<<"\n";
}

// Bieu dien so thap phan duoi dang 8 bit
void PrintBitsOfByte(unsigned int x) {
    int i;
    for (i = 7; i >= 0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    cout<<"\n";
}

// thuc hien x&y khong su dung dau &
int bitAnd(int x, int y)
{
    int result;

    PrintBits(x);
    PrintBits(y);
    PrintBits(~x);
    PrintBits(~y);
    PrintBits(~x | ~y);
    PrintBits(~(~x | ~y));
   
    result = ~(~x | ~y);
    
    return result;
}

// Tinh gia tri cua -x khong su dung dau -
int negative(int x)
{
    int result;

    PrintBits(x);
    PrintBits(~x);
    PrintBits(~x + 1);
    cout << "\n";
        
    result = ~x + 1;
    return result;
}

// Lay bit thu n trong bieu dien nhi phan cua x 0<n<31
// Shift Right roi &1
int getBit(int x, int n)
{
    int result;

    PrintBits(x);
    PrintBits(x>>n);
    PrintBits((x >> n) & 1);

    result = (x>>n) & 1;

    return result;
}

// Tinh x*2^n
int mulpw2(int x, int n)
{
    int result;
    n = negative(n);

    PrintBits(x);
    PrintBits(x >> n);

    result = x >> n;
    return result;
}

// Tinh x % 2^n
int modul2(int x, int n)
{
    int result = 0;
    int temp = (x >> n) << n;

    PrintBits(x);
    PrintBits(temp);
    PrintBits(x + negative(temp));

    result = x + negative(temp);

    return result;
}

// Kiem tra chan le : Lay bit cuoi cua x & 1
// Neu le tra ve 1
// Chan tra ve 0
int isOdd(int x)
{
    int result = 0;
    int temp = getBit(x, 0);
    
    PrintBits(x);
    PrintBits(getBit(result, 0));
    PrintBits(temp & 1);

    result = temp & 1;
    return result;
}

int is8x(int x)
{
    int result = 0;

    int bit1 = ~x&1;
    int bit2 = ~ (getBit(x, 1));
    int bit3 = ~ (getBit(x, 2));

    result = (bit1 & bit2 & bit3);
    return result;
}

int isPositive(int x)
{
    int result = 0;
    result = ~ getBit(x,31) & 1;
    return result;
}

int main()
{
    // Cau 1.1
    /*if (bitAnd(3, -9) == (3 & -9))
    {
        cout << "\n" <<"Pass";
    }*/

    // Cau 1.2
    /*if (negative(0) == 0 && negative(9) == -9
        && negative(-5) == 5)
    {
        cout << "\n" << "Pass";
    }*/

    // Cau 1.3
    /*if (getBit(8, 0) == 0 && getBit(3, 1) == 1 &&
        getBit(32, 5) == 1)
    {
        cout << "\n" << "Pass";
    }*/
    
    // Cau 1.4
    /*if (mulpw2(10, -1) == 5 && mulpw2(15, -2)
        == 3 && mulpw2(103, -4) == 6)
    {
        cout << "\n" << "Pass";
    }*/

    // Cau 1.5
    /*if (modul2(2, 1) == 0 && modul2(30, 2) == 2
        && modul2(63, 6) == 63)
    {
        cout << "\n" << "Pass";
    }*/

    // Cau 2.1
    /*if (isOdd(3) && !isOdd(0) && !isOdd(12))
    {
        cout << "\n" << "Pass";
    }*/

    // Cau 2.2
    /*if (is8x(16) && !is8x(3) && is8x(0))
    {
        cout << "\n" << "Pass";
    }*/
    
    if (isPositive(10) && !isPositive(-5) &&
        !isPositive(0))
    {
        cout << "\n" << "Pass";
    }

    return 0;
}