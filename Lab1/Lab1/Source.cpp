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

//  Thuc hien x&y khong su dung dau &
//  Su dung dinh luat De Morgan
int bitAnd(int x, int y)
{
    int result;

    result = ~(~x | ~y);
    
    return result;
}

//  Tinh gia tri cua -x khong su dung dau -
//  Chuyen ve ~ cua x
//  Sau do + 1
int negative(int x)
{
    int result;
        
    result = ~x + 1;
    return result;
}

// Lay bit thu n trong bieu dien nhi phan cua x 0<n<31
// Dich phai n bits roi &1
int getBit(int x, int n)
{
    int result;

    result = (x>>n) & 1;

    return result;
}

// Tinh x*2^n
// ket qua = x * 1/(2*n)
int mulpw2(int x, int n)
{
    // Chuyen ve negative cua n 
    int result;
    n = negative(n);

    result = x >> n;
    return result;
}

// Tinh x % 2^n
// temp = Dich bit sang n phai don vi sau do dich trai n don vi
// Modul = x - temp 
int modul2(int x, int n)
{
    int result = 0;
    int temp = (x >> n) << n;

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

    result = temp & 1;
    return result;
}

//  Kiem tra so co chia het cho 8 hay khong
//  So chia het cho 8 la 3 bits cuoi = 000
int is8x(int x)
{
    int result = 0;

    // Lay gia tri 3 bits cuoi
    int bit1 = ~x&1;
    int bit2 = ~ (getBit(x, 1));
    int bit3 = ~ (getBit(x, 2));

    // su dung phep & 3 gia tri xem co ket qua la 1
    result = (bit1 & bit2 & bit3);
    return result;
}



// Tra ve 1 neu x duong (x>0)
int isPositive(int x)
{
    int result = 0;

    //  Lay bit thu 31
    //  Kiem tra xem x co phai la so 0 hay khong 
    //      Neu x = 0 (!x = 1) 
    //      Nguoc lai x = 0
    //  Kiem tra gia tri sau khi dung phep OR voi 2 gia tri tren co bang 0 hay khong
    //      Neu  = 1 : so > 0
    //      Nguoc lai : so <= 0
    result = !((((x>>31)) & 1) | !x);
    
    return result;
}

//  Kiem tra so < 0
//  Neu <= 0 tra ve 1 
//  Nguoc lai tra ve 0 
int CheckPositive(int x)
{
    int result = 0;
    result = !((x >> 31) & 1);

    return result;
}

//  Tra ve 1 neu x >= 2^n
int isGE2n(int x, int n)
{
    int result = 0;

    // Dich trai n lan de tinh gia tri cua 2^n
    int temp =  1 << n;

    //  Tinh gia tri cua x - 2^n 
    //      Neu > 0 : x >= 2^n
    //      Nguoc lai : x < 2^n
    result = x + negative(temp);

    return (CheckPositive(result));
}

int main()
{
    // Cau 1.1
    if (bitAnd(3, -9) == (3 & -9))
    {
        cout << "\n" <<"Pass";
    }

    // Cau 1.2
    if (negative(0) == 0 && negative(9) == -9
        && negative(-5) == 5)
    {
        cout << "\n" << "Pass";
    }

    // Cau 1.3
    if (getBit(8, 0) == 0 && getBit(3, 1) == 1 &&
        getBit(32, 5) == 1)
    {
        cout << "\n" << "Pass";
    }
    
    // Cau 1.4
    if (mulpw2(10, -1) == 5 && mulpw2(15, -2)
        == 3 && mulpw2(103, -4) == 6)
    {
        cout << "\n" << "Pass";
    }

    // Cau 1.5
    if (modul2(2, 1) == 0 && modul2(30, 2) == 2
        && modul2(63, 6) == 63)
    {
        cout << "\n" << "Pass";
    }

    // Cau 2.1
    if (isOdd(3) && !isOdd(0) && !isOdd(12))
    {
        cout << "\n" << "Pass";
    }

    // Cau 2.2
    if (is8x(16) && !is8x(3) && is8x(0))
    {
        cout << "\n" << "Pass";
    }
    
    // Cau 2.3
    if (isPositive(10) && !isPositive(-5) &&
        !isPositive(0))
    {
        cout << "\n" << "Pass";
    }

    // Cau 2.4
    if (isGE2n(15, 1) && isGE2n(8, 3) &&
        !isGE2n(12, 4))
    {
        cout << "\n" << "Pass";
    }

    return 0;
}