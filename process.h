//
//  process.h
//  Lamport
//
//  Created by Michael Burdi on 10/6/20.
//  Copyright © 2020 Michael Burdi. All rights reserved.
//

#ifndef Process_h
#define Process_h

#include <string>
#include <vector>
#include <iostream>

template <int N, int M>
auto lamport_calculate(std::string (&events)[N][M]) {
    
    // Lamport clock values
    auto lc = new int[N][M]();

    int send[9];
    
    for (int r = 0; r <= sizeof(send)/sizeof(send[0]); r++) {  // Num. send events + 1 times

        for (int i = 0; i < N; i++) {   // Num. processes times
            
            for (int j = 0; j < M; j++) {   // Num. max events in process times

                auto &a = events[i][j];
                
                char type = a[0];
                int id = a[1] - '0';
                
                int k = std::max((j > 0) ? lc[i][j-1] + 1 : 1, lc[i][j]);
                lc[i][j] = (a == "" ? 0 : k);
                
                if (type == 's') {
                    send[id - 1] = k;
                }
                else if (type == 'r' && id == r) {
                    lc[i][j] = std::max(k, send[id-1] + 1);
                }
            }
        }
    }
    
    return lc;
}



template <int N, int M>
auto lamport_verify(int (&lc)[N][M]) {
    
    auto output = new std::string[N][M];
    
    std::vector<std::string*> values(24, nullptr);
    
    int max = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            max = lc[i][j] > max ? lc[i][j] : max;
            
            if (j == 0) {
                if (lc[i][j] == 1) {
                    output[i][j] = "si";
                    
                    if (values[lc[i][j]-1] == 0)
                        values[lc[i][j]-1] = &output[i][j];
                        
                } else if (lc[i][j] > 1) {
                    output[i][j] = "r";
                    
                    values[lc[i][j]-1] = &output[i][j];
                }
            } else {
                if (lc[i][j] - lc[i][j-1] == 1) {
                    output[i][j] = "si";
                    
                    if (values[lc[i][j]-1] == 0)
                        values[lc[i][j]-1] = &output[i][j];
                    
                } else if (lc[i][j] - lc[i][j-1] > 1) {
                    output[i][j] = "r";
                    
                    values[lc[i][j]-1] = &output[i][j];
                }
            }
        }
    }
    
    int count = 1;
    for (int i = 0; i < max; i++) {
        if (values[i] == nullptr) {
            throw "Incorrect";
        } else if (i > 0 && *values[i] == "r") {
            *values[i-1] = ("s" + std::to_string(count));
            *values[i] = ("r" + std::to_string(count));
            count ++;
        }
    }
    
    char symbol = 'a';
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (output[j][i] == "si") {
                output[j][i] = symbol;
                symbol += 1;
            }
        }
    }
    
    return output;
}



#endif /* Process_h */
