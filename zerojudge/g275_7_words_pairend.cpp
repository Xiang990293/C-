#include<iostream>
using namespace std;

int main() {
    int pair_count = 0;
    while (cin >> pair_count){
        // input sentences
        for (int i = 0; i < pair_count; i++){
            int sentence[2] = {0, 0};
            bool temp = false;

            for (int j = 0, k = 0; j < 7 && k < 2; j++){
                cin >> temp;
                sentence[k] <<= 1;
                sentence[k] |= temp;
                if (j == 6) {
                    k++;
                    j = 0;
                }
            }
            cin >> temp;
            sentence[1] <<= 1;
            sentence[1] |= temp;

            string result = "";
    
            // rule A check
            bool second_word, forth_word, sixth_word;
            for (int k = 0; k < 2; k++){
                second_word = sentence[k] & 0b0100000;
                forth_word = sentence[k] & 0b0001000;
                sixth_word = sentence[k] & 0b0000010;
    
                if (!(second_word ^ forth_word) || (second_word ^ sixth_word)) {
                    result += "A";
                    break;
                }
            }
    
            // rule B check
            if (((bool) (sentence[0] & 0b0000001) ^ true) || ((bool) (sentence[1] & 0b0000001) ^ false)) {
                result += "B";
            }
    
            // rule C check
            int temp_xor = sentence[0] ^ sentence[1];
            if ((temp_xor & 0b0101010) != 0b0101010) {
                result += "C";
            }
    
            if (result == "") {
                result = "None";
            }
    
            cout << result << endl;
        }
    }
}