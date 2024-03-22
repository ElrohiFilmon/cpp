// class Solution {
// public:
//     int reverse(int x) {
//         if(x<0){    
//             x = x*-1;
//             int reversedNum = 0;

//             while(x>0){
//                 reversedNum = reversedNum *10+(x%10);    
//                 x/=10;
//             }
            
//             return reversedNum*-1;
//         }else{
//             int reversedNum = 0;

//             while(x>0){
//                 reversedNum = reversedNum *10+(x%10);    
//                 x/=10;
//             }
            
//             return reversedNum;
//         }
//     }
// };

/*So v1 didin't account the big int 1534236469 and -2147483648 which are can't be represented by int when val * 10 so they required 0 as an output 
Then I did the first thing that came into mind setting a maximum and minimum value for these big int */


//V2 had it all yeah!!!🤟🏿
class Solution {
public:
    int reverse(int x) {

        int reversedNum = 0;
        int max_int = INT_MAX/10;
        int min_int = INT_MIN/10;
        while(x!=0){
            int carry = x %10;
            if(reversedNum > max_int){
                return 0;
            }
            if(reversedNum < min_int || (reversedNum == min_int && carry < -8)){
                return 0;
            }
            reversedNum = reversedNum *10+carry;    
            x/=10;
        }
        
        return reversedNum;
    }
};

