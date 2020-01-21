#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

/*written by Aniebiet Akpan
*Date: 20/07/16
///~*/
/*this code has many limitations
 *one of which is parity of numbers
*/

int dectobin(int i);
int bintodec(int bin);
int main(){
    int number = dectobin(100);
    printf("%i\n", number);
    printf("%i\n", bintodec(number));
}
int dectobin(int i)
{
    int inbin=0;
    int inbinArr[100];
    int bits = 1;
    int num = i;
    int temp_num = 0;
    temp_num = num;

    //get in binary
    if(num == 0)
        return 0;
    else{
        while((temp_num / 2) != 0){
            if(temp_num == num){

                inbinArr[bits] = temp_num%2;
                temp_num /= 2;
                ++bits;
            }
            else{
                inbinArr[bits] = temp_num%2;
                temp_num /= 2;
                ++bits;
            }
        }
        inbinArr[bits] = 1;
        ++bits;
        inbinArr[bits] = '\0';

        int j;
        for(j=bits-1; j>0; j--){
            if(inbinArr[j] == 0){
                inbin *= 10;
            }
            else if(inbinArr[j] == 1)
                inbin = (inbin*10 + 1);
        }
        return inbin;
    }

}
int bintodec(int bin)
{
    int num = bin;
    int bits[100];
    int tens = 1;
    int c_bits = 0;
    int rem = 0;
    int t_num = 0;

    //get number of bits
    int n_bits;
    n_bits = 1;
    int tens1 = 10;
    while((num/tens1) != 0){
        ++n_bits;
        tens1 *= 10;
    }
    //get in decimal
    if(num == 0)
        return 0;
    else{
        int i;
        for(i=0; i<n_bits; i++){
            t_num = num/tens;
            rem = t_num%2;
            if(rem == 0){
                if(c_bits == n_bits-1){
                    bits[c_bits] = 1;
                    break;
                }else {
                    bits[c_bits] = 0;
                    ++c_bits;
                    tens *= 10;
                }
            }
            else if(rem == 1){
                bits[c_bits] = 1;
                ++c_bits;
                tens *= 10;
            }
        }
        bits[n_bits] = '\0';

        int indec = 0;
        int k;
        int n=0;
        for(k=0; k<n_bits; k++){
            indec += (bits[n] * pow(2, n));
            ++n;
        }
        return indec;
    }
}
