//
//  main.cpp
//  Lamport
//
//  Created by Michael Burdi on 10/6/20.
//  Copyright © 2020 Michael Burdi. All rights reserved.
//

#include <iostream>
#include "process.h"

int main(int argc, const char * argv[]) {
    
    std::string events[3][4] = {
        { "a", "s1", "r3", "b"},
        { "c", "r2", "s3", "" },
        { "r1", "d", "s2", "e" }
    };
    
    std::string events1[3][4] = {
        { "s1", "b", "r3", "e"},
        { "a", "r2", "s3", "" },
        { "r1", "c", "d", "s2" }
    };
    
    std::string events2[3][4] = {
        { "r1", "b", "r2", "s3"},
        { "a", "s1", "d", "" },
        { "s2", "c", "r3", "" }
    };
    
    
    int lc[3][4] = {
        {1, 2, 8, 9},
        {1, 6, 7, 0},
        {3, 4, 5, 6}
    };
    
    int lc1[3][4] = {
        {1, 2, 8, 9},
        {1, 6, 7, 0},
        {2, 4, 5, 6}
    };
    
    auto output = lamport_calculate(events);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    output = lamport_calculate(events1);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    output = lamport_calculate(events2);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    auto output2 = lamport_verify(lc);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << output2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    output2 = lamport_verify(lc1);
    
}

