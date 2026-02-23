#include <iostream>
#include <queue>
#include <vector>



/*




*/


void moving_average(){
    std::vector<int> data {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::queue<int> my_q;
    int w_size = 3;

    for(int i = 0; i < data.size(); i++){
        if(i < w_size - 1){
            my_q.push(data[i]);
        }else {
            int sum = 0;
            while(!my_q.empty()){
                sum += my_q.front();
                my_q.pop();
            }
            std::cout << sum / 3 << std::endl;
            for(int j = 0; j < 3; j++){
                my_q.push(data[i - j]);
            }
        }

    }

}