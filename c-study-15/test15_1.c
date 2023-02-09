//
// Created by stellar on 2023/2/9.
//

#include <stdio.h>
#include "common.h"

struct config {
    unsigned int config1: 3;
    unsigned int config2: 1;
};

void testBitOper();

void showConfigInfo(const struct config *pConfig);

int main() {
    brWithStr("testBitOper");
    testBitOper();
    return 0;
}

void testBitOper() {
    struct config conf1 = {
            5, 1
    };
    conf1.config1 = 3;
    conf1.config2 = 0;
    conf1.config2 = 5;
    //1111 1101
    //1111 1011
    //1111 0011
    //1111 1011
    showConfigInfo(&conf1);
}

void showConfigInfo(const struct config *pConfig) {
    printf("config.config1: %d, config.config2: %d\n", pConfig->config1, pConfig->config2);
}
