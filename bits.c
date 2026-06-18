/* 
 * CS:APP Data Lab 
 * 
 * <DAOVANDAT_22022172@vnu.edu.vn>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*Bit x and y = 1*/
  int both_1 = x&y;
  /*Bit x and y = 0*/
  int both_0 = (~x)&(~y);
  /*XOR Bit x and y không trùng nhau*/
  return (~both_0)&(~both_1);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /*Khoi tao bit ban dau 1*/
  int startbit = 1;
  /*Dich trai 31 de vao bit Start - Dấu*/
  return startbit << 31 ;
  /*Chuoi bit dang: 100...000 */
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {/*Tmax = 0xFFFFFFFF,0x111..111*/
  /*x is Tmax, +1 overflow x_plus = Tmin*/
  int x_plus_1 = x+1;
  /*x is Tmax, flipped = Tmax*/
  int flipped = ~x_plus_1;
  /*So sanh x and flipped*/
  /*Same is_equal == 0*/
  int is_equal = !(x^flipped);
  /*Loai tru truong hop x=-1, x+1 = 0, flipped = 0xFFFFFFFF*/
  int not_minus_1 = !!x_plus_1;
  /*Ket hop 2 dieu kien*/
  return is_equal&not_minus_1;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = 0xAA;/*0xAA = 10101010 < 255*/
  int odd_bits;
  int check_odd;
  mask = (mask<<8)|0xAA;/*Upto 16bit 0xAAAA*/
  mask = (mask<<16)|mask;/*Upto 32bit 0xAAAAAAAA*/
  /*Lọc bit lẻ, bit chan == 0*/
  odd_bits=x&mask;
  /*Check odd_bits == mask*/
  check_odd = odd_bits ^ mask;

  return !check_odd;

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*Đảo ngược toàn bộ bit*/
  int flipped = ~x;
  /*Cộng thêm 1 = phép bù 2*/
  return flipped + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {/*0x31 = 0011 0001 --> 0x39 = 0011 1001 */
  /*Dich phai 4 bit kiem tra 4 bit dau*/
  int upper_bits = x>>4;
  int is_upper_3 = !(upper_bits ^ 0x3);
  /*Loc 4 bit sau cua x & 1111*/
  int lower_bits = x&0xF;
  /*Tinh hieu 9 - lower_bits*/
  int sub = 9 + (~lower_bits+1);
  /*Kiem tra Start Bit, dấu la 0 or 1*/
  /*Dich phai 31 bit */
  int is_0 = !((sub >> 31)&1);
  /*Reurn 1 khi both is true*/
  return is_upper_3&is_0;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {/*(0xFFFFFFFF&y)|(0x00000000&z)=y*/
  /*Chuyen doi ve 1 bit 0 or 1*/
  int x_status = !x;
  /*Đưa lên bit dấu thực hiện bước sau*/
  int start_bit = x_status<<31;
  /*Copy start bit xuong toan bo make mask 0xFFFFFFFF or 0x00000000*/
  int mask = start_bit>>31;
  /*Thuc hien phep toan ban dau*/
  return (mask & z)|(~mask & y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {/*2 truong hop cung dau va khac dau*/
  /*Lay bit start xac dinh dau cua x,y*/
  int start_x=(x>>31)&1;
  int start_y=(y>>31)&1;
  /*Kiem tra cung dau hay khong*/
  int is_diff_start = start_x^start_y;
  /*TH1 (khau dau) x<=y khi start_x == 1 => Giu lai dau cua x*/
  int case_diff_start = is_diff_start&start_x;
  /*TH2 (cung dau) tinh y-x*/
  int sub = y+(~x+1);
  /*Lay bit dấu cua sub. Neu sub >=0 start_bit_sub == 0 */
  int start_bit_sub = (sub>>31)&1;
  /*TH2 đúng: Cùng dấu (is_diff_start) == 0 and start_bit_sub == 0*/
  int case_same_start = (!is_diff_start)&(!start_bit_sub);
  
  return case_diff_start|case_same_start;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*start_bit_x | start_bit_neg_x == 1 if x!=0*/
  /*strat_bit_x | start_bit_neg_x == 0 if x==0*/
  int Neg_x = ~x +1; /*Bù 2 lấy số âm*/
  /*Lấy 2 dấu start_bit_x or start_bit_neg_x*/
  int combined_start_bit = x|Neg_x;
  /*Dịch phải 31 bit copy start_bit*/
  /*x != 0, dịch phải là -1 0XFFFFFFFF*/
  /*x == 0, dịch phải là 0 0x00000000*/
  int result = combined_start_bit >>31;

  /*x !=0, return 0 = result +1*/
  /*x ==0, return 1 = result +1*/
  return result+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {/*tìm bit 1 cao nhất binary search*/
  int start_bit, b16,b8,b4,b2,b1,b0;
  /*Xác định dấu của số*/
  start_bit = x>>31;
  /*Nếu âm đảo bit, nếu dương giữ nguyên*/
  x= (start_bit & ~x)|(~start_bit & x);
  b16 = !(!(x>>16))<<4;/*Xác định 16 bit đầu có bit 1 hay không*/
  /*Nếu 16 bit đầu có chứa 1 => !!(x>>16) =1 dịch trái 4 thì b16=16 bit 1 nằm trong 16 bit đầu*/
  /*Nếu 16 bit đầu không chứa 1 => !!(x>>16) =0 dịch trái 4 vẫn là 0*/
  x=x>>b16;
  /*Nếu có bit 1 trong 16 bit đầu bỏ qua 16 bit sau tiếp tục tìm*/
  /*Nếu không có bit 1 trong 16 bit đầu giữ nguyên x tìm trong 16 bit sau*/
  b8 =(!!(x>>8))<<3;
  x=x>>b8;
  /* Tương tụ thực hiện phân chia tìm bit 1*/
  b4 = (!!(x>>4))<<2;
  x=x>>b4;

  b2 = (!!(x>>2))<<1;
  x=x>>b2;

  b1 = (!!(x>>1));
  x=x>>b1;

  b0=x;

  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /*Chia số thực thành 3 phần*/
  unsigned sign = uf&0x80000000;
  unsigned exp = (uf >>23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;
  /*TH1: Số vô cùng Scale vẫn vô cùng*/
  if(exp == 0xFF) return uf;
  /*TH2: Số siêu nhỏ tiệm cận 0 => dịch trái 1 bit là x2*/
  if(exp==0) return sign | (uf << 1);/*Giu nguyên dấu của số*/
  /*TH3 Số bình thường => tăng số mũ lên 1 = x2 lần*/
  exp = exp +1 ;
  if (exp == 0xFF) frac = 0;
  /*Khi tang len tràn số 255 => số thành vô cùng*/
  return sign | (exp <<23)|frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  /*Tách các phần để lấy chuyển thành số thực*/
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf>>23)&0xFF;
  unsigned frac = uf & 0x7FFFFF;
  int E = exp -127;
  unsigned mantissa;
  /*Số quá nhỏ exp < 1 => số 0*/
  if(E<0){
  return 0;
  }
  /*Số quá lớn E > 31 => chuyển về số vô cùng siêu lớn*/
  if(E>31){
    return 0x80000000;
  }
  /*Thêm bit 1 bit thứ 23 trước dấu phẩy đánh dấu phần thập phần*/
  mantissa = frac | 0x00800000;
  if(E>23){
    mantissa = mantissa << (E-23);/*Nhân số lên 2^E lần*/
  }else{
    mantissa = mantissa >>(23-E);/*Dịch phải giảm đi 2^E lần*/
  }
  if(sign){
    return -mantissa;
  }
  return mantissa;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {/*1.frac*2^exp-127; x=exp-127, frac = 0*/
    if(x>127){
      return 0x7F800000;/*Too Large return +INF*/
    }
    if(x>=-126){/*Vung so thong thuong*/
      int exp = x+127;
      return exp <<23;/*Dich trai 23 bit ve phan mu exp*/
    }
    if(x>=-149){/*exp < 0 cho co phan frac bieu dien*/
      return 1 << (x+149);/*dich bit 1 vao frac bieu dien*/
    }
    /*Qua nho return 0*/
    return 0;
}
