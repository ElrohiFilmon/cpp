#include <iostream>

using namespace std;


void game(){
    int cards[13] ={1,2,3,4,5,6,7,8,9,10,11,12,13};
                //[4] = {
                // {'A','1','2','3','4','5','6','7','8','9','8','10','J','Q','K'},
                // {'A','1','2','3','4','5','6','7','8','9','8','1o','J','Q','K'},
                // {'A','1','2','3','4','5','6','7','8','9','8','10','J','Q','K'},
                // {'A','1','2','3','4','5','6','7','8','9','8','10','J','Q','K'}
    //};

    int gamecard[6] = {};
    int sum;
    int gamecardsize = (*(&gamecard + 1) - gamecard);
    int  K = 13, Q = 12, J = 11;
    string answer;
    int ace;
    char spades = 'S',dimoand = 'D',flower = 'F', hearts = 'H'; 

    cout<<"Let's play a game of blackjack you get two card if you get a submission of 21 you win but if you pass the 21 mark you lose"<<endl;
    // int randomdraw2 = rand() % 10;
    /*while(true){*/
        /*
            do{
        */  

    for(int i =0; i<=1; ++i){
        srand(time(NULL));
        int randomdraw = rand() % 10;
        gamecard[randomdraw];
        cout<<gamecard[i]<<" "<<endl;
        
        // cout<<gamecard[randomdraw];//[randomdraw2];
    }
    /*for(int i = 0; i<=gamecardsize;++i){*/

    if((((gamecard[1]) == 1)||((gamecard[2])==1)||((gamecard[3]) == 1)||((gamecard[4]) == 1)||((gamecard[5])== 1)||((gamecard[6]) == 1))){
        cout<<"In the game blackjack the Ace can be 1 or 11, Choose one that helps you";
        cin>>ace;
    }else{
        cout<<"1.Do you want to add more cards or"<<endl<<"2.Do you want to take it as it is"<<endl;
        cin>>answer;
    }
    /*}*/
    
    
        // cin<<
        /*
            }while(gamecardsize>2);*/
    /*   }*/
    for(int i =0;i<gamecardsize;++i){
        sum += gamecard[i];

    }
    if((answer =="Yes")||(answer =="yes")||(answer =="YES")){
        srand(time(NULL));
        int randomdraw = 1+ (rand() % 12);
        cout<<gamecard[randomdraw];
    }else if((answer == "No")||(answer == "no")||answer =="NO"){
        if(sum>21){
            cout<<"You have lost!"<<sum<<endl;
        }else if(sum<=21){
            cout<<"You have won!"<<sum<<endl;
        }else{
            cout<<"Invalid result!"<<endl;
        }
    }else{
        cout<<"invalid submission!"<<endl;
    }
    
}
int main(){
    game();
}
